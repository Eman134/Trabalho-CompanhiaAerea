#include <iostream>
#include "modulos/Aviao.h"
#include "modulos/Passageiro.h"
#include "modulos/sistemaTripulacao.h"

#ifdef _WIN32
    #define LIMPAR_CONSOLE "cls"
#else
    #define LIMPAR_CONSOLE "clear"
#endif

using namespace std;

void mostrarMenu() {
    cout << "1 - Cadastrar avião" << endl;
    cout << "2 - Visualizar aviões" << endl;
    cout << "3 - Cadastrar tripulação" << endl;
    cout << "4 - Visualizar tripulações" << endl;
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
    cout << "1 - Buscar passageiro por código" << endl;
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
            cout << "Comando inválido! Digite 'R' para voltar: ";
        }
    }
}

int main() {
    sistemaTripulacao sistema;
    Aviao aviao;
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
                passageiro.cadastrarPassageiro();
                esperarRetorno();
                break;
            }
            case 6: {
                int opcaoBusca;
                do {
                    mostrarMenuBuscaPassageiro();
                    cin >> opcaoBusca;
                    system(LIMPAR_CONSOLE);
                    switch (opcaoBusca) {
                        case 1: {
                            int codigo;
                            cout << "Digite o código do passageiro: ";
                            cin >> codigo;
                            Passageiro* passageiro = Passageiro::buscarPassageiroPorCodigo(codigo);
                            if (passageiro) {
                                cout << "Passageiro encontrado: " << passageiro->getNome() << endl;
                            } else {
                                cout << "Passageiro não encontrado." << endl;
                            }
                            esperarRetorno();
                            break;
                        }
                        case 2: {
                            string nome;
                            cout << "Digite o nome do passageiro: ";
                            cin.ignore();
                            getline(cin, nome);
                            Passageiro* passageiro = Passageiro::buscarPassageiroPorNome(nome);
                            if (passageiro) {
                                cout << "Passageiro encontrado: " << passageiro->getNome() << endl;
                            } else {
                                cout << "Passageiro não encontrado." << endl;
                            }
                            esperarRetorno();
                            break;
                        }
                        case R: {
                            cout << "Voltando ao menu principal..." << endl;
                            break;
                        }
                        default: {
                            cout << "Opção inválida." << endl;
                            esperarRetorno();
                            break;
                        }
                    }
                } while (opcaoBusca != 3);
                break;
            }
            case 7: {
                cout << "Cadastrar voo (em desenvolvimento)" << endl;
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
                cout << "Encerrando o programa..." << endl;
                break;
            }
            default: {
                cout << "Opção inválida!" << endl;
                esperarRetorno();
                break;
            }
        }
    } while (opcao != 12);

    return 0;
}
