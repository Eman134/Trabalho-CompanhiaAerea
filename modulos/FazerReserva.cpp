#include "FazerReserva.h"
#include <iostream>
#include <vector>
#include "Passageiro.h"
#include "../src/models/Voo.h"
#include "../src/controllers/VooController.h"
#include <fstream>
#include <limits>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

using namespace std;

Reserva::Reserva() {
    this->codigoReserva = codigoReserva;
    this->codigo_voo = codigo_voo;
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

int Reserva::getCodigoReserva() {
    return codigoReserva;
}

int Reserva::getNumeroVoo() {
    return codigo_voo;
}

string Reserva::getNomePassageiro() {
    return nomePassageiro;
}

// Método para cadastrar reserva
void Reserva::cadastrarReserva(VooController* vooController, Passageiro* passageiroController) {
    int codigo_voo;
    int codigo_passageiro;
    Voo* voo;
    Passageiro* passageiro;
    string data;

    if (vooController->getNumeroVoos() == 0) {
        cout << RED << "Nenhum voo cadastrado para fazer a reserva!" << RESET << endl;
        return;
    }

    if (passageiroController->getListaPassageiros().empty()) {
        cout << RED << "Nenhum passageiro cadastrado para fazer a reserva!" << RESET << endl;
        return;
    }

    cout << "Lista de voos disponiveis para fazer a reserva: " << endl;
    vooController->visualizarVoos();

    cout << YELLOW << "Digite o codigo do voo para fazer a reserva: " << RESET;

    while (true) {
        cin >> codigo_voo;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "Codigo invalido. Digite um numero valido: " << RESET;
        } else {
            voo = vooController->buscarVoo(codigo_voo);
            if (voo) {
                if (voo->getAssentosDisponiveis() == 0) {
                    cout << RED << "Voo lotado. Escolha outro voo: " << RESET << endl;
                    continue;
                }

                break;
            }
            cout << RED << "Voo nao encontrado. Digite um codigo valido: " << RESET << endl;
        }
    }

    this->codigo_voo = voo->getCodigoVoo();

    cout << "Lista de passageiros disponiveis para fazer a reserva: " << endl;
    for (const auto& passageiro_temp : passageiroController->getListaPassageiros()) {
        cout << "Codigo: " << passageiro_temp.getCodigoPassageiro() << " - Nome: " << passageiro_temp.getNome() << endl;
    }

    cout << YELLOW << "Digite o codigo do passageiro para fazer a reserva: " << RESET;

    while (true) {
        cin >> codigo_passageiro;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "Codigo invalido. Digite um número válido: " << RESET;
        } else {
            passageiro = passageiroController->buscarPassageiro(codigo_passageiro);
            if (passageiro) {
                break;
            }
            cout << RED << "Passageiro nao encontrado. Digite um codigo válido: " << RESET << endl;
        }
    }

    voo->exibirTabelaAssentos(5, 10);

    int numeroAssento;

    cout << YELLOW << "Digite o numero do assento para fazer a reserva: " << RESET;

    while (true) {
        cin >> numeroAssento;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "Numero de assento invalido. Digite um numero valido: " << RESET;
        } else {

            if (numeroAssento < 1 || numeroAssento > voo->getAssentosTotais()) {
                cout << RED << "Assento invalido. Digite um assento valido: " << RESET << endl;
                continue;
            }

            if (voo->reservarAssento(numeroAssento, passageiro)) {
                break;
            }
            cout << RED << "Assento ocupado ou invalido. Digite um numero valido: " << RESET << endl;
        }
    }

    this->codigoPassageiro = passageiro->getCodigoPassageiro();

    cout << "Reserva realizada com sucesso!" << endl;
    vooController->salvarVoos();
}

void Reserva::exibirDetalhesReserva() {
    cout << "Codigo da Reserva: " << codigoReserva << endl;
    cout << "Número do Voo: " << codigo_voo << endl;
    cout << "Codigo do Passageiro: " << codigoPassageiro << endl;
    cout << "Pontos de Fidelidade: " << pontos_fidelidade << endl;
    cout << "Nome do Passageiro: " << nomePassageiro << endl;
    cout << "Endereço: " << endereco << endl;
    cout << "Telefone: " << telefone << endl;
    cout << "Fidelidade: " << (fidelidade ? "Sim" : "Não") << endl;
    cout << "Data de Cadastro: " << dataReserva << endl;
}
