#ifndef ASSENTO_H
#define ASSENTO_H

#include <string>
#include "Passageiro.h"

class Assento {
private:
    int numero;
    Passageiro* passageiro;

public:
    // Construtor
    Assento(int num = 0);

    // Métodos
    int getNumero() const;
    Passageiro* getPassageiro() const;

    bool Ocupado() const;
    void reservar(Passageiro* p);
    void liberar();
};

#endif
