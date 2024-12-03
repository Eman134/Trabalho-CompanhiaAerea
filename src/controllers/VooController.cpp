#include "VooController.h"
#include <iostream>
#include <sys/stat.h>
#ifdef _WIN32
    #include <direct.h>
#endif

using namespace std;

VooController::VooController() {
    carregarVoos();
}

void VooController::carregarVoos() {
    lista_voos.clear();

    ifstream arquivo("./db/voos.bin", ios::binary);
    if (!arquivo) {
        return;
    }

    while (arquivo.peek() != EOF) {
        Voo Voo;
        Voo.carregar();
        lista_voos.push_back(Voo);
    }

    arquivo.close();
}

void VooController::cadastrarVoo() {
    Voo voo;
    int codigo_voo = getProximoCodigo();
    voo.setCodigoVoo(codigo_voo);

    string origem, destino, data;
    cout << "Digite a origem: ";
    cin >> origem;
    voo.setOrigem(origem);

    cout << "Digite o destino: ";
    cin >> destino;
    voo.setDestino(destino);

    cout << "Digite a data (dd/mm/aaaa): ";
    cin >> data;
    voo.setData(data);

    voo.salvar();
    lista_voos.push_back(voo);
}

Voo* VooController::buscarVoo(int codigoVoo) {
    for (auto& voo : lista_voos) {
        if (voo.getCodigoVoo() == codigoVoo) {
            return &voo;
        }
    }
    return nullptr;
}

int VooController::getNumeroVoos() const {
    return lista_voos.size();
}

void VooController::visualizarVoos() const {

    if (lista_voos.empty()) {
        cout << "Nenhum voo cadastrado no sistema." << endl;
        return;
    }

    cout << "voos cadastrados no sistema:" << endl;
    for (const Voo& Voo : lista_voos) {
        cout << "Código do Voo: " << Voo.getCodigoVoo() << endl;
        cout << "Origem: " << Voo.getOrigem() << " - Destino: " << Voo.getDestino() << endl;
        cout << "Data: " << Voo.getData() << " Hora: " << Voo.getHora() << endl;
        cout << "Tarifa: " << Voo.getTarifa() << " Assentos disponíveis: [" << Voo.getAssentosDisponiveis() << "/" << Voo.getAssentosTotais() << "]" << endl;
    }
}

int VooController::voosCadastrados() const {
    return lista_voos.size();
}

int VooController::getProximoCodigo() const {
    if (lista_voos.empty()) {
        return 1;
    }
    return lista_voos.back().getCodigoVoo() + 1;
}