#include "AviaoController.h"
#include <iostream>
#include <sys/stat.h>

using namespace std;

AviaoController::AviaoController() {
    carregarAvioes();
}

void AviaoController::carregarAvioes() {
    lista_avioes.clear();

    ifstream arquivo("./db/avioes.bin", ios::binary);
    if (!arquivo) {
        return;
    }

    while (arquivo.peek() != EOF) {
        Aviao aviao;
        aviao.carregar();
        lista_avioes.push_back(aviao);
    }

    arquivo.close();
}

void AviaoController::cadastrarAviao() {
    
    Aviao aviao;
    int codigo = getProximoCodigo();
    aviao.setCodigoAviao(codigo);
    
    string nome;
    int qtdAssentos;

    cout << "Digite o nome do aviao: ";
    cin.ignore();
    getline(cin, nome);
    aviao.setNomeAviao(nome);
    cout << "Digite a quantidade de assentos: ";
    cin >> qtdAssentos;
    aviao.setQtdAssentos(qtdAssentos);


    aviao.salvar();
    lista_avioes.push_back(aviao);

    cout << "Aviao cadastrado com sucesso!" << endl;
}

Aviao* AviaoController::buscarAviao(int codigo_aviao) {
    for (Aviao& aviao : lista_avioes) {
        if (aviao.getCodigoAviao() == codigo_aviao) {
            return &aviao;
        }
    }
    return nullptr;
}

void AviaoController::visualizarAvioes() const {

    if (lista_avioes.empty()) {
        cout << "Nenhum aviao cadastrado no sistema." << endl;
        return;
    }

    cout << "Avioes cadastrados no sistema:" << endl;
    for (const Aviao& aviao : lista_avioes) {
        cout << "Codigo do aviao: " << aviao.getCodigoAviao() << endl;
        cout << "Nome do aviao: " << aviao.getNomeAviao() << endl;
        cout << "Quantidade de assentos: " << aviao.getQtdAssentos() << endl;
        cout << "----------------------------" << endl;
    }
}

int AviaoController::avioesCadastrados() const {
    return lista_avioes.size();
}

int AviaoController::getProximoCodigo() const {
    if (lista_avioes.empty()) {
        return 1;
    }
    return lista_avioes.back().getCodigoAviao() + 1;
}