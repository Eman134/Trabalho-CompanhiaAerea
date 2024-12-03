#include <iostream>
#include <fstream>
#include "Voo.h"
#include "../controllers/AviaoController.h"

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
Voo::Voo(int numAssentos) : numAssentos(numAssentos) {
    for (int i = 1; i <= numAssentos; ++i) {
        assentos.emplace_back(i);
    }
}

Assento* Voo::getAssento(int numero) {
    if (numero < 1 || numero > numAssentos) {
        return nullptr;
    }
    return &assentos[numero - 1];
}

bool Voo::reservarAssento(int numero, Passageiro* passageiro) {
    if (numero < 1 || numero > numAssentos) {
        return false;
    }
    Assento* assento = getAssento(numero);
    if (assento && !assento->Ocupado()) {
        assento->reservar(passageiro);
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
    Aviao* aviao = aviaoController.buscarAviao(codigo_aviao);
    if (aviao) {
        qtd_assentos = aviao->getQtdAssentos();
    }
    return 0;
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

void Voo::salvar() {
    ofstream arquivo("./db/voos.bin", ios::binary | ios::app);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo para salvar os voos!" << endl;
        return;
    }

    arquivo.write((char*)&codigo_voo, sizeof(codigo_voo));
    arquivo.write((char*)&codigo_aviao, sizeof(codigo_aviao));
    arquivo.write((char*)&codigo_piloto, sizeof(codigo_piloto));
    arquivo.write((char*)&codigo_copiloto, sizeof(codigo_copiloto));
    arquivo.write((char*)&codigo_comissario, sizeof(codigo_comissario));

    size_t tamanhoData = data.size();
    arquivo.write((char*)&tamanhoData, sizeof(tamanhoData));
    arquivo.write(data.c_str(), tamanhoData);

    arquivo.write((char*)&hora, sizeof(hora));

    size_t tamanhoOrigem = origem.size();
    arquivo.write((char*)&tamanhoOrigem, sizeof(tamanhoOrigem));
    arquivo.write(origem.c_str(), tamanhoOrigem);

    size_t tamanhoDestino = destino.size();
    arquivo.write((char*)&tamanhoDestino, sizeof(tamanhoDestino));
    arquivo.write(destino.c_str(), tamanhoDestino);

    size_t tamanhoStatus = status.size();
    arquivo.write((char*)&tamanhoStatus, sizeof(tamanhoStatus));
    arquivo.write(status.c_str(), tamanhoStatus);

    arquivo.write((char*)&tarifa, sizeof(tarifa));
    arquivo.write((char*)&assentos_disponiveis, sizeof(assentos_disponiveis));

    arquivo.close();
}

void Voo::carregar()  {
    ifstream arquivo("./db/voos.bin", ios::binary);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo para carregar os voos!" << endl;
        return;
    }

    while (arquivo.read((char*)&codigo_voo, sizeof(codigo_voo))) {
        arquivo.read((char*)&codigo_aviao, sizeof(codigo_aviao));
        arquivo.read((char*)&codigo_piloto, sizeof(codigo_piloto));
        arquivo.read((char*)&codigo_copiloto, sizeof(codigo_copiloto));
        arquivo.read((char*)&codigo_comissario, sizeof(codigo_comissario));

        size_t tamanhoData;
        arquivo.read((char*)&tamanhoData, sizeof(tamanhoData));
        char* bufferData = new char[tamanhoData + 1];
        arquivo.read(bufferData, tamanhoData);
        bufferData[tamanhoData] = '\0';
        data = bufferData;
        delete[] bufferData;

        arquivo.read((char*)&hora, sizeof(hora));

        size_t tamanhoOrigem;
        arquivo.read((char*)&tamanhoOrigem, sizeof(tamanhoOrigem));
        char* bufferOrigem = new char[tamanhoOrigem + 1];
        arquivo.read(bufferOrigem, tamanhoOrigem);
        bufferOrigem[tamanhoOrigem] = '\0';
        origem = bufferOrigem;
        delete[] bufferOrigem;

        size_t tamanhoDestino;
        arquivo.read((char*)&tamanhoDestino, sizeof(tamanhoDestino));
        char* bufferDestino = new char[tamanhoDestino + 1];
        arquivo.read(bufferDestino, tamanhoDestino);
        bufferDestino[tamanhoDestino] = '\0';
        destino = bufferDestino;
        delete[] bufferDestino;

        size_t tamanhoStatus;
        arquivo.read((char*)&tamanhoStatus, sizeof(tamanhoStatus));
        char* bufferStatus = new char[tamanhoStatus + 1];
        arquivo.read(bufferStatus, tamanhoStatus);
        bufferStatus[tamanhoStatus] = '\0';
        status = bufferStatus;
        delete[] bufferStatus;

        arquivo.read((char*)&tarifa, sizeof(tarifa));
        arquivo.read((char*)&assentos_disponiveis, sizeof(assentos_disponiveis));
    }

    arquivo.close();
}
