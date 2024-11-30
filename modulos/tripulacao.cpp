#include "Tripulacao.h"
#include <iostream>
using namespace std;

tripulacao::tripulacao(int codigo, string nome, string cargo, string telefone)
    : codigoTripulacao(codigo), nomeTripulacao(nome), cargoTripulacao(cargo), telefoneTripulacao(telefone) {}

int tripulacao::getCodigoTripulacao() const {
    return this->codigoTripulacao;
}

string tripulacao::getNomeTripulacao() const {
    return this->nomeTripulacao;
}

string tripulacao::getCargoTripulacao() const {
    return this->cargoTripulacao;
}

string tripulacao::getTelefoneTripulacao() const {
    return this->telefoneTripulacao;
}

void tripulacao::setCodigoTripulacao(int codigo) {
    this->codigoTripulacao = codigo;
}

void tripulacao::setNomeTripulacao(string nome) {
    this->nomeTripulacao = nome;
}

void tripulacao::setCargoTripulacao(string cargo) {
    this->cargoTripulacao = cargo;
}

void tripulacao::setTelefoneTripulacao(string telefone) {
    this->telefoneTripulacao = telefone;
}

void tripulacao::salvar() {
    cout << "Tripulação salva com sucesso!" << endl;
}

void tripulacao::carregar() {
    cout << "Tripulação carregada!" << endl;
}
