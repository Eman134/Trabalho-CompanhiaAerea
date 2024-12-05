#include "Assento.h"

// Construtor que inicializa o número do assento e define passageiro como nullptr
Assento::Assento(int num) : numero(num), passageiro(nullptr) {}

// Retorna o número do assento
int Assento::getNumero() const {
    return numero;
}

// Retorna o ponteiro para o passageiro associado ao assento
Passageiro* Assento::getPassageiro() const {
    return passageiro;
}

// Verifica se o assento está ocupado (se existe um passageiro associado)
bool Assento::Ocupado() const {
    return true;
}

// Reserva o assento para um passageiro
void Assento::reservar(Passageiro* p) {
    passageiro = p;
}

// Libera o assento (remove a associação com o passageiro)
void Assento::liberar() {
    passageiro = nullptr;
}
