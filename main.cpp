#include <iostream>

using namespace std;

int main() {
    
    int opcao;
    do {
        cout << "1 - Cadastrar avião" << endl;
        cout << "2 - Cadastrar tripulação" << endl;
        cout << "3 - Cadastrar passageiro" << endl;
        cout << "4 - Cadastrar voo" << endl;
        cout << "5 - Cadastrar assento" << endl;
        cout << "6 - Fazer reserva" << endl;
        cout << "7 - Baixa reserva" << endl;
        cout << "8 - Pesquisa" << endl;
        cout << "9 - Fidelidade" << endl;
        cout << "10 - Sair" << endl;
        cout << "Digite a opção desejada: ";
        cin >> opcao;
        switch(opcao) {
            case 1:
                cout << "Cadastrar avião" << endl;
                break;
            case 2:
                cout << "Cadastrar tripulação" << endl;
                break;
            case 3:
                cout << "Cadastrar passageiro" << endl;
                break;
            case 4:
                cout << "Cadastrar voo" << endl;
                break;
            case 5:
                cout << "Cadastrar assento" << endl;
                break;
            case 6:
                cout << "Fazer reserva" << endl;
                break;
            case 7:
                cout << "Baixa reserva" << endl;
                break;
            case 8:
                cout << "Pesquisa" << endl;
                break;
            case 9:
                cout << "Fidelidade" << endl;
                break;
            case 10:
                cout << "Sair" << endl;
                break;
            default:
                cout << "Opção inválida" << endl;
        }
    } while(opcao != 10);

    return 0;
}