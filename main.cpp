#include <iostream>
#include "src/controllers/AviaoController.h"
#include "src/controllers/VooController.h"
#include "modulos/Passageiro.h"
#include "modulos/sistemaTripulacao.h"
#include <stdlib.h>
#include <locale>
#ifdef _WIN32
    #include <direct.h>
#endif

#ifdef _WIN32
    #define LIMPAR_CONSOLE "cls"
#else
    #define LIMPAR_CONSOLE "clear"
#endif

using namespace std;

void mostrarMenu() {
    cout << "====== MENU PRINCIPAL ======" << endl;
    cout << "1 - Cadastrar aviao" << endl;
    cout << "2 - Visualizar avioes" << endl;
    cout << "3 - Cadastrar tripulacao" << endl;
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
    cout << "Digite a opcao desejada: ";
}

void esperarRetorno() {
    string retorno;
    cout << "\nCaso deseje voltar ao menu inicial, digite 'R': ";
    while (true) {
        cin >> retorno;
        if (retorno == "R" || retorno == "r") {
            system(LIMPAR_CONSOLE);
            break;
        } else {
            cout << "Comando invalido! Digite 'R' para voltar: ";
        }
    }
}

void criarDiretorioLocal() {
    #ifdef _WIN32
        if (_mkdir("./db") != 0 && errno != EEXIST) {
            cerr << "Erro ao criar diretório 'db'!" << endl;
        }
    #else
        if (mkdir("./db", 0777) != 0 && errno != EEXIST) {
            cerr << "Erro ao criar diretório 'db'!" << endl;
        }
    #endif
}

int main() {

    criarDiretorioLocal();

    AviaoController aviaoController;
    VooController vooController;

    sistemaTripulacao sistema;
    Passageiro passageiro;
    Passageiro::carregarPassageiros();
    
    int opcao;
    do {
        mostrarMenu();
        cin >> opcao;
        system(LIMPAR_CONSOLE);
        switch (opcao) {
            case 1: {
                aviaoController.cadastrarAviao();
                esperarRetorno();
                break;
            }
            case 2: {
                aviaoController.visualizarAvioes();
                esperarRetorno();
                break;
            }
            case 3: {
                sistema.cadastrarTripulacao();
                esperarRetorno();
                break;
            }
            case 4: {
                sistema.listarTripulacao();
                esperarRetorno();
                break;
            }
            case 5: {
                Passageiro::cadastrarPassageiro();
                esperarRetorno();
                break;
            }
            case 6: {
                string codigo;

                cout << "Digite o codigo ou o nome do passageiro para pesquisa: " << endl;

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
                        cout << "Passageiro encontrado: " << passageiro->getNome() << endl;
                    } else {
                        cout << "Passageiro não encontrado." << endl;
                    }
                } else {
                    Passageiro* passageiro = Passageiro::buscarPassageiro(codigo);
                    if (passageiro) {
                        cout << "Passageiro encontrado: " << passageiro->getNome() << endl;
                    } else {
                        cout << "Passageiro não encontrado." << endl;
                    }
                }
 
                esperarRetorno();
                break;
            }
            case 7: {
                vooController.cadastrarVoo();
                esperarRetorno();
                break;
            }
            case 8: {
                vooController.visualizarVoos();
                esperarRetorno();
                break;
            }
            case 9: {
                cout << "Cadastrar assento (em desenvolvimento)" << endl;
                esperarRetorno();
                break;
            }
            case 10: {
                cout << "Fazer reserva (em desenvolvimento)" << endl;
                esperarRetorno();
                break;
            }
            case 11: {
                cout << "Baixa reserva (em desenvolvimento)" << endl;
                esperarRetorno();
                break;
            }
            case 12: {
                cout << "Fidelidade (em desenvolvimento)" << endl;
                esperarRetorno();
                break;
            }
            case 13: {
                cout << "Saindo..." << endl;
                break;
            }
            default: {
                cout << "Opção invalida." << endl;
                esperarRetorno();
                break;
            }
        }
    } while (opcao != 13);

    return 0;
}
