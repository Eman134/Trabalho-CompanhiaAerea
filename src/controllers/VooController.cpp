#include "VooController.h"
#include "AviaoController.h"
#include "TripulacaoController.h"
#include <iostream>
#include <sys/stat.h>
#include <fstream>
#include <limits>
#ifdef _WIN32
    #include <direct.h>
#endif

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

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
        Voo voo;
        voo.carregar(arquivo);
        lista_voos.push_back(voo);
    }

    arquivo.close();
}

void VooController::salvarVoos() {

    std::ofstream arquivo("./db/voos.bin", std::ios::binary | std::ios::trunc);
    if (!arquivo) {
        return;
    }

    for (const Voo& voo : lista_voos) {
        voo.salvar(arquivo);
    }

    arquivo.close();
}


vector<Voo> VooController::getListaVoos() const {
    return lista_voos;
}

void VooController::cadastrarVoo() {
    Voo voo;
    int codigo_voo = getProximoCodigo();
    voo.setCodigoVoo(codigo_voo);

    AviaoController aviaoController;

    if (aviaoController.avioesCadastrados() == 0) {
        cout << "Nenhum aviao cadastrado no sistema. Cadastre um aviao antes de cadastrar um voo." << endl;
        return;
    }

    if (aviaoController.avioesDisponiveis() == 0) {
        cout << "Nenhum aviao disponível no sistema. Cadastre um aviao ou espere o voo do aviao antes de cadastrar um novo voo." << endl;
        return;
    }

    cout << "Avioes disponiveis [" << aviaoController.avioesDisponiveis() << "/" << aviaoController.avioesCadastrados() << "]" << endl;
    for (const Aviao& aviao : aviaoController.getListaAvioes()) {
        string disponivel = aviao.getDisponivel() ? GREEN + string("Disponivel") + RESET : RED + string("Indisponivel") + RESET;
        cout << "[" << disponivel << "] Codigo: " << aviao.getCodigoAviao() << " - Nome: " << aviao.getNomeAviao() << " - Assentos maximos: " << aviao.getQtdAssentos() << endl;
    }

    int codigo_aviao;
    Aviao aviao;

    cout << "Digite o codigo do aviao para o voo: ";

    while (true) {

        try {
            cin >> codigo_aviao;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Codigo invalido. Digite um numero inteiro.");
            }
        } catch (const invalid_argument& e) {
            cout << RED << e.what() << RESET << endl;
            cout << "Digite o codigo do aviao para o voo: ";
            continue;
        }

        if (aviaoController.buscarAviao(codigo_aviao)) {
            aviao = *aviaoController.buscarAviao(codigo_aviao);
            break;
        }
        cout << RED << "Aviao nao encontrado. Digite um codigo valido: " << RESET << endl;
    }

    cout << GREEN << "Aviao selecionado: " << RESET << aviao.getNomeAviao() << " de codigo " << aviao.getCodigoAviao() << endl;

    voo.setCodigoAviao(aviao.getCodigoAviao());

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

    lista_voos.push_back(voo);
    salvarVoos();
    
}

Voo* VooController::buscarVoo(int codigo_voo) {
    for (auto& voo : lista_voos) {
        if (voo.getCodigoVoo() == codigo_voo) {
            return &voo;
        }
    }
    return nullptr;
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