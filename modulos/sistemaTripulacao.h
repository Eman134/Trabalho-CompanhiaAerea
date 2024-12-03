#ifndef SISTEMATRIPULACAO_H_INCLUDED
#define SISTEMATRIPULACAO_H_INCLUDED

#include "Tripulacao.h"
#include <vector>

using namespace std;

class sistemaTripulacao {
private:
    vector<tripulacao> tripulacoes;  // Usando o nome correto da classe
    int codigoCounter;  // Contador para gerar c�digo �nico para cada tripula��o
    int qtdPiloto;
    int qtdCopiloto;
    int qtdComissario;

public:
    sistemaTripulacao();  // Inicializa o contador a partir de 1

    int getqtdPiloto() const;
    int getqtdCopiloto() const;
    int getqtdComissario() const;

    void setqtdPiloto(int qtdPiloto);
    void setqtdCopiloto(int qtdCopiloto);
    void setqtdComissario(int qtdComissario);

    // Fun��o para cadastrar uma tripula��o
    void cadastrarTripulacao();

    // Fun��o para listar todas as tripula��es cadastradas
    void listarTripulacao();
};

#endif
