#include "Aviao.h"
#include <fstream>

// Construtor da classe Aviao
Aviao::Aviao(int codigo_aviao, string nome_aviao, int qtd_assentos, bool disponivel) {
    this->codigo_aviao = codigo_aviao;
    this->nome_aviao = nome_aviao;
    this->qtd_assentos = qtd_assentos;
    this->disponivel = disponivel;
}

// Construtor da classe Aviao
Aviao::Aviao() {
    this->codigo_aviao = 0;
    this->nome_aviao = "";
    this->qtd_assentos = 50;
    this->disponivel = true;
}

// Pegar o código do avião
int Aviao::getCodigoAviao() const {
    return this->codigo_aviao;
}

// Pegar o nome do avião
string Aviao::getNomeAviao() const {
    return this->nome_aviao;
}

// Pegar a quantidade de assentos do avião
int Aviao::getQtdAssentos() const {
    return this->qtd_assentos;
}

// Setar o código do avião
void Aviao::setCodigoAviao(int codigo_aviao) {
    this->codigo_aviao = codigo_aviao;
}

// Setar o nome do avião
void Aviao::setNomeAviao(const string& nome_aviao) {
    this->nome_aviao = nome_aviao;
}

// Setar a quantidade de assentos do avião
void Aviao::setQtdAssentos(int qtd_assentos) {
    this->qtd_assentos = qtd_assentos;
}

// Alterar a disponibilidade do avião
void Aviao::setDisponibilidade(bool disponibilidade) {
    this->disponivel = disponibilidade;
}

// Pegar a disponibilidade do avião
bool Aviao::getDisponivel() const {
    return this->disponivel;
}

// Método para salvar os dados do avião
void Aviao::salvar(std::ostream& out) const {
    out.write((char*)&codigo_aviao, sizeof(codigo_aviao));

    size_t tamanhoNome = nome_aviao.size();
    out.write((char*)&tamanhoNome, sizeof(tamanhoNome));
    out.write(nome_aviao.c_str(), tamanhoNome);

    out.write((char*)&qtd_assentos, sizeof(qtd_assentos));

    out.write((char*)&disponivel, sizeof(disponivel));
}

// Método para carregar os dados do avião
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
