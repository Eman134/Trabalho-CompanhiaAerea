#include "AviaoController.h"
#include "../models/Aviao.h"
#include <iostream>
#include <sys/stat.h>
#include <fstream>

using namespace std;

AviaoController::AviaoController() {
    carregarAvioes();
}

void AviaoController::carregarAvioes() {
    lista_avioes.clear();

    ifstream arquivo("./db/avioes.bin", ios::binary);
    if (!arquivo) {
        cout << "Erro ao abrir o arquivo de avioes!" << endl;
        return;
    }

    while (arquivo.peek() != EOF) {
        Aviao aviao;
        aviao.carregar(arquivo);
        lista_avioes.push_back(aviao);
    }

    arquivo.close();
}

vector<Aviao> AviaoController::getListaAvioes() const {
    return lista_avioes;
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

    ofstream arquivo("./db/avioes.bin", ios::binary | ios::trunc);
    if (!arquivo) {
        return;
    }

    aviao.salvar(arquivo);

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

int AviaoController::avioesDisponiveis() const {
    int count = 0;
    for (const Aviao& aviao : lista_avioes) {
        if (aviao.getDisponivel()) {
            count++;
        }
    }
    return count;
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