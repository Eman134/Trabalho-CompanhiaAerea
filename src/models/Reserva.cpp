#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include "Reserva.h"

using namespace std;

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

int Reserva::getCodigoPassageiro() const {
    return this->codigoPassageiro;
}

int Reserva::getCodigoReserva() const {
    return this->codigoReserva;
}

int Reserva::getNumeroVoo() const {
    return this->codigo_voo;
}

int Reserva::getAssento() const {
    return this->assento;
}

string Reserva::getNomePassageiro() const {
    return this->nomePassageiro;
}

string Reserva::getdataVoo() const {
    return this->dataVoo;
}

string Reserva::getdataReserva() const {
    return this->dataReserva;
}

float Reserva::getTarifa() const {
    return this->tarifa;
}

int Reserva::getHora() const {
    return this->hora;
}

int Reserva::getPontosFidelidade() const {
    return this->pontos_fidelidade;
}

string Reserva::getEndereco() const {
    return this->endereco;
}

string Reserva::getTelefone() const {
    return this->telefone;
}

bool Reserva::isFidelidade() const {
    return this->fidelidade;
}

void Reserva::setCodigoPassageiro(int codigoPassageiro) {
    this->codigoPassageiro = codigoPassageiro;
}

void Reserva::setCodigoReserva(int codigoReserva) {
    this->codigoReserva = codigoReserva;
}

void Reserva::setNumeroVoo(int codigo_voo) {
    this->codigo_voo = codigo_voo;
}

void Reserva::setAssento(int assento) {
    this->assento = assento;
}

void Reserva::setNomePassageiro(string nomePassageiro) {
    this->nomePassageiro = nomePassageiro;
}

void Reserva::setdataVoo(string dataVoo) {
    this->dataVoo = dataVoo;
}

void Reserva::setdataReserva(string dataReserva) {
    this->dataReserva = dataReserva;
}

void Reserva::setTarifa(float tarifa) {
    this->tarifa = tarifa;
}

void Reserva::setHora(int hora) {
    this->hora = hora;
}

void Reserva::setPontosFidelidade(int pontos_fidelidade) {
    this->pontos_fidelidade = pontos_fidelidade;
}

void Reserva::setEndereco(string endereco) {
    this->endereco = endereco;
}

void Reserva::setTelefone(string telefone) {
    this->telefone = telefone;
}

void Reserva::setFidelidade(bool fidelidade) {
    this->fidelidade = fidelidade;
}
