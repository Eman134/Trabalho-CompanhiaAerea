#ifndef VOOCONTROLLER_H
#define VOOCONTROLLER_H

#include "../models/Voo.h"
#include "../models/Passageiro.h"
#include "AviaoController.h"
#include "TripulacaoController.h"
#include <vector>
#include <fstream>

using namespace std;

class VooController {
private:
    vector<Voo> lista_voos;

public:

    // Construtor padrão que inicializa a lista de voos
    VooController();

    // Métodos para manipulação da lista de voos

    void carregarVoos();

    Voo* buscarVoo(int codigo_voo);
    int getNumeroVoos() const;

    vector<Voo> getListaVoos() const;

    void salvarVoos();
    void cadastrarVoo(AviaoController* aviaoController, TripulacaoController* tripulacaoController);
    void visualizarVoos() const;
    void darBaixaVoo(int codigo_voo);
    int voosCadastrados() const;
    int getProximoCodigo() const;
};

#endif
