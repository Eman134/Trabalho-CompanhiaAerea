#include "Passageiro.h"
#include <iostream>

Passageiro::Passageiro(int codigo_passageiro, std::string nome, std::string endereco, std::string telefone, bool fidelidade, int pontos_fidelidade) {
    this->codigo_passageiro = codigo_passageiro;
    this->nome = nome;
    this->endereco = endereco;
    this->telefone = telefone;
    this->fidelidade = fidelidade;
    this->pontos_fidelidade = pontos_fidelidade;
}

int Passageiro::getCodigoPassageiro() {
    return this->codigo_passageiro;
}

std::string Passageiro::getNome() {
    return this->nome;
}

std::string Passageiro::getEndereco() {
    return this->endereco;
}

std::string Passageiro::getTelefone() {
    return this->telefone;
}

bool Passageiro::isFidelidade() {
    return this->fidelidade;
}

int Passageiro::getPontosFidelidade() {
    return this->pontos_fidelidade;
}

void Passageiro::setCodigoPassageiro(int codigo_passageiro) {
    this->codigo_passageiro = codigo_passageiro;
}

void Passageiro::setNome(std::string nome) {
    this->nome = nome;
}

void Passageiro::setEndereco(std::string endereco) {
    this->endereco = endereco;
}

void Passageiro::setTelefone(std::string telefone) {
    this->telefone = telefone;
}

void Passageiro::setFidelidade(bool fidelidade) {
    this->fidelidade = fidelidade;
}

void Passageiro::setPontosFidelidade(int pontos_fidelidade) {
    this->pontos_fidelidade = pontos_fidelidade;
}
using namespace std;

void cadastrarPassageiro() {
    int codigo_passageiro;
    string nome;
    string endereco;
    string telefone;
    bool fidelidade;
    int pontos_fidelidade;

    cout << "Digite o código do passageiro: ";
    cin >> codigo_passageiro;
    cout << "Digite o nome do passageiro: ";
    cin.ignore();
    getline(cin, nome);
    cout << "Digite o endereço do passageiro: ";
    getline(cin, endereco);
    cout << "Digite o telefone do passageiro: ";
    getline(cin, telefone);
    cout << "O passageiro possui fidelidade? (1 para sim, 0 para não): ";
    cin >> fidelidade;
    cout << "Digite os pontos de fidelidade do passageiro: ";
    cin >> pontos_fidelidade;

    Passageiro passageiro(codigo_passageiro, nome, endereco, telefone, fidelidade, pontos_fidelidade);
    cout << "Passageiro cadastrado com sucesso!" << endl;
}