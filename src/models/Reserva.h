#ifndef RESERVA_H_INCLUDED
#define RESERVA_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "../controllers/VooController.h"
#include "../controllers/PassageiroController.h"
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
    string dataReserva; 

public:

    // Construtores
    Reserva();
    Reserva(int codigoReserva, int codigo_voo, int codigoPassageiro, int pontos_fidelidade, int assento,
            string nomePassageiro, string endereco, string telefone, string dataVoo, bool fidelidade, int hora,
            string dataReserva, float tarifa);

    // Métodos para acessar os dados privados
    int getCodigoPassageiro() const;
    int getCodigoReserva() const;
    int getNumeroVoo() const;
    int getAssento() const;
    string getNomePassageiro() const;
    string getdataVoo() const;
    string getdataReserva() const;
    float getTarifa() const;
    int getHora() const;
    int getPontosFidelidade() const;
    string getEndereco() const;
    string getTelefone() const;
    bool isFidelidade() const;

    // Métodos para modificar os dados privados
    void setCodigoPassageiro(int codigoPassageiro);
    void setCodigoReserva(int codigoReserva);
    void setNumeroVoo(int codigo_voo);
    void setAssento(int assento);
    void setNomePassageiro(string nomePassageiro);
    void setdataVoo(string dataVoo);
    void setdataReserva(string dataReserva);
    void setTarifa(float tarifa);
    void setHora(int hora);
    void setPontosFidelidade(int pontos_fidelidade);
    void setEndereco(string endereco);
    void setTelefone(string telefone);
    void setFidelidade(bool fidelidade);

};

#endif
