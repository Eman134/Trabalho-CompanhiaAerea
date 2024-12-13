#ifndef PASSAGEIROCONTROLLER_H
#define PASSAGEIROCONTROLLER_H
#include <string>
#include <vector>
#include "../models/Passageiro.h"

using namespace std;

// Classe PassageiroController
class PassageiroController {
private:
    vector<Passageiro> lista_passageiros;
public:

    // Construtor padrão, que inicializa os atributos com valores padrão
    PassageiroController();

    // Métodos para manipulação da lista de passageiros
    bool verificarDuplicidade(int codigo_passageiro);
    void cadastrarPassageiro();
    void salvarPassageiros();
    void carregarPassageiros();
    void pesquisarPassageiro();
    Passageiro* buscarPassageiro(int codigo_passageiro);
    Passageiro* buscarPassageiro(const string& nome);
    vector<Passageiro> getListaPassageiros() const;
};

#endif
