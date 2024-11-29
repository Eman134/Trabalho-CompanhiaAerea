#include "Aviao.h"
#include <iostream>
#include <fstream>

using namespace std;

Aviao::Aviao(int codigo_aviao, string nome_aviao, int qtd_assentos) {
    this->codigo_aviao = codigo_aviao;
    this->nome_aviao = nome_aviao;
    this->qtd_assentos = qtd_assentos;
}

int Aviao::getCodigoAviao() {
    return this->codigo_aviao;
}

string Aviao::getNomeAviao() {
    return this->nome_aviao;
}

int Aviao::getQtdAssentos() {
    return this->qtd_assentos;
}

void Aviao::setCodigoAviao(int codigo_aviao) {
    this->codigo_aviao = codigo_aviao;
}

void Aviao::setNomeAviao(string nome_aviao) {
    this->nome_aviao = nome_aviao;
}

void Aviao::setQtdAssentos(int qtd_assentos) {
    this->qtd_assentos = qtd_assentos;
}

void Aviao::salvar() {
    cout << "Avião salvo!" << endl;
}

void Aviao::carregar() {
    cout << "Avião carregado!" << endl;
}
