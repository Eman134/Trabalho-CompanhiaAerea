#ifndef AVIAOCONTROLLER_H
#define AVIAOCONTROLLER_H

#include "../models/Aviao.h"
#include <vector>
#include <fstream>

using namespace std;

class AviaoController {
private:
    vector<Aviao> lista_avioes;

    void criarDiretorioLocal();

public:
    AviaoController();
    void carregarAvioes();
    void salvarAvioes();

    Aviao* buscarAviao(int codigo_aviao);

    void cadastrarAviao();
    void visualizarAvioes() const;
    
    int avioesCadastrados() const;
    int getProximoCodigo() const;
};

#endif
