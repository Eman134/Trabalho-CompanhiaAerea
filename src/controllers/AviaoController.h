#ifndef AVIAOCONTROLLER_H
#define AVIAOCONTROLLER_H

#include "../models/Aviao.h"
#include <vector>
#include <fstream>

using namespace std;

class AviaoController {
private:
    vector<Aviao> lista_avioes;

public:
    // Construtor padrão que inicializa a lista de avioes'
    AviaoController();
    void carregarAvioes();
    void salvarAvioes();

    // Métodos para manipulação da lista de avioes
    Aviao* buscarAviao(int codigo_aviao);

    vector<Aviao> getListaAvioes() const;
    void cadastrarAviao();
    void editarAviao(int codigo_aviao);
    void excluirAviao(int codigo_aviao);
    void visualizarAvioes() const;

    void setDisponibilidade(int codigo_aviao, bool disponibilidade);
    
    int avioesDisponiveis() const;
    int avioesCadastrados() const;
    int getProximoCodigo() const;
};

#endif
