#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include <algorithm>
#include <iomanip>
#include "../models/Reserva.h"
#include "../models/Voo.h"
#include "../models/Passageiro.h"
#include "./VooController.h"
#include "./ReservaController.h"
#include "./PassageiroController.h"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

using namespace std;

ReservaController::ReservaController() {
    carregarReservas();
}

// Método para cadastrar reserva
void ReservaController::cadastrarReserva(VooController* vooController, PassageiroController* passageiroController) {
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
                    return;
                }
                break;
            } else {
                cout << RED << "Voo nao encontrado. Digite um codigo valido: " << RESET << endl;
            }
        }
    }

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

    exibirTabelaAssentos(codigo_voo);

    int numeroAssento;

    cout << YELLOW << "Digite o numero do assento para fazer a reserva: " << RESET;

    while (true) {
        cin >> numeroAssento;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "Numero de assento invalido. Digite um numero valido!" << RESET;
            return;
        } else {

            if (numeroAssento < 1 || numeroAssento > voo->getAssentosTotais()) {
                cout << RED << "Assento invalido. Digite um assento valido!" << RESET << endl;
                return;
            }

            if (estaReservado(codigo_voo, numeroAssento)) {
                cout << RED << "Assento ocupado. Digite um assento valido!" << RESET << endl;
                return;
            }

            reservarAssento(codigo_voo, numeroAssento, passageiro);
            break;
        }
    }
    
    Reserva nova_reserva(getProximoCodigoReserva(), codigo_voo, codigo_passageiro, passageiro->getPontosFidelidade(), numeroAssento, passageiro->getNome(), passageiro->getEndereco(), passageiro->getTelefone(), voo->getData(), passageiro->isFidelidade(), voo->getHora(), voo->getData(), voo->getTarifa());

    lista_reservas.push_back(nova_reserva);

    voo->setAssentosDisponiveis(voo->getAssentosDisponiveis() - 1);

    salvarReservas();

    cout << GREEN << "Reserva realizada com sucesso!" << RESET << endl;

}

// Salvar reservas no arquivo
void ReservaController::salvarReservas() {
    ofstream arquivo("./db/reservas.bin", ios::binary);
    for (const auto& reserva : lista_reservas) {
        int codigo_reserva = reserva.getCodigoReserva();
        int codigo_voo = reserva.getNumeroVoo();
        int codigo_passageiro = reserva.getCodigoPassageiro();
        int pontos_fidelidade = reserva.getPontosFidelidade();
        int assento = reserva.getAssento();
        string nome = reserva.getNomePassageiro();
        string endereco = reserva.getEndereco();
        string telefone = reserva.getTelefone();
        string dataVoo = reserva.getdataVoo();
        bool fidelidade = reserva.isFidelidade();
        int hora = reserva.getHora();
        string dataReserva = reserva.getdataReserva();
        float tarifa = reserva.getTarifa();

        arquivo.write((char*)&codigo_reserva, sizeof(codigo_reserva));
        arquivo.write((char*)&codigo_voo, sizeof(codigo_voo));
        arquivo.write((char*)&codigo_passageiro, sizeof(codigo_passageiro));
        arquivo.write((char*)&pontos_fidelidade, sizeof(pontos_fidelidade));
        arquivo.write((char*)&assento, sizeof(assento));
        size_t size = nome.size();
        arquivo.write((char*)&size, sizeof(size));
        arquivo.write(nome.c_str(), size);
        size = endereco.size();
        arquivo.write((char*)&size, sizeof(size));
        arquivo.write(endereco.c_str(), size);
        size = telefone.size();
        arquivo.write((char*)&size, sizeof(size));
        arquivo.write(telefone.c_str(), size);
        size = dataVoo.size();
        arquivo.write((char*)&size, sizeof(size));
        arquivo.write(dataVoo.c_str(), size);
        arquivo.write((char*)&fidelidade, sizeof(fidelidade));
        arquivo.write((char*)&hora, sizeof(hora));
        size = dataReserva.size();
        arquivo.write((char*)&size, sizeof(size));
        arquivo.write(dataReserva.c_str(), size);
        arquivo.write((char*)&tarifa, sizeof(tarifa));
    }
    arquivo.close();
}

// Carregar reservas do arquivo
void ReservaController::carregarReservas() {
    ifstream arquivo("./db/reservas.bin", ios::binary);
    if (!arquivo.is_open()) return;

    lista_reservas.clear();

    int codigo_reserva;
    int codigo_voo;
    int codigo_passageiro;
    int pontos_fidelidade;
    int assento;
    string nome;
    string endereco;
    string telefone;
    string dataVoo;
    bool fidelidade;
    int hora;
    string dataReserva;
    float tarifa;

    while (arquivo.read((char*)&codigo_reserva, sizeof(codigo_reserva))) {
        arquivo.read((char*)&codigo_voo, sizeof(codigo_voo));
        arquivo.read((char*)&codigo_passageiro, sizeof(codigo_passageiro));
        arquivo.read((char*)&pontos_fidelidade, sizeof(pontos_fidelidade));
        arquivo.read((char*)&assento, sizeof(assento));

        size_t size;
        arquivo.read((char*)&size, sizeof(size));
        nome.resize(size);
        arquivo.read(&nome[0], size);

        arquivo.read((char*)&size, sizeof(size));
        endereco.resize(size);
        arquivo.read(&endereco[0], size);

        arquivo.read((char*)&size, sizeof(size));
        telefone.resize(size);
        arquivo.read(&telefone[0], size);

        arquivo.read((char*)&size, sizeof(size));
        dataVoo.resize(size);
        arquivo.read(&dataVoo[0], size);

        arquivo.read((char*)&fidelidade, sizeof(fidelidade));
        arquivo.read((char*)&hora, sizeof(hora));

        arquivo.read((char*)&size, sizeof(size));
        dataReserva.resize(size);
        arquivo.read(&dataReserva[0], size);

        arquivo.read((char*)&tarifa, sizeof(tarifa));

        Reserva reserva(codigo_reserva, codigo_voo, codigo_passageiro, pontos_fidelidade, assento, nome, endereco, telefone, dataVoo, fidelidade, hora, dataReserva, tarifa);
        lista_reservas.push_back(reserva);
    }
    arquivo.close();
}

// Exibe uma tabela interativa com os assentos disponíveis e ocupados
void ReservaController::exibirTabelaAssentos(int codigo_voo) {
    cout << "Tabela de assentos (verde = disponivel, vermelho = ocupado):\n";

    int linhas = 5;
    int colunas = 10;

    cout << "   ";
    for (int j = 0; j < colunas; ++j) {
        cout << setw(4) << j + 1;
    }
    cout << endl;


    vector<Assento> assentos;

    for (const auto& reserva : lista_reservas) {
        if (reserva.getNumeroVoo() == codigo_voo) {
            assentos.push_back(Assento(reserva.getAssento()));
        }
    }

    printf(assentos.size() > 0 ? "Assentos ocupados: %d\n" : "Nenhum assento ocupado.\n", assentos.size());

    for (int i = 0; i < linhas; ++i) {
        cout << setw(2) << char('A' + i) << " ";
        for (int j = 0; j < colunas; ++j) {
            int numeroAssento = i * colunas + j + 1;
            auto it = find_if(assentos.begin(), assentos.end(),
                              [numeroAssento](const Assento& assento) { return assento.getNumero() == numeroAssento; });
            if (it != assentos.end() && it->Ocupado()) {
                cout << RED << setw(4) << numeroAssento << RESET;
            } else {
                cout << GREEN << setw(4) << numeroAssento << RESET;
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Função que vai cadastrar uma reserva
void ReservaController::reservarAssento(int codigo_voo, int assento, Passageiro* passageiro) {
    int codigo_reserva = lista_reservas.size() + 1;
    int pontos_fidelidade = passageiro->getPontosFidelidade();
    string nome = passageiro->getNome();
    string endereco = passageiro->getEndereco();
    string telefone = passageiro->getTelefone();
    bool fidelidade = passageiro->isFidelidade();
    string dataVoo = "";
    int hora = 0;
    string dataReserva = "";
    float tarifa = 0;

    Reserva reserva(codigo_reserva, codigo_voo, passageiro->getCodigoPassageiro(), pontos_fidelidade, assento, nome, endereco, telefone, dataVoo, fidelidade, hora, dataReserva, tarifa);
    lista_reservas.push_back(reserva);
    salvarReservas();
}

// Função para excluir reservas de um voo
void ReservaController::excluirReservasVoo(int codigo_voo) {
    for (auto it = lista_reservas.begin(); it != lista_reservas.end();) {
        if (it->getNumeroVoo() == codigo_voo) {
            it = lista_reservas.erase(it);
        } else {
            ++it;
        }
    }
    salvarReservas();
}

int ReservaController::getProximoCodigoReserva() const {

    if (lista_reservas.empty()) {
        return 1;
    }

    return lista_reservas.back().getCodigoReserva() + 1;

}

bool ReservaController::estaReservado(int codigo_voo, int assento) {
    for (const auto& reserva : lista_reservas) {
        if (reserva.getNumeroVoo() == codigo_voo && reserva.getAssento() == assento) {
            return true;
        }
    }
    return false;
}