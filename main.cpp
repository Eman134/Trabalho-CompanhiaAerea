#include <iostream>
#include "modulos/Aviao.h"
#include "modulos/Voo.h"
#include "modulos/Passageiro.h"
#include "modulos/sistemaTripulacao.h"
#include <stdlib.h>

#ifdef _WIN32
    #define LIMPAR_CONSOLE "cls"
#else
    #define LIMPAR_CONSOLE "clear"
#endif

using namespace std;

void mostrarMenu() {
    cout << "1 - Cadastrar aviao" << endl;
    cout << "2 - Visualizar avioes" << endl;
    cout << "3 - Cadastrar tripulacao" << endl;
    cout << "4 - Visualizar tripulacoes" << endl;
    cout << "5 - Cadastrar passageiro" << endl;
    cout << "6 - Pesquisa de passageiro" << endl;
    cout << "7 - Cadastrar voo" << endl;
    cout << "8 - Cadastrar assento" << endl;
    cout << "9 - Fazer reserva" << endl;
    cout << "10 - Baixa reserva" << endl;
    cout << "11 - Fidelidade" << endl;
    cout << "12 - Sair" << endl;
    cout << "Digite a opção desejada: ";
}

void mostrarMenuBuscaPassageiro() {
    cout << "1 - Buscar passageiro por codigo" << endl;
    cout << "2 - Buscar passageiro por nome" << endl;
    cout << "R - Voltar ao menu principal" << endl;
    cout << "Digite a opção desejada: ";
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

int main() {
    sistemaTripulacao sistema;
    Aviao aviao;
    Voo voo;
    Passageiro passageiro;
    Passageiro::carregarPassageiros();
    
    int opcao;
    do {
        mostrarMenu();
        cin >> opcao;
        system(LIMPAR_CONSOLE);
        switch (opcao) {
            case 1: {
                aviao.cadastrarAviao();
                esperarRetorno();
                break;
            }
            case 2: {
                aviao.visualizarAvioes();
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
                voo.cadastrarVoo();
                esperarRetorno();
                break;
            }
            case 8: {
                cout << "Cadastrar assento (em desenvolvimento)" << endl;
                esperarRetorno();
                break;
            }
            case 9: {
                cout << "Fazer reserva (em desenvolvimento)" << endl;
                esperarRetorno();
                break;
            }
            case 10: {
                cout << "Baixa reserva (em desenvolvimento)" << endl;
                esperarRetorno();
                break;
            }
            case 11: {
                cout << "Fidelidade (em desenvolvimento)" << endl;
                esperarRetorno();
                break;
            }
            case 12: {
                cout << "Saindo..." << endl;
                break;
            }
            default: {
                cout << "Opção invalida." << endl;
                esperarRetorno();
                break;
            }
        }
    } while (opcao != 12);

    return 0;
}
