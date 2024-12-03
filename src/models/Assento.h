#ifndef ASSENTO_H
#define ASSENTO_H

#include <string>
#include "../../modulos/Passageiro.h"

// Classe que representa um assento em um voo
class Assento {
private:
    int numero; 
    Passageiro* passageiro; 

public:
    // Construtor que inicializa o número do assento e define passageiro como nullptr
    Assento(int num) : numero(num), passageiro(nullptr) {}

    int getNumero() const { return numero; }

    Passageiro* getPassageiro() const { return passageiro; }

    // Verifica se o assento está ocupado
    bool Ocupado() const { return passageiro != nullptr; }

    // Reserva o assento para um passageiro
    void reservar(Passageiro* p) { passageiro = p; }

    // Libera o assento
    void liberar() { passageiro = nullptr; }
};

#endif