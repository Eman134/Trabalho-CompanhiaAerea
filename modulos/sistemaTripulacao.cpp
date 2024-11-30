#include "SistemaTripulacao.h"
#include <iostream>
#include <locale.h>
#include <cctype>  // Para isdigit()
using namespace std;

sistemaTripulacao::sistemaTripulacao() : codigoCounter(1) {}

void sistemaTripulacao::cadastrarTripulacao() {
    string nome, cargo, telefone;

    cout << "\nInforme o nome do tripulante: " << endl;
    cin.ignore();  // Limpar o buffer de entrada
    getline(cin, nome);  // Usar getline para aceitar espaços no nome

    // Garantir que o cargo não esteja vazio
    while(cargo.length() == 0){
        cout << "Informe o cargo do tripulante (não pode ser vazio): " << endl;
        getline(cin, cargo);  // Usar getline para aceitar espaços no cargo
    }

    cout << "Informe o telefone do tripulante (somente números):" << endl;
    cin >> telefone;

    // Verificando se o telefone tem exatamente 11 dígitos e se contém apenas números
    while (telefone.length() != 11 || !isdigit(telefone[0])) {
        cout << "Informe um telefone válido com 11 dígitos (somente números): " << endl;
        cin >> telefone;
    }

    // Gerar o código automaticamente
    tripulacao pass(codigoCounter++, nome, cargo, telefone);  // Usando o contador para gerar código
    Tripulacaos.push_back(pass);  // Adiciona a tripulação ao vetor
    cout << "Tripulação cadastrada com sucesso!" << endl;
}

void sistemaTripulacao::listarTripulacao() {
    // Verificando se existem tripulações cadastradas
    if (Tripulacaos.empty()) {
        cout << "Nenhuma tripulação cadastrada!" << endl;
        return;
    }

    for (const auto& t : Tripulacaos) {
        cout << "\nCodigo: " << t.getCodigoTripulacao() << endl;
        cout << "Nome: " << t.getNomeTripulacao() << endl;
        cout << "Cargo: " << t.getCargoTripulacao() << endl;
        cout << "Telefone: " << t.getTelefoneTripulacao() << endl;
        cout << "---------------------------\n" << endl;
    }
}
