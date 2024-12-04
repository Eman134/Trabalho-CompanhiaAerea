#include "Aviao.h"
#include <fstream>

Aviao::Aviao(int codigo_aviao, string nome_aviao, int qtd_assentos, bool disponivel) {
    this->codigo_aviao = codigo_aviao;
    this->nome_aviao = nome_aviao;
    this->qtd_assentos = qtd_assentos;
    this->disponivel = disponivel;
}

Aviao::Aviao() {
    this->codigo_aviao = 0;
    this->nome_aviao = "";
    this->qtd_assentos = 0;
    this->disponivel = true;
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

void Aviao::setDisponibilidade(bool disponibilidade) {
    this->disponivel = disponibilidade;
}

bool Aviao::getDisponivel() const {
    return this->disponivel;
}

void Aviao::salvar(std::ostream& out) const {
    out.write((char*)&codigo_aviao, sizeof(codigo_aviao));

    size_t tamanhoNome = nome_aviao.size();
    out.write((char*)&tamanhoNome, sizeof(tamanhoNome));
    out.write(nome_aviao.c_str(), tamanhoNome);

    out.write((char*)&qtd_assentos, sizeof(qtd_assentos));

    out.write((char*)&disponivel, sizeof(disponivel));
}

void Aviao::carregar(std::istream& in) {
    in.read((char*)&codigo_aviao, sizeof(codigo_aviao));

    size_t tamanhoNome;
    in.read((char*)&tamanhoNome, sizeof(tamanhoNome));

    char* buffer = new char[tamanhoNome + 1];
    in.read(buffer, tamanhoNome);
    buffer[tamanhoNome] = '\0';
    nome_aviao = buffer;
    delete[] buffer;

    in.read((char*)&qtd_assentos, sizeof(qtd_assentos));

    in.read((char*)&disponivel, sizeof(disponivel));
}
