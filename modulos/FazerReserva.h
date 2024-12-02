#ifndef FAZERRESERVA_H_INCLUDED
#define FAZERRESERVA_H_INCLUDED

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Reserva {
private:
    int codigoReserva;
    int numerodovoo;
    int codigoPassageiro;
    int pontos_fidelidade;
    string nomePassageiro;
    string endereco;
    string telefone;
    bool fidelidade;
    tm dataReserva;  // Data de reserva, armazenada como estrutura tm

public:

    Reserva(int codigoReserva, int numerodovoo, int codigoPassageiro, int pontos_fidelidade,
            string nomePassageiro, string endereco, string telefone, bool fidelidade);

    // Métodos para acessar os dados privados
    int getCodigoPassageiro();
    int getcodigoReserva();
    int getNumeroVoo();
    string getNomePassageiro();

    // Método para cadastrar reserva
    void cadastrarReserva();

    // Métodos para exibir informações da reserva
    void exibirDataCadastro();
    void exibirdetalhesReserva();
};

#endif
