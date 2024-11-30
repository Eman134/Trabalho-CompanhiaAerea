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

void cadastrarAviao() {
    int codigo;
    string nome;
    int qtdAssentos;

    cout << "Digite o código do avião: ";
    cin >> codigo;
    cout << "Digite o nome do avião: ";
    cin.ignore();
    getline(cin, nome);
    cout << "Digite a quantidade de assentos: ";
    cin >> qtdAssentos;

    Aviao aviao(codigo, nome, qtdAssentos);
    aviao.salvar();

    cout << "Avião cadastrado com sucesso!" << endl;
}

void carregarAvioes() {
    Aviao aviao(0, "", 0);
    aviao.carregar();
}

int main() {
    
    int opcao;
    do {
        cout << "1 - Cadastrar avião" << endl;
        cout << "2 - Visualizar aviões" << endl;
        cout << "3 - Cadastrar tripulação" << endl;
        cout << "4 - Cadastrar passageiro" << endl;
        cout << "5 - Cadastrar voo" << endl;
        cout << "6 - Cadastrar assento" << endl;
        cout << "7 - Fazer reserva" << endl;
        cout << "8 - Baixa reserva" << endl;
        cout << "9 - Pesquisa" << endl;
        cout << "10 - Fidelidade" << endl;
        cout << "11 - Sair" << endl;
        cout << "Digite a opção desejada: ";
        cin >> opcao;

        system(LIMPAR_CONSOLE);
        switch (opcao) {
            case 1: {
                Aviao aviao;
                aviao.cadastrarAviao();
                esperarRetorno();
                break;
            }
            case 2: {
                Aviao aviao;
                aviao.visualizarAvioes();
                esperarRetorno();
                break;
            }
            case 3:
                cout << "Cadastrar tripulação (em desenvolvimento)." << endl;
                esperarRetorno();
                break;
            case 4:
                cout << "Cadastrar passageiro (em desenvolvimento)." << endl;
                esperarRetorno();
                break;
            case 5:
                cout << "Cadastrar voo (em desenvolvimento)." << endl;
                esperarRetorno();
                break;
            case 6:
                cout << "Cadastrar assento (em desenvolvimento)." << endl;
                esperarRetorno();
                break;
            case 7:
                cout << "Fazer reserva (em desenvolvimento)." << endl;
                esperarRetorno();
                break;
            case 8:
                cout << "Baixa reserva (em desenvolvimento)." << endl;
                esperarRetorno();
                break;
            case 9:
                cout << "Pesquisa (em desenvolvimento)." << endl;
                esperarRetorno();
                break;
            case 10:
                cout << "Fidelidade (em desenvolvimento)." << endl;
                esperarRetorno();
                break;
            case 11:
                cout << "Encerrando o programa..." << endl;
                break;
            case 3:
                sistema.cadastrarTripulacao(); // Chama a função cadastrarTripulacao através do objeto 'sistema'
                break;
            case 4:
                sistema.listarTripulacao(); // Chama a função listarTripulacao através do objeto 'sistema'
                break;
            case 5:
                cadastrarPassageiro();
                break;
            default:
                cout << "Opção inválida!" << endl;
                esperarRetorno();
        }
    } while(opcao != 11);

    return 0;
}
