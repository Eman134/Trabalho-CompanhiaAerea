#include "TripulacaoController.h"
#include <iostream>
#include <fstream>
#include <locale.h>
#include <cctype>  // Para isdigit()
#include <algorithm>  // Para all_of()

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

using namespace std;

TripulacaoController::TripulacaoController() {
    carregarTripulacao();
    codigoCounter = tripulacoes.empty() ? 1 : tripulacoes.back().getCodigoTripulacao() + 1;
}

int TripulacaoController::getQtdPiloto() const {

    int qtdPiloto = 0;
    for (const auto& t : tripulacoes) {
        if (t.getCargoTripulacao() == "Piloto") {
            qtdPiloto++;
        }
    }

    return qtdPiloto;
}
int TripulacaoController::getQtdCopiloto() const {

    int qtdCopiloto = 0;
    for (const auto& t : tripulacoes) {
        if (t.getCargoTripulacao() == "Copiloto") {
            qtdCopiloto++;
        }
    }

    return qtdCopiloto;
}
int TripulacaoController::getQtdComissario() const {

    int qtdComissario = 0;
    for (const auto& t : tripulacoes) {
        if (t.getCargoTripulacao() == "Comissario") {
            qtdComissario++;
        }
    }

    return qtdComissario;
}

void TripulacaoController::cadastrarTripulacao() {
    string nome, cargo, telefone;
    bool disponivel = true;  // Inicializando a variável disponivel
    int cargo_teste;

    cout << "\nInforme o nome do tripulante: " << endl;
    cin.ignore();  // Limpar o buffer de entrada
    getline(cin, nome);  // Usar getline para aceitar espaços no nome

    // Garantir que o cargo não esteja vazio
    do {
        cout << "Informe o id do cargo do tripulante:" << endl;
        cout << "1 - Piloto" << endl;
        cout << "2 - Co-piloto" << endl;
        cout << "3 - Comissario" << endl;

        cin >> cargo_teste;  // Usar getline para aceitar espaços no cargo
        if(cargo_teste == 1) {
            cargo = "Piloto";
        }
        else if(cargo_teste == 2) {
            cargo = "Co-piloto";
        }
        else if(cargo_teste == 3) {
            cargo = "Comissario";
        }
    } while (cargo_teste < 1 || cargo_teste > 3);

    cout << "Informe o telefone do tripulante: " << endl;
    cin.ignore();
    getline(cin, telefone);

    Tripulacao novoTripulante(codigoCounter++, nome, cargo, telefone, disponivel);
    tripulacoes.push_back(novoTripulante);  // Adiciona a tripulação ao vetor
    cout << GREEN << "Tripulacao cadastrada com sucesso!" << RESET << endl;
}

vector<Tripulacao> TripulacaoController::getTripulacoes() const {
    return tripulacoes;
}

void TripulacaoController::listarTripulacao(){
    // Verificando se existem tripulações cadastradas
    if (tripulacoes.empty()) {
        cout << "Nenhuma tripulacao cadastrada!" << endl;
        return;
    }

    for (const auto& t : tripulacoes) {
        cout << "\nCodigo: " << t.getCodigoTripulacao() << endl;
        cout << "Nome: " << t.getNomeTripulacao() << endl;
        cout << "Cargo: " << t.getCargoTripulacao() << endl;
        cout << "Telefone: " << t.getTelefoneTripulacao() << endl;
        cout << "---------------------------\n" << endl;
    }
    cout << "Piloto: " << getQtdPiloto() << endl;
    cout << "Co-piloto: " << getQtdCopiloto() << endl;
    cout << "Comissario: " << getQtdComissario() << endl;
}

void TripulacaoController::salvarTripulacao() {
    ofstream arquivo("./db/tripulacao.bin", ios::binary);
    for (const auto& tripulante : tripulacoes) {
        int codigo = tripulante.getCodigoTripulacao();
        arquivo.write(reinterpret_cast<const char*>(&codigo), sizeof(codigo));
        size_t size = tripulante.getNomeTripulacao().size();
        arquivo.write(reinterpret_cast<const char*>(&size), sizeof(size));
        arquivo.write(tripulante.getNomeTripulacao().c_str(), size);
        size = tripulante.getCargoTripulacao().size();
        arquivo.write(reinterpret_cast<const char*>(&size), sizeof(size));
        arquivo.write(tripulante.getCargoTripulacao().c_str(), size);
        size = tripulante.getTelefoneTripulacao().size();
        arquivo.write(reinterpret_cast<const char*>(&size), sizeof(size));
        arquivo.write(tripulante.getTelefoneTripulacao().c_str(), size);
        bool disponivel = tripulante.getDisponivel();
        arquivo.write(reinterpret_cast<const char*>(&disponivel), sizeof(disponivel));
    }
}

void TripulacaoController::carregarTripulacao() {
    ifstream arquivo("./db/tripulacao.bin", ios::binary);
    if (!arquivo.is_open()) return;

    while (arquivo.peek() != EOF) {
        int codigo;
        string nome, cargo, telefone;
        bool disponivel;

        arquivo.read(reinterpret_cast<char*>(&codigo), sizeof(codigo));
        size_t size;
        arquivo.read(reinterpret_cast<char*>(&size), sizeof(size));
        nome.resize(size);
        arquivo.read(&nome[0], size);
        arquivo.read(reinterpret_cast<char*>(&size), sizeof(size));
        cargo.resize(size);
        arquivo.read(&cargo[0], size);
        arquivo.read(reinterpret_cast<char*>(&size), sizeof(size));
        telefone.resize(size);
        arquivo.read(&telefone[0], size);
        arquivo.read(reinterpret_cast<char*>(&disponivel), sizeof(disponivel));

        Tripulacao tripulante(codigo, nome, cargo, telefone, disponivel);
        tripulacoes.push_back(tripulante);
    }
}
