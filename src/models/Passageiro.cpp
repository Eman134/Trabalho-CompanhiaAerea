#include "Passageiro.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Construtor que inicializa um passageiro com os dados fornecidos
Passageiro::Passageiro(int codigo_passageiro, string nome, string endereco, string telefone, bool fidelidade, int pontos_fidelidade) {
    this->codigo_passageiro = codigo_passageiro;
    this->nome = nome;
    this->endereco = endereco;
    this->telefone = telefone;
    this->fidelidade = fidelidade;
    this->pontos_fidelidade = pontos_fidelidade;
}

// Construtor padrão que inicializa um passageiro com valores padrão
Passageiro::Passageiro() {
    this->codigo_passageiro = 0;
    this->nome = "";
    this->endereco = "";
    this->telefone = "";
    this->fidelidade = false;
    this->pontos_fidelidade = 0;
}

// Métodos getter para acessar os atributos privados de um passageiro
int Passageiro::getCodigoPassageiro() const { return this->codigo_passageiro; }
string Passageiro::getNome() const { return this->nome; }
string Passageiro::getEndereco() const { return this->endereco; }
string Passageiro::getTelefone() const { return this->telefone; }
bool Passageiro::isFidelidade() const { return this->fidelidade; }
int Passageiro::getPontosFidelidade() const { return this->pontos_fidelidade; }

// Métodos setter para modificar os atributos privados de um passageiro
void Passageiro::setCodigoPassageiro(int codigo_passageiro) { this->codigo_passageiro = codigo_passageiro; }
void Passageiro::setNome(string nome) { this->nome = nome; }
void Passageiro::setEndereco(string endereco) { this->endereco = endereco; }
void Passageiro::setTelefone(string telefone) { this->telefone = telefone; }
void Passageiro::setFidelidade(bool fidelidade) { this->fidelidade = fidelidade; }
void Passageiro::setPontosFidelidade(int pontos_fidelidade) { this->pontos_fidelidade = pontos_fidelidade; }
