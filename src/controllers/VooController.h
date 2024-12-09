#ifndef VOOCONTROLLER_H
#define VOOCONTROLLER_H

#include "../models/Voo.h"
#include "AviaoController.h"
#include "TripulacaoController.h"
#include <vector>
#include <fstream>

using namespace std;

class VooController {
private:
    vector<Voo> lista_voos;

public:
    VooController();
    void carregarVoos();

    Voo* buscarVoo(int codigo_voo);
    int getNumeroVoos() const;

    vector<Voo> getListaVoos() const;

    void salvarVoos();
    void cadastrarVoo(AviaoController* aviaoController, TripulacaoController* tripulacaoController);
    void reservarAssento(int codigo_voo, int numero_assento, Passageiro* passageiro);
    void visualizarVoos() const;
    void darBaixaVoo(int codigo_voo);
    int voosCadastrados() const;
    int getProximoCodigo() const;
};

#endif
