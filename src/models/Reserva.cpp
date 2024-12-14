#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include "Reserva.h"

using namespace std;

// Construtor da classe Reserva
Reserva::Reserva(int codigoReserva, int codigo_voo, int codigoPassageiro, int pontos_fidelidade, int assento,
                 string nomePassageiro, string endereco, string telefone, string dataVoo, bool fidelidade, int hora,
                 string dataReserva, float tarifa) {
    this->codigoReserva = codigoReserva;
    this->codigo_voo = codigo_voo;
    this->codigoPassageiro = codigoPassageiro;
    this->pontos_fidelidade = pontos_fidelidade;
    this->assento = assento;
    this->nomePassageiro = nomePassageiro;
    this->endereco = endereco;
    this->telefone = telefone;
    this->fidelidade = fidelidade;
    this->hora = hora;
    this->dataVoo = dataVoo;
    this->dataReserva = dataReserva;
    this->tarifa = tarifa;
}
 
// Construtor padrão da classe Reserva
Reserva::Reserva() {
    this->codigoReserva = codigoReserva;
    this->codigo_voo = codigo_voo;
    this->codigoPassageiro = codigoPassageiro;
    this->pontos_fidelidade = pontos_fidelidade;
    this->nomePassageiro = nomePassageiro;
    this->endereco = endereco;
    this->telefone = telefone;
    this->fidelidade = fidelidade;
    this->dataVoo = dataVoo;
    this->hora = hora;
    this->dataReserva = dataReserva;
    this->assento = assento;
    this->tarifa = tarifa;
}

// Pegar o código do passageiro
int Reserva::getCodigoPassageiro() const {
    return this->codigoPassageiro;
}

// Pegar o código da reserva
int Reserva::getCodigoReserva() const {
    return this->codigoReserva;
}

// Pegar o número do voo
int Reserva::getNumeroVoo() const {
    return this->codigo_voo;
}

// Pegar o número do assento
int Reserva::getAssento() const {
    return this->assento;
}

// Pegar o nome do passageiro
string Reserva::getNomePassageiro() const {
    return this->nomePassageiro;
}

// Pegar a data do voo
string Reserva::getdataVoo() const {
    return this->dataVoo;
}

// Pegar a data da reserva
string Reserva::getdataReserva() const {
    return this->dataReserva;
}

// Pegar a tarifa
float Reserva::getTarifa() const {
    return this->tarifa;
}

// Pegar a hora
int Reserva::getHora() const {
    return this->hora;
}

// Pegar os pontos de fidelidade
int Reserva::getPontosFidelidade() const {
    return this->pontos_fidelidade;
}

// Pegar o endereço
string Reserva::getEndereco() const {
    return this->endereco;
}

// Pegar o telefone
string Reserva::getTelefone() const {
    return this->telefone;
}

// Pegar a fidelidade
bool Reserva::isFidelidade() const {
    return this->fidelidade;
}

// Setar o código do passageiro
void Reserva::setCodigoPassageiro(int codigoPassageiro) {
    this->codigoPassageiro = codigoPassageiro;
}

// Setar o código da reserva
void Reserva::setCodigoReserva(int codigoReserva) {
    this->codigoReserva = codigoReserva;
}

// Setar o número do voo
void Reserva::setNumeroVoo(int codigo_voo) {
    this->codigo_voo = codigo_voo;
}

// Setar o número do assento
void Reserva::setAssento(int assento) {
    this->assento = assento;
}

// Setar o nome do passageiro
void Reserva::setNomePassageiro(string nomePassageiro) {
    this->nomePassageiro = nomePassageiro;
}

// Setar a data do voo
void Reserva::setdataVoo(string dataVoo) {
    this->dataVoo = dataVoo;
}

// Setar a data da reserva
void Reserva::setdataReserva(string dataReserva) {
    this->dataReserva = dataReserva;
}

// Setar a tarifa
void Reserva::setTarifa(float tarifa) {
    this->tarifa = tarifa;
}

// Setar a hora
void Reserva::setHora(int hora) {
    this->hora = hora;
}

// Setar os pontos de fidelidade
void Reserva::setPontosFidelidade(int pontos_fidelidade) {
    this->pontos_fidelidade = pontos_fidelidade;
}

// Setar o endereço
void Reserva::setEndereco(string endereco) {
    this->endereco = endereco;
}

// Setar o telefone
void Reserva::setTelefone(string telefone) {
    this->telefone = telefone;
}

// Setar a fidelidade
void Reserva::setFidelidade(bool fidelidade) {
    this->fidelidade = fidelidade;
}
