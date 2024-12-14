#include "Tripulacao.h"
#include <iostream>
using namespace std;

// Construtor da classe Tripulacao
Tripulacao::Tripulacao(int codigo, string nome, string cargo, string telefone, bool disponivel) {
    codigoTripulacao = codigo;
    nomeTripulacao = nome;
    cargoTripulacao = cargo;
    telefoneTripulacao = telefone;
    disponivel = disponivel;
}

Tripulacao::Tripulacao() {
    codigoTripulacao = 0;
    nomeTripulacao = "";
    cargoTripulacao = "";
    telefoneTripulacao = "";
}

// Pegar a disponibilidade do tripulante
bool Tripulacao::getDisponivel() const {
    return disponivel;
}

// Pegar o código do tripulante
int Tripulacao::getCodigoTripulacao() const {
    return this->codigoTripulacao;
}

// Pegar o nome do tripulante
string Tripulacao::getNomeTripulacao() const {
    return this->nomeTripulacao;
}

// Pegar o cargo do tripulante
string Tripulacao::getCargoTripulacao() const {
    return this->cargoTripulacao;
}

// Pegar o telefone do tripulante
string Tripulacao::getTelefoneTripulacao() const {
    return this->telefoneTripulacao;
}

// Setar a disponibilidade do tripulante
void Tripulacao::setCodigoTripulacao(int codigo) {
    this->codigoTripulacao = codigo;
}

// Setar o código do tripulante
void Tripulacao::setNomeTripulacao(string nome) {
    this->nomeTripulacao = nome;
}

// Setar o nome do tripulante
void Tripulacao::setCargoTripulacao(string cargo) {
    this->cargoTripulacao = cargo;
}

// Setar o cargo do tripulante
void Tripulacao::setTelefoneTripulacao(string telefone) {
    this->telefoneTripulacao = telefone;
}
