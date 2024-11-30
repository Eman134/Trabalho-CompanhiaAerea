#ifndef SISTEMATRIPULACAO_H_INCLUDED
#define SISTEMATRIPULACAO_H_INCLUDED

#include "Tripulacao.h"
#include <vector>

using namespace std;

class sistemaTripulacao {
private:
    vector<tripulacao> Tripulacaos;  // Usando o nome correto da classe
    int codigoCounter;  // Contador para gerar c�digo �nico para cada tripula��o

public:
    sistemaTripulacao();  // Inicializa o contador a partir de 1

    // Fun��o para cadastrar uma tripula��o
    void cadastrarTripulacao();

    // Fun��o para listar todas as tripula��es cadastradas
    void listarTripulacao();
};

#endif
