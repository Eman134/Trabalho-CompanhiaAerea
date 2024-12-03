#include "Aviao.h"
#include <fstream>

Aviao::Aviao(int codigo_aviao, string nome_aviao, int qtd_assentos) {
    this->codigo_aviao = codigo_aviao;
    this->nome_aviao = nome_aviao;
    this->qtd_assentos = qtd_assentos;
}

Aviao::Aviao() {
    this->codigo_aviao = 0;
    this->nome_aviao = "";
    this->qtd_assentos = 0;
}

int Aviao::getCodigoAviao() const {
    return this->codigo_aviao;
}

string Aviao::getNomeAviao() const {
    return this->nome_aviao;
}

int Aviao::getQtdAssentos() const {
    return this->qtd_assentos;
}

void Aviao::setCodigoAviao(int codigo_aviao) {
    this->codigo_aviao = codigo_aviao;
}

void Aviao::setNomeAviao(const string& nome_aviao) {
    this->nome_aviao = nome_aviao;
}

void Aviao::setQtdAssentos(int qtd_assentos) {
    this->qtd_assentos = qtd_assentos;
}

void Aviao::salvar() {
    ofstream arquivo("./db/avioes.bin", ios::binary | ios::app);
    if (!arquivo.is_open()) {
        return;
    }

    arquivo.write((char*)&codigo_aviao, sizeof(codigo_aviao));

    size_t tamanhoNome = nome_aviao.size();
    arquivo.write((char*)&tamanhoNome, sizeof(tamanhoNome));
    arquivo.write(nome_aviao.c_str(), tamanhoNome);

    arquivo.write((char*)&qtd_assentos, sizeof(qtd_assentos));

    arquivo.close();

}

void Aviao::carregar() {
    
    ifstream arquivo("./db/avioes.bin", ios::binary);

    arquivo.read((char*)&codigo_aviao, sizeof(codigo_aviao));

    size_t tamanhoNome;
    arquivo.read((char*)&tamanhoNome, sizeof(tamanhoNome));

    char* buffer = new char[tamanhoNome + 1];
    arquivo.read(buffer, tamanhoNome);
    buffer[tamanhoNome] = '\0';
    nome_aviao = buffer;
    delete[] buffer;

    arquivo.read((char*)&qtd_assentos, sizeof(qtd_assentos));

    arquivo.close();
}
