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
#define CYAN "\033[36m"

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

void VooController::cadastrarVoo(AviaoController* aviaoController) {
    Voo voo;
    int codigo_voo = getProximoCodigo();
    voo.setCodigoVoo(codigo_voo);


    if (aviaoController->avioesCadastrados() == 0) {
        cout << "Nenhum aviao cadastrado no sistema. Cadastre um aviao antes de cadastrar um voo." << endl;
        return;
    }

    if (aviaoController->avioesDisponiveis() == 0) {
        cout << "Nenhum aviao disponivel no sistema.\nCadastre um aviao ou espere o voo do aviao antes de cadastrar um novo voo." << endl;
        return;
    }

    cout << "Avioes disponiveis [" << aviaoController->avioesDisponiveis() << "/" << aviaoController->avioesCadastrados() << "]" << endl;
    for (const Aviao& aviao : aviaoController->getListaAvioes()) {
        string disponivel = aviao.getDisponivel() ? GREEN + string("Disponivel") + RESET : RED + string("Indisponivel") + RESET;
        cout << "[" << disponivel << "] Codigo: " << aviao.getCodigoAviao() << " - Nome: " << aviao.getNomeAviao() << " - Assentos maximos: " << aviao.getQtdAssentos() << endl;
    }

    int codigo_aviao;
    Aviao* aviao;

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

        aviao = aviaoController->buscarAviao(codigo_aviao);

        if (aviao && aviao->getDisponivel()) {
            break;
        } else if (aviao && !aviao->getDisponivel()) {
            cout << RED << "Aviao indisponivel. Digite um codigo valido: " << RESET << endl;
        } else {
            cout << RED << "Aviao nao encontrado. Digite um codigo valido: " << RESET << endl;
        }

    }

    cout << GREEN << "Aviao selecionado: " << RESET << aviao->getNomeAviao() << " de codigo " << aviao->getCodigoAviao() << endl;


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

    int hora;
    cout << "Digite a hora (hh): ";
    cin >> hora;
    voo.setHora(hora);

    float tarifa;
    cout << "Digite a tarifa: ";
    cin >> tarifa;
    voo.setTarifa(tarifa);

    voo.setCodigoAviao(aviao->getCodigoAviao());

    aviaoController->setDisponibilidade(aviao->getCodigoAviao(), false);

    voo.setAssentosDisponiveis(aviao->getQtdAssentos());

    lista_voos.push_back(voo);
    salvarVoos();

    cout << " " << endl;

    cout << GREEN << "Voo cadastrado com sucesso!" << RESET << endl;
    
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

    for (const Voo& voo : lista_voos) {
        cout << "Codigo do Voo: " << voo.getCodigoVoo() << endl;
        cout << "Codigo do Aviao: " << voo.getCodigoAviao() << endl;
        cout << "Codigo do Piloto: " << voo.getCodigoPiloto() << endl;
        cout << "Codigo do Co-piloto: " << voo.getCodigoCopiloto() << endl;
        cout << "Codigo do Comissario: " << voo.getCodigoComissario() << endl;
        cout << "Origem: " << CYAN << voo.getOrigem() << RESET << " -> Destino: " << CYAN << voo.getDestino() << RESET << endl;
        cout << "Data: " << voo.getData() << " Hora: " << voo.getHora() << endl;
        cout << "Tarifa: R$" << voo.getTarifa() << endl;
        cout << "Assentos disponiveis: [" << voo.getAssentosDisponiveis() << "/" << voo.getAssentosTotais() << "]" << endl;
        cout << "---------------------------" << endl;
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