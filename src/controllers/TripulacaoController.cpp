#include "TripulacaoController.h"
#include <iostream>
#include <locale.h>
#include <cctype>  // Para isdigit()
#include <algorithm>  // Para all_of()
using namespace std;

TripulacaoController::TripulacaoController() : codigoCounter(1), qtdPiloto(0), qtdCopiloto(0), qtdComissario(0) {}

void TripulacaoController::cadastrarTripulacao() {
    string nome, cargo, telefone;
    bool disponivel = true;  // Inicializando a variável disponivel
    int cargo_teste;

    cout << "\nInforme o nome do tripulante: " << endl;
    cin.ignore();  // Limpar o buffer de entrada
    getline(cin, nome);  // Usar getline para aceitar espaços no nome

    // Garantir que o cargo não esteja vazio
    do {
        cout << "Informe o cargo do tripulante (1 para piloto - 2 para co-piloto - 3 para comissário): " << endl;
        cin >> cargo_teste;  // Usar getline para aceitar espaços no cargo
        if(cargo_teste == 1) {
            cargo = "Piloto";
            qtdPiloto++;
        }
        else if(cargo_teste == 2) {
            cargo = "Co-piloto";
            qtdCopiloto++;
        }
        else if(cargo_teste == 3) {
            cargo = "Comissário";
            qtdComissario++;
        }
    } while(cargo_teste < 1 || cargo_teste > 3);

    cout << "O cargo escolhido foi: " << cargo << endl;

    cout << "Informe o telefone do tripulante (somente números):" << endl;
    cin >> telefone;

    // Verificando se o telefone tem exatamente 11 dígitos e se contém apenas números
    while (telefone.length() != 11 || !all_of(telefone.begin(), telefone.end(), ::isdigit)) {
        cout << "Informe um telefone válido com 11 dígitos (somente números): " << endl;
        cin >> telefone;
    }

    // Gerar o código automaticamente
    Tripulacao novoTripulante(codigoCounter++, nome, cargo, telefone, disponivel);  // Usando o contador para gerar código
    tripulacoes.push_back(novoTripulante);  // Adiciona a tripulação ao vetor
    cout << "Tripulação cadastrada com sucesso!" << endl;
}

vector<Tripulacao> TripulacaoController::getTripulacoes() const {
    return tripulacoes;
}

void TripulacaoController::listarTripulacao(){
    // Verificando se existem tripulações cadastradas
    if (tripulacoes.empty()) {
        cout << "Nenhuma tripulação cadastrada!" << endl;
        return;
    }

    for (const auto& t : tripulacoes) {
        cout << "\nCodigo: " << t.getCodigoTripulacao() << endl;
        cout << "Nome: " << t.getNomeTripulacao() << endl;
        cout << "Cargo: " << t.getCargoTripulacao() << endl;
        cout << "Telefone: " << t.getTelefoneTripulacao() << endl;
        cout << "---------------------------\n" << endl;
    }
    cout << "Piloto: " << qtdPiloto << endl;
    cout << "Co-piloto: " << qtdCopiloto << endl;
    cout << "Comissário: " << qtdComissario<< endl;
}
