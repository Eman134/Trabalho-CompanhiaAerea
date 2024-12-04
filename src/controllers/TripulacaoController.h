#ifndef TRIPULACAOCONTROLLER_H
#define TRIPULACAOCONTROLLER_H

#include "../models/Tripulacao.h"
#include <vector>

using namespace std;

class TripulacaoController {
private:
    vector<Tripulacao> tripulacoes;  // Usando o nome correto da classe
    int codigoCounter;  // Contador para gerar c�digo �nico para cada tripula��o

public:
    TripulacaoController();  // Inicializa o contador a partir de 1

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
