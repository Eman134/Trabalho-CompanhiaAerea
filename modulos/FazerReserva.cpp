#include "FazerReserva.h"
#include <iostream>
#include <vector>
#include "Passageiro.h"
#include "Voo.h"

using namespace std;

Reserva::Reserva() {}

Reserva::Reserva() {
    this->codigoReserva = codigoReserva;
    this->numerodovoo = numerodovoo;
    this->codigoPassageiro = codigoPassageiro;
    this->pontos_fidelidade = pontos_fidelidade;
    this->nomePassageiro = nomePassageiro;
    this->endereco = endereco;
    this->telefone = telefone;
    this->fidelidade = fidelidade;
    this->dataVoo = dataVoo;
    this->hora = hora;
    this->dataReserva = dataReserva;
    this->assento = assento;
    this->tarifa = tarifa;
}

// Métodos para obter os dados
int Reserva::getCodigoPassageiro() {
    return codigoPassageiro;
}

int Reserva::getcodigoReserva() {
    return codigoReserva;
}

int Reserva::getNumeroVoo() {
    return numerodovoo;
}

string Reserva::getNomePassageiro() {
    return nomePassageiro;
}

void Reserva::exibirDataCadastro() {
    cout << "Data de Cadastro: " << dataReserva << endl;
}

// Método para cadastrar reserva
void Reserva::cadastrarReserva(vector<Reserva>& reservas, vector<Passageiro>& passageiros, vector<Voo>& voos) {
    int numerodovoo;
    string data;
    int codigoPassageiroInput;
    bool vooExistente = false;
    bool vooValido = false;

    cout << "Digite a data do voo: ";
    cin >> data;

    // Verificar se existe um voo com a data fornecida
    for (const auto& voo : voos) {
        if (voo.getData() == data) {
            vooExistente = true;
            vooValido = true;
            cout << "Código do voo: " << voo.getCodigoVoo()
                 << " - Horário do voo: " << voo.getHora() << endl;
            break;
        }
    }

    if (!vooExistente) {
        cout << "Não existe voo com essa data!" << endl;
        return;
    }

    cout << "Digite o código do passageiro: ";
    cin >> codigoPassageiroInput;

    // Verifica se o passageiro existe
   bool passageiroExistente = false;
    for (const auto& passageiro : passageiros) {
    if (codigoPassageiroInput == Passageiro.getCodigoPassageiro) {  // A correção está aqui
        passageiroExistente = true;
        this->codigoPassageiro = passageiro.getCodigoPassageiro();
        this->nomePassageiro = passageiro.getNome();
        this->telefone = passageiro.getTelefone();
        this->endereco = passageiro.getEndereco();
        this->fidelidade = passageiro.isFidelidade();
        this->pontos_fidelidade = passageiro.getPontosFidelidade();

        cout << "Passageiro encontrado - Código: " << passageiro.getCodigoPassageiro()
             << ", Nome: " << passageiro.getNome()
             << ", Endereço: " << passageiro.getEndereco()
             << ", Telefone: " << passageiro.getTelefone()
             << ", Pontos de fidelidade: " << passageiro.getPontosFidelidade() << endl;
        break;
    }
}


    if (!passageiroExistente) {
        cout << "Não existe passageiro com esse código!" << endl;
        return;
    }

    // Inicializar outros atributos necessários aqui
    this->codigoReserva = reservas.size() + 1;

    // Adiciona a reserva ao vetor de reservas
    reservas.push_back(*this);
    cout << "Reserva realizada com sucesso!" << endl;
}

void Reserva::exibirDetalhesReserva() {
    cout << "Código da Reserva: " << codigoReserva << endl;
    cout << "Número do Voo: " << numerodovoo << endl;
    cout << "Código do Passageiro: " << codigoPassageiro << endl;
    cout << "Pontos de Fidelidade: " << pontos_fidelidade << endl;
    cout << "Nome do Passageiro: " << nomePassageiro << endl;
    cout << "Endereço: " << endereco << endl;
    cout << "Telefone: " << telefone << endl;
    cout << "Fidelidade: " << (fidelidade ? "Sim" : "Não") << endl;
    exibirDataCadastro();
}
