#ifndef RESERVACONTROLLER_H_INCLUDED
#define RESERVACONTROLLER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "./VooController.h"
#include "./PassageiroController.h"
#include "../models/Passageiro.h"
#include "../models/Reserva.h"

using namespace std;

class ReservaController {

    private:
        vector<Reserva> lista_reservas;
    public:

        ReservaController();

        // Método para cadastrar reserva
        void cadastrarReserva(VooController* vooController, PassageiroController* passageiroController);

        // Métodos para exibir informações da reserva
        void exibirDetalhesReserva(Reserva* reserva);

        // Métodos para manipulação da lista de reservas
        Reserva* buscarReserva(int codigo_reserva);

        vector<Reserva> getListaReservas() const;

        void salvarReservas();

        void carregarReservas();

        void excluirReservasVoo(int codigo_voo);

        void listarReservas();

        void exibirTabelaAssentos(int codigo_voo);

        void reservarAssento(int codigo_voo, int assento, Passageiro* passageiro);

        int getProximoCodigoReserva() const;

        bool estaReservado(int codigo_voo, int assento);
    
};

#endif
