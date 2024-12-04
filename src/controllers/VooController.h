#ifndef VOOCONTROLLER_H
#define VOOCONTROLLER_H

#include "../models/Voo.h"
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
    void cadastrarVoo();
    void visualizarVoos() const;
    void editarVoo(int codigo_voo);
    void excluirVoo(int codigo_voo);
    int voosCadastrados() const;
    int getProximoCodigo() const;
};

#endif
