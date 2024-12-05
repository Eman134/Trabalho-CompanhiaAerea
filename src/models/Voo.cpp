#include <iostream>
#include <fstream>
#include <iomanip>
#include "Voo.h"
#include "Aviao.h"
#include "Assento.h"
#include <algorithm>
#include "../controllers/AviaoController.h"
#include "../../modulos/Passageiro.h"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

using namespace std;

Voo::Voo() {
    this->codigo_voo = 0;
    this->codigo_aviao = 0;
    this->codigo_piloto = 0;
    this->codigo_copiloto = 0;
    this->codigo_comissario = 0;
    this->data = "";
    this->hora = 0;
    this->origem = "";
    this->destino = "";
    this->status = "";
    this->tarifa = 0.0f;
    this->assentos_disponiveis = 0;
    this->numAssentos = 50;
}

int Voo::getCodigoVoo() const {
    return this->codigo_voo;
}

int Voo::getCodigoAviao() const {
    return this->codigo_aviao;
}

int Voo::getCodigoPiloto() const {
    return this->codigo_piloto;
}

int Voo::getCodigoCopiloto() const {
    return this->codigo_copiloto;
}

int Voo::getCodigoComissario() const {
    return this->codigo_comissario;
}

string Voo::getData() const {
    return this->data;
}

int Voo::getHora() const {
    return this->hora;
}

string Voo::getOrigem() const {
    return this->origem;
}

string Voo::getDestino() const {
    return this->destino;
}

string Voo::getStatus() const {
    return this->status;
}

float Voo::getTarifa() const {
    return this->tarifa;
}

Assento* Voo::getAssento(int numeroassento) {
    auto it = find_if(assentos.begin(), assentos.end(),
                      [numeroassento](const Assento& assento) { return assento.getNumero() == numeroassento; });
    if (it != assentos.end()) {
        return &(*it);
    }
    return nullptr;
}

vector<Assento> Voo::getAssentos() const {
    return assentos;
}

vector<Assento> Voo::getAssentosOcupados() const {
    vector<Assento> ocupados;
    for (const auto& assento : assentos) {
        if (assento.Ocupado()) {
            ocupados.push_back(assento);
        }
    }
    return ocupados;
}

void Voo::exibirTabelaAssentos(int linhas = 5, int colunas = 10) {
    cout << "Tabela de assentos (verde = disponivel, vermelho = ocupado):\n";

    cout << "   ";
    for (int j = 0; j < colunas; ++j) {
        cout << setw(4) << j + 1;
    }
    cout << endl;

    // pegar assentos ocupados
    vector<Assento> assentos = getAssentosOcupados();

    printf(assentos.size() > 0 ? "Assentos ocupados: %d\n" : "Nenhum assento ocupado.\n", assentos.size());

    for (int i = 0; i < linhas; ++i) {
        cout << setw(2) << char('A' + i) << " ";
        for (int j = 0; j < colunas; ++j) {
            int numeroAssento = i * colunas + j + 1;
            auto it = find_if(assentos.begin(), assentos.end(),
                              [numeroAssento](const Assento& assento) { return assento.getNumero() == numeroAssento; });
            if (it != assentos.end() && it->Ocupado()) {
                cout << RED << setw(4) << numeroAssento << RESET;
            } else {
                cout << GREEN << setw(4) << numeroAssento << RESET;
            }
        }
        cout << endl;
    }
    cout << endl;
}


bool Voo::reservarAssento(int numero, Passageiro* passageiro) {
    if (numero < 1 || numero > numAssentos) {
        return false;
    }
    Assento* assento;

    if (getAssento(numero)) {
        assento = getAssento(numero);
    } else {
        assento = new Assento(numero);
    }

    bool ocupado = assento->Ocupado();
    if (!ocupado) {
        assento->reservar(passageiro);
        setAssentosDisponiveis(getAssentosDisponiveis() - 1);
        assentos.push_back(*assento);
        printf("Assento %d reservado com sucesso.\n", numero);
        return true;
    }
    return false;
}

void Voo::liberarAssento(int numero) {
    if (numero < 1 || numero > numAssentos) {
        return;
    }
    Assento* assento = getAssento(numero);
    if (assento) {
        assento->liberar();
    }
}

void Voo::cadastrarAssento(int numero) {
    if (numero < 1 || numero > numAssentos) {
        std::cout << "Número de assento inválido." << std::endl;
        return;
    }
    assentos.emplace_back(numero);
    std::cout << "Assento " << numero << " cadastrado com sucesso." << std::endl;
}

int Voo::getAssentosDisponiveis() const {
    return this->assentos_disponiveis;
}

int Voo::getAssentosTotais() const {
    int qtd_assentos = 0;
    AviaoController aviaoController;
    Aviao* aviao = aviaoController.buscarAviao(getCodigoAviao());
    if (aviao) {
        qtd_assentos = aviao->getQtdAssentos();
    }
    return qtd_assentos;
}

void Voo::setCodigoVoo(int codigo_voo) {
    this->codigo_voo = codigo_voo;
}

void Voo::setCodigoAviao(int codigo_aviao) {
    this->codigo_aviao = codigo_aviao;
}

void Voo::setCodigoPiloto(int codigo_piloto) {
    this->codigo_piloto = codigo_piloto;
}

void Voo::setCodigoCopiloto(int codigo_copiloto) {
    this->codigo_copiloto = codigo_copiloto;
}

void Voo::setCodigoComissario(int codigo_comissario) {
    this->codigo_comissario = codigo_comissario;
}

void Voo::setData(const string& data) {
    this->data = data;
}

void Voo::setHora(int hora) {
    this->hora = hora;
}

void Voo::setOrigem(const string& origem) {
    this->origem = origem;
}

void Voo::setDestino(const string& destino) {
    this->destino = destino;
}

void Voo::setStatus(const string& status) {
    this->status = status;
}

void Voo::setTarifa(float tarifa) {
    this->tarifa = tarifa;
}

void Voo::setAssentosDisponiveis(int assentos_disponiveis) {
    this->assentos_disponiveis = assentos_disponiveis;
}

void Voo::salvar(ostream& out) const {

    out.write((char*)&codigo_voo, sizeof(codigo_voo));
    out.write((char*)&codigo_aviao, sizeof(codigo_aviao));
    out.write((char*)&codigo_piloto, sizeof(codigo_piloto));
    out.write((char*)&codigo_copiloto, sizeof(codigo_copiloto));
    out.write((char*)&codigo_comissario, sizeof(codigo_comissario));

    size_t tamanhoData = data.size();
    out.write((char*)&tamanhoData, sizeof(tamanhoData));
    out.write(data.c_str(), tamanhoData);

    out.write((char*)&hora, sizeof(hora));

    size_t tamanhoOrigem = origem.size();
    out.write((char*)&tamanhoOrigem, sizeof(tamanhoOrigem));
    out.write(origem.c_str(), tamanhoOrigem);

    size_t tamanhoDestino = destino.size();
    out.write((char*)&tamanhoDestino, sizeof(tamanhoDestino));
    out.write(destino.c_str(), tamanhoDestino);

    size_t tamanhoStatus = status.size();
    out.write((char*)&tamanhoStatus, sizeof(tamanhoStatus));
    out.write(status.c_str(), tamanhoStatus);

    out.write((char*)&tarifa, sizeof(tarifa));
    out.write((char*)&assentos_disponiveis, sizeof(assentos_disponiveis));

    // Salve os assentos
    int numAssentos = assentos.size();
    out.write((char*)&numAssentos, sizeof(numAssentos));

    for (const Assento& assento : assentos) {
        int numero = assento.getNumero();
        Passageiro* passageiro = assento.getPassageiro();
        bool ocupado = assento.Ocupado();
        out.write((char*)&numero, sizeof(numero));
        out.write((char*)&ocupado, sizeof(ocupado));
        if (ocupado) {
            int codigoPassageiro = passageiro->getCodigoPassageiro();
            out.write((char*)&codigoPassageiro, sizeof(codigoPassageiro));
        }
    }

}

void Voo::carregar(std::istream& in) {
    // Leia os dados básicos do voo
    in.read((char*)&codigo_voo, sizeof(codigo_voo));
    in.read((char*)&codigo_aviao, sizeof(codigo_aviao));
    in.read((char*)&codigo_piloto, sizeof(codigo_piloto));
    in.read((char*)&codigo_copiloto, sizeof(codigo_copiloto));
    in.read((char*)&codigo_comissario, sizeof(codigo_comissario));

    // Leia o tamanho e os dados da string `data`
    size_t tamanhoData;
    in.read((char*)&tamanhoData, sizeof(tamanhoData));
    char* bufferData = new char[tamanhoData + 1];
    in.read(bufferData, tamanhoData);
    bufferData[tamanhoData] = '\0';
    data = bufferData;
    delete[] bufferData;

    // Leia o campo `hora`
    in.read((char*)&hora, sizeof(hora));

    // Leia o tamanho e os dados da string `origem`
    size_t tamanhoOrigem;
    in.read((char*)&tamanhoOrigem, sizeof(tamanhoOrigem));
    char* bufferOrigem = new char[tamanhoOrigem + 1];
    in.read(bufferOrigem, tamanhoOrigem);
    bufferOrigem[tamanhoOrigem] = '\0';
    origem = bufferOrigem;
    delete[] bufferOrigem;

    // Leia o tamanho e os dados da string `destino`
    size_t tamanhoDestino;
    in.read((char*)&tamanhoDestino, sizeof(tamanhoDestino));
    char* bufferDestino = new char[tamanhoDestino + 1];
    in.read(bufferDestino, tamanhoDestino);
    bufferDestino[tamanhoDestino] = '\0';
    destino = bufferDestino;
    delete[] bufferDestino;

    // Leia o tamanho e os dados da string `status`
    size_t tamanhoStatus;
    in.read((char*)&tamanhoStatus, sizeof(tamanhoStatus));
    char* bufferStatus = new char[tamanhoStatus + 1];
    in.read(bufferStatus, tamanhoStatus);
    bufferStatus[tamanhoStatus] = '\0';
    status = bufferStatus;
    delete[] bufferStatus;

    // Leia os demais dados
    in.read((char*)&tarifa, sizeof(tarifa));
    in.read((char*)&assentos_disponiveis, sizeof(assentos_disponiveis));

    // Carregar os assentos
    int numAssentos;
    in.read((char*)&numAssentos, sizeof(numAssentos));
    assentos.clear();

    for (int i = 0; i < numAssentos; ++i) {
        int numero;
        bool ocupado;
        in.read((char*)&numero, sizeof(numero));
        in.read((char*)&ocupado, sizeof(ocupado));
        Passageiro* passageiro = nullptr;
        Assento assento(numero);
        if (ocupado) {
            int codigoPassageiro;
            in.read((char*)&codigoPassageiro, sizeof(codigoPassageiro));
            passageiro = Passageiro::buscarPassageiro(codigoPassageiro);
            assento.reservar(passageiro);
        }
        assentos.push_back(assento);
    }
}
