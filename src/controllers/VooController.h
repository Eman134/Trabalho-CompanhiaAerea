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

    Voo* buscarVoo(int codigo_voo);

    void cadastrarVoo();
    void visualizarVoos() const;
    void editarVoo(int codigo_voo);
    void excluirVoo(int codigo_voo);
    void carregarVoos();
    int voosCadastrados() const;
    int getProximoCodigo() const;
};

#endif
