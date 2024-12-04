#ifndef FAZERRESERVA_H_INCLUDED
#define FAZERRESERVA_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "voo.h"
#include "FazerReserva.h"
#include "Passageiro.h"

using namespace std;

class Reserva {
private:
    int codigoReserva;
    int numerodovoo;
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
    Reserva(int codigoReserva, int numerodovoo, int codigoPassageiro, int pontos_fidelidade, int assento,
            string nomePassageiro, string endereco, string telefone, string dataVoo, bool fidelidade, int hora,
            string dataReserva, float tarifa);

    // Métodos para acessar os dados privados
    int getCodigoPassageiro();
    int getcodigoReserva();
    int getNumeroVoo();
    int getAssento();
    string getNomePassageiro();
    string getdataVoo();
    string getdataReserva();
    float getTarifa();

    // Método para cadastrar reserva
    void cadastrarReserva(vector<Reserva>& reservas, vector<Passageiro>& passageiros, vector<Voo>& voos);

    // Métodos para exibir informações da reserva
    void exibirDataCadastro();
    void exibirDetalhesReserva();
};

#endif
