#include <iostream>
#include "modulos/Aviao.h"
#include "modulos/Passageiro.h"
#include "modulos/sistemaTripulacao.h"

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

void cadastrarPassageiro();

int main() {
        sistemaTripulacao sistema;  // Instancia o objeto do tipo sistemaTripulacao
    
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
        switch(opcao) {
            case 1:
                cadastrarAviao();
                break;
            case 2:
                carregarAvioes();
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
        }
    } while(opcao != 12);

    return 0;
}
