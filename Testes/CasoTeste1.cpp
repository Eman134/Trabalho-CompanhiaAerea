#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include "TripulacaoController.h"

using namespace std;

// Função de teste automatizado para cadastrar tripulação
void TestCadastrarTripulacao() {
    TripulacaoController controller;

    // Função para simular entrada padrão para testar a função
    auto simulateCin = [](const string& input) {
        streambuf* orig = cin.rdbuf();
        stringstream ss(input);
        cin.rdbuf(ss.rdbuf());
        return orig;
    };

    // Teste 1: Adicionar um tripulante válido
    string input1 = "\nJoão da Silva\n1\n11987654321\n";
    auto orig = simulateCin(input1);
    controller.cadastrarTripulacao();
    cin.rdbuf(orig);  // Restaurar buffer original

    const auto& tripulacoes = controller.getTripulacoes();
    assert(tripulacoes.size() == 1);
    assert(tripulacoes[0].getNomeTripulacao() == "João da Silva");
    assert(tripulacoes[0].getCargoTripulacao() == "Piloto");
    assert(tripulacoes[0].getTelefoneTripulacao() == "11987654321");

    // Teste 2: Adicionar outro tripulante válido
    string input2 = "\nMaria de Souza\n2\n11912345678\n";
    orig = simulateCin(input2);
    controller.cadastrarTripulacao();
    cin.rdbuf(orig);

    assert(tripulacoes.size() == 2);
    assert(tripulacoes[1].getNomeTripulacao() == "Maria de Souza");
    assert(tripulacoes[1].getCargoTripulacao() == "Co-piloto");
    assert(tripulacoes[1].getTelefoneTripulacao() == "11912345678");

    cout << "Todos os testes passaram!" << endl;
}

// Função principal
int main() {
    TestCadastrarTripulacao();
    return 0;
}
