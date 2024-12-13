#ifndef TRIPULACAOCONTROLLER_H
#define TRIPULACAOCONTROLLER_H

#include "../models/Tripulacao.h"
#include <vector>

using namespace std;

class TripulacaoController {
private:
    vector<Tripulacao> tripulacoes;
    int codigoCounter;

public:

    // Construtor padrão que inicializa a lista de tripulacoes
    TripulacaoController();

    // Métodos para manipulação da lista de tripulacoes
    vector<Tripulacao> getTripulacoes() const;

    int getQtdPiloto() const;
    int getQtdCopiloto() const;
    int getQtdComissario() const;

    void cadastrarTripulacao();
    void listarTripulacao();
    void salvarTripulacao();
    void carregarTripulacao();
};

#endif
