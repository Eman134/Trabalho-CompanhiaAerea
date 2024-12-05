#include <iostream>
#include "src/controllers/AviaoController.h"
#include "src/controllers/VooController.h"
#include "src/controllers/TripulacaoController.h"
#include "modulos/Passageiro.h"
#include "modulos/FazerReserva.h"
#include <stdlib.h>
#include <locale>
#include <limits>
#ifdef _WIN32
    #include <direct.h>
#endif

#ifdef _WIN32
    #define LIMPAR_CONSOLE "cls"
#else
    #define LIMPAR_CONSOLE "clear"
#endif

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

using namespace std;

void mostrarMenu() {
    cout << "====== MENU PRINCIPAL ======" << endl;
    cout << "1 - Cadastrar aviao" << endl;
    cout << "2 - Visualizar avioes" << endl;
    cout << "3 - Cadastrar Tripulacao" << endl;
    cout << "4 - Visualizar tripulacoes" << endl;
    cout << "5 - Cadastrar passageiro" << endl;
    cout << "6 - Pesquisa de passageiro" << endl;
    cout << "7 - Cadastrar voo" << endl;
    cout << "8 - Visualizar voos" << endl;
    cout << "9 - Cadastrar assento" << endl;
    cout << "10 - Fazer reserva" << endl;
    cout << "11 - Baixa reserva" << endl;
    cout << "12 - Fidelidade" << endl;
    cout << "13 - Sair" << endl;
    cout << "============================" << endl;
    cout << YELLOW << "Digite a opcao desejada: " << RESET;
}

void esperarRetorno() {
    string retorno;
    cout << "\n" << GREEN << "Caso deseje voltar ao menu inicial, digite 'R': " << RESET;
    while (true) {
        cin >> retorno;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (retorno == "R" || retorno == "r") {
            system(LIMPAR_CONSOLE);
            break;
        }
    }
}

void criarDiretorioLocal() {
    #ifdef _WIN32
        if (_mkdir("./db") != 0 && errno != EEXIST) {
            cerr << RED << "Erro ao criar diretório 'db'!" << RESET << endl;
        }
    #else
        if (mkdir("./db", 0777) != 0 && errno != EEXIST) {
            cerr << RED << "Erro ao criar diretório 'db'!" << RESET << endl;
        }
    #endif
}

int main() {
    criarDiretorioLocal();

    AviaoController aviaoController;
    VooController vooController;
    TripulacaoController tripulacaoController;
    Reserva reserva;
    Passageiro passageiro;

    int opcao;
    do {
        mostrarMenu();
        cin >> opcao;
        system(LIMPAR_CONSOLE);
        switch (opcao) {
            case 1: {
                cout << GREEN << "Cadastrar aviao iniciado..." << RESET << endl;
                aviaoController.cadastrarAviao();
                aviaoController.salvarAvioes();
                esperarRetorno();
                break;
            }
            case 2: {
                cout << GREEN << "Visualizando avioes..." << RESET << endl;
                aviaoController.visualizarAvioes();
                esperarRetorno();
                break;
            }
            case 3: {
                cout << GREEN << "Cadastro de tripulacao iniciado..." << RESET << endl;
                tripulacaoController.cadastrarTripulacao();
                tripulacaoController.salvarTripulacao();
                esperarRetorno();
                break;
            }
            case 4: {
                cout << GREEN << "Listando tripulacoes..." << RESET << endl;
                tripulacaoController.listarTripulacao();
                esperarRetorno();
                break;
            }
            case 5: {
                cout << GREEN << "Cadastro de passageiro iniciado..." << RESET << endl;
                Passageiro::cadastrarPassageiro();
                Passageiro::salvarPassageiros();
                esperarRetorno();
                break;
            }
            case 6: {
                cout << YELLOW << "Digite o codigo ou o nome do passageiro para pesquisa: " << RESET << endl;
                string codigo;
                cin >> codigo;

                bool isNumero = true;
                for (char c : codigo) {
                    if (!isdigit(c)) {
                        isNumero = false;
                        break;
                    }
                }

                if (isNumero) {
                    int numero = stoi(codigo);
                    Passageiro* passageiro = Passageiro::buscarPassageiro(numero);
                    if (passageiro) {
                        cout << GREEN << "Passageiro encontrado: " << RESET << passageiro->getNome() << endl;
                        cout << "Nome: " << passageiro->getNome() << endl;
                        cout << "Codigo: " << passageiro->getCodigoPassageiro() << endl;
                        cout << "Telefone: " << passageiro->getTelefone() << endl;
                    } else {
                        cout << RED << "Passageiro não encontrado." << RESET << endl;
                    }
                } else {
                    Passageiro* passageiro = Passageiro::buscarPassageiro(codigo);
                    if (passageiro) {
                        cout << GREEN << "Passageiro encontrado: " << RESET << passageiro->getNome() << endl;
                        cout << "Nome: " << passageiro->getNome() << endl;
                        cout << "Codigo: " << passageiro->getCodigoPassageiro() << endl;
                        cout << "Telefone: " << passageiro->getTelefone() << endl;
                    } else {
                        cout << RED << "Passageiro não encontrado." << RESET << endl;
                    }
                }

                esperarRetorno();
                break;
            }
            case 7: {
                cout << GREEN << "Cadastrar voo iniciado..." << RESET << endl;
                vooController.cadastrarVoo(&aviaoController, &tripulacaoController);
                vooController.salvarVoos();
                esperarRetorno();
                break;
            }
            case 8: {
                cout << GREEN << "Visualizando voos..." << RESET << endl;
                vooController.visualizarVoos();
                esperarRetorno();
                break;
            }
            case 9: {
               if (vooController.getNumeroVoos() == 0) {
                    cout << "Nenhum voo cadastrado!" << endl;
                } else {
                    int codigoVoo;
                    cout << "Digite o codigo do voo: ";
                    cin >> codigoVoo;
                    Voo* voo = vooController.buscarVoo(codigoVoo);
                    if (voo) {
                        int numeroAssento;
                        cout << "Digite o numero do assento a ser cadastrado: ";
                        cin >> numeroAssento;
                        voo->cadastrarAssento(numeroAssento);
                        vooController.salvarVoos();
                    } else {
                        cout << "Voo nao encontrado!" << endl;
                    }
                }
                esperarRetorno();
                break;
            }
            case 10: {
                cout << GREEN << "Fazer reserva iniciado..." << RESET << endl;
                reserva.cadastrarReserva(&vooController, &passageiro);
                esperarRetorno();
                break;
            }
            case 11: {
                cout << GREEN << "Baixa de reserva iniciado..." << RESET << endl;
                if (vooController.getNumeroVoos() == 0) {
                    cout << "Nenhum voo cadastrado!" << endl;
                } else {
                    vooController.visualizarVoos();
                    int codigoVoo;
                    cout << "Digite o codigo do voo: ";
                    cin >> codigoVoo;
                    Voo* voo = vooController.buscarVoo(codigoVoo);
                    if (voo) {
                        if (voo->getStatus() == "Realizado") {
                            cout << "Voo ja realizado!" << endl;
                        } else {
                            vooController.darBaixaVoo(codigoVoo);
                        }
                    } else {
                        cout << "Voo nao encontrado!" << endl;
                    }
                }
                esperarRetorno();
                break;
            }
            case 12: {
                cout << GREEN << "Fidelidade iniciado..." << RESET << endl;
                for (const auto& passageiro : passageiro.getListaPassageiros()) {
                    cout << "Passageiro: " << passageiro.getNome() << " - Pontos de fidelidade: " << passageiro.getPontosFidelidade() << endl;
                }
                esperarRetorno();
                break;
            }
            case 13: {
                cout << RED << "Saindo..." << RESET << endl;
                break;
            }
            default: {
                cout << RED << "Opcao invalida." << RESET << endl;
                esperarRetorno();
                break;
            }
        }
    } while (opcao != 13);

    return 0;
}
