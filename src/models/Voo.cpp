#include <iostream>
#include <fstream>
#include <iomanip>
#include "Voo.h"
#include "Aviao.h"
#include "Assento.h"
#include "Passageiro.h"
#include <algorithm>
#include "../controllers/AviaoController.h"
#include "../controllers/PassageiroController.h"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

using namespace std;

// Construtor da classe Voo
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

// Pegar o código do voo
int Voo::getCodigoVoo() const {
    return this->codigo_voo;
}

// Pegar o código do avião
int Voo::getCodigoAviao() const {
    return this->codigo_aviao;
}

// Pegar o código do piloto
int Voo::getCodigoPiloto() const {
    return this->codigo_piloto;
}

// Pegar o código do copiloto
int Voo::getCodigoCopiloto() const {
    return this->codigo_copiloto;
}

// Pegar o código do comissário
int Voo::getCodigoComissario() const {
    return this->codigo_comissario;
}

// Pegar a data
string Voo::getData() const {
    return this->data;
}

// Pegar a hora
int Voo::getHora() const {
    return this->hora;
}

// Pegar a origem
string Voo::getOrigem() const {
    return this->origem;
}

// Pegar o destino
string Voo::getDestino() const {
    return this->destino;
}

// Pegar o status
string Voo::getStatus() const {
    return this->status;
}

// Pegar a tarifa
float Voo::getTarifa() const {
    return this->tarifa;
}

// Pega a quantidade de assentos disponíveis
int Voo::getAssentosDisponiveis() const {
    return this->assentos_disponiveis;
}

// Pega a quantidade de assentos totais
int Voo::getAssentosTotais() const {
    int qtd_assentos = 0;
    AviaoController aviaoController;
    Aviao* aviao = aviaoController.buscarAviao(getCodigoAviao());
    if (aviao) {
        qtd_assentos = aviao->getQtdAssentos();
    }
    return qtd_assentos;
}

// Setar o código do voo
void Voo::setCodigoVoo(int codigo_voo) {
    this->codigo_voo = codigo_voo;
}

// Setar o código do avião
void Voo::setCodigoAviao(int codigo_aviao) {
    this->codigo_aviao = codigo_aviao;
}

// Setar o código do piloto
void Voo::setCodigoPiloto(int codigo_piloto) {
    this->codigo_piloto = codigo_piloto;
}

// Setar o código do copiloto
void Voo::setCodigoCopiloto(int codigo_copiloto) {
    this->codigo_copiloto = codigo_copiloto;
}

// Setar o código do comissário
void Voo::setCodigoComissario(int codigo_comissario) {
    this->codigo_comissario = codigo_comissario;
}

// Setar a data
void Voo::setData(const string& data) {
    this->data = data;
}

// Setar a hora
void Voo::setHora(int hora) {
    this->hora = hora;
}

// Setar a origem
void Voo::setOrigem(const string& origem) {
    this->origem = origem;
}

// Setar o destino
void Voo::setDestino(const string& destino) {
    this->destino = destino;
}

// Setar o status
void Voo::setStatus(const string& status) {
    this->status = status;
}

// Setar a tarifa
void Voo::setTarifa(float tarifa) {
    this->tarifa = tarifa;
}

// Setar a quantidade de assentos disponíveis
void Voo::setAssentosDisponiveis(int assentos_disponiveis) {
    this->assentos_disponiveis = assentos_disponiveis;
}

// Método para salvar os dados do voo
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
        bool ocupado = true;
        out.write((char*)&numero, sizeof(numero));
        out.write((char*)&ocupado, sizeof(ocupado));
        if (ocupado) {
            int codigoPassageiro = passageiro->getCodigoPassageiro();
            out.write((char*)&codigoPassageiro, sizeof(codigoPassageiro));
        }
    }

}

// Método para carregar os dados do voo
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
    PassageiroController* passageiroController = new PassageiroController();

    for (int i = 0; i < numAssentos; ++i) {
        int numero;
        bool ocupado;
        in.read((char*)&numero, sizeof(numero));
        in.read((char*)&ocupado, sizeof(ocupado));
        Assento assento(numero);
        if (ocupado) {
            int codigoPassageiro;
            in.read((char*)&codigoPassageiro, sizeof(codigoPassageiro));
            Passageiro* passageiro = passageiroController->buscarPassageiro(codigoPassageiro);
            assento.reservar(passageiro);
        }
        assentos.push_back(assento);
    }

}
