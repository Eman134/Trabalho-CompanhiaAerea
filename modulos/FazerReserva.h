#ifndef FAZERRESERVA_H_INCLUDED
#define FAZERRESERVA_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "../src/controllers/VooController.h"
#include "FazerReserva.h"
#include "Passageiro.h"

using namespace std;

class Reserva {
private:
    int codigoReserva;
    int codigo_voo;
    int codigoPassageiro;
    int pontos_fidelidade;
    int assento;
    string nomePassageiro;
    string endereco;
    string telefone;
    bool fidelidade;
    int hora;
    string dataVoo;
    float tarifa;
    string dataReserva;  // Data de reserva, armazenada como string

public:
    Reserva();
    Reserva(int codigoReserva, int codigo_voo, int codigoPassageiro, int pontos_fidelidade, int assento,
            string nomePassageiro, string endereco, string telefone, string dataVoo, bool fidelidade, int hora,
            string dataReserva, float tarifa);

    // Métodos para acessar os dados privados
    int getCodigoPassageiro();
    int getCodigoReserva();
    int getNumeroVoo();
    int getAssento();
    string getNomePassageiro();
    string getdataVoo();
    string getdataReserva();
    float getTarifa();

    // Método para cadastrar reserva
    void cadastrarReserva(VooController* vooController, Passageiro* passageiro);

    // Métodos para exibir informações da reserva
    void exibirDetalhesReserva();
};

#endif
