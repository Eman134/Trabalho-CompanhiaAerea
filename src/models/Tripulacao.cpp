#include "Tripulacao.h"
#include <iostream>
using namespace std;

Tripulacao::Tripulacao(int codigo, string nome, string cargo, string telefone, bool disponivel) {
    codigoTripulacao = codigo;
    nomeTripulacao = nome;
    cargoTripulacao = cargo;
    telefoneTripulacao = telefone;
    disponivel = disponivel;
}
bool Tripulacao::getDisponivel() const {
    return disponivel;
}

Tripulacao::Tripulacao() {
    codigoTripulacao = 0;
    nomeTripulacao = "";
    cargoTripulacao = "";
    telefoneTripulacao = "";
}

int Tripulacao::getCodigoTripulacao() const {
    return this->codigoTripulacao;
}

string Tripulacao::getNomeTripulacao() const {
    return this->nomeTripulacao;
}

string Tripulacao::getCargoTripulacao() const {
    return this->cargoTripulacao;
}

string Tripulacao::getTelefoneTripulacao() const {
    return this->telefoneTripulacao;
}

void Tripulacao::setCodigoTripulacao(int codigo) {
    this->codigoTripulacao = codigo;
}

void Tripulacao::setNomeTripulacao(string nome) {
    this->nomeTripulacao = nome;
}

void Tripulacao::setCargoTripulacao(string cargo) {
    this->cargoTripulacao = cargo;
}

void Tripulacao::setTelefoneTripulacao(string telefone) {
    this->telefoneTripulacao = telefone;
}
