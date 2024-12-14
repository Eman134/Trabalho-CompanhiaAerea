#include "AviaoController.h"
#include "../models/Aviao.h"
#include <iostream>
#include <sys/stat.h>
#include <fstream>

using namespace std;

// Construtor da classe AviaoController
AviaoController::AviaoController() {
    carregarAvioes();
}

// Método para carregar os aviões do arquivo binário
void AviaoController::carregarAvioes() {
    lista_avioes.clear();

    ifstream arquivo("./db/avioes.bin", ios::binary);
    if (!arquivo) {
        return;
    }

    while (arquivo.peek() != EOF) {
        Aviao aviao;
        aviao.carregar(arquivo);
        lista_avioes.push_back(aviao);
    }

    arquivo.close();
}

// Método para pegar a lista de aviões
vector<Aviao> AviaoController::getListaAvioes() const {
    return lista_avioes;
}

// Método para salvar os aviões no arquivo binário
void AviaoController::salvarAvioes() {

    std::ofstream arquivo("./db/avioes.bin", std::ios::binary | std::ios::trunc);
    if (!arquivo) {
        return;
    }

    for (const Aviao& aviao : lista_avioes) {
        aviao.salvar(arquivo);
    }

    arquivo.close();
}

// Método para cadastrar um avião novo
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
    //cout << "Digite a quantidade de assentos: ";
    //cin >> qtdAssentos;
    //aviao.setQtdAssentos(qtdAssentos);
    // Modificado para 50 assentos como padrão
    aviao.setQtdAssentos(50);

    lista_avioes.push_back(aviao);

    salvarAvioes();

    cout << "Aviao cadastrado com sucesso!" << endl;
}

// Método para buscar um avião no vetor de aviões pelo código
Aviao* AviaoController::buscarAviao(int codigo_aviao) {
    for (Aviao& aviao : lista_avioes) {
        if (aviao.getCodigoAviao() == codigo_aviao) {
            return &aviao;
        }
    }
    return nullptr;
}

// Procedimento para visualizar os aviões cadastrados
void AviaoController::visualizarAvioes() const {

    if (lista_avioes.empty()) {
        cout << "Nenhum aviao cadastrado no sistema." << endl;
        return;
    }

    for (const Aviao& aviao : lista_avioes) {
        cout << "Codigo do aviao: " << aviao.getCodigoAviao() << endl;
        cout << "Nome do aviao: " << aviao.getNomeAviao() << endl;
        cout << "Quantidade de assentos: " << aviao.getQtdAssentos() << endl;
        cout << "Disponivel para voo: " << (aviao.getDisponivel() ? "\033[32mSim\033[0m" : "\033[31mNao\033[0m") << endl;
        cout << "----------------------------" << endl;
    }
}

// Método para alterar a disponibilidade de um avião
void AviaoController::setDisponibilidade(int codigo_aviao, bool disponibilidade) {
    for (Aviao& aviao : lista_avioes) {
        if (aviao.getCodigoAviao() == codigo_aviao) {
            aviao.setDisponibilidade(disponibilidade);
            break;
        }
    }
    salvarAvioes();
}

// Método para ver a quantidade de aviões disponíveis
int AviaoController::avioesDisponiveis() const {
    int count = 0;
    for (const Aviao& aviao : lista_avioes) {
        if (aviao.getDisponivel()) {
            count++;
        }
    }
    return count;
}

// Método para ver a quantidade de aviões cadastrados
int AviaoController::avioesCadastrados() const {
    return lista_avioes.size();
}

// Método para pegar o próximo código de avião, para não repetir códigos
int AviaoController::getProximoCodigo() const {
    if (lista_avioes.empty()) {
        return 1;
    }
    return lista_avioes.back().getCodigoAviao() + 1;
}
