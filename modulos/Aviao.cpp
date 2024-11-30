#include "Aviao.h"
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#ifdef _WIN32
    #include <direct.h>
#endif

using namespace std;

Aviao::Aviao(int codigo_aviao, string nome_aviao, int qtd_assentos) {
    this->codigo_aviao = codigo_aviao;
    this->nome_aviao = nome_aviao;
    this->qtd_assentos = qtd_assentos;
}

Aviao::Aviao() {
    this->codigo_aviao = 0;
    this->nome_aviao = "";
    this->qtd_assentos = 0;
}

int Aviao::getCodigoAviao() {
    return this->codigo_aviao;
}

string Aviao::getNomeAviao() {
    return this->nome_aviao;
}

int Aviao::getQtdAssentos() {
    return this->qtd_assentos;
}

void Aviao::setCodigoAviao(int codigo_aviao) {
    this->codigo_aviao = codigo_aviao;
}

void Aviao::setNomeAviao(string nome_aviao) {
    this->nome_aviao = nome_aviao;
}

void Aviao::setQtdAssentos(int qtd_assentos) {
    this->qtd_assentos = qtd_assentos;
}

void criarDiretorioLocal() {
    #ifdef _WIN32
        if (_mkdir("./db") != 0) {
            if (errno != EEXIST) {
                cerr << "Erro ao criar diretório 'db'!" << endl;
            }
        }
    #else
        if (mkdir("./db", 0777) != 0) {
            if (errno != EEXIST) {
                cerr << "Erro ao criar diretório 'db'!" << endl;
            }
        }
    #endif
}

void Aviao::salvar() {
    criarDiretorioLocal();
    ofstream arquivo("./db/avioes.bin", ios::binary | ios::app);
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo para salvar!" << endl;
        return;
    }

    arquivo.write((char*)&codigo_aviao, sizeof(codigo_aviao));

    size_t tamanhoNome = nome_aviao.size();
    arquivo.write((char*)&tamanhoNome, sizeof(tamanhoNome));
    arquivo.write(nome_aviao.c_str(), tamanhoNome);

    arquivo.write((char*)&qtd_assentos, sizeof(qtd_assentos));
    arquivo.close();

    cout << "Avião salvo no arquivo binário!" << endl;
}


void Aviao::carregar() {
    ifstream arquivo("./db/avioes.bin", ios::binary);
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo para carregar!" << endl;
        return;
    }

    while (arquivo.read((char*)&codigo_aviao, sizeof(codigo_aviao))) {
        size_t tamanhoNome;
        arquivo.read((char*)&tamanhoNome, sizeof(tamanhoNome));

        char* buffer = new char[tamanhoNome + 1];
        arquivo.read(buffer, tamanhoNome);
        buffer[tamanhoNome] = '\0';
        nome_aviao = buffer;
        delete[] buffer;

        arquivo.read((char*)&qtd_assentos, sizeof(qtd_assentos));

        cout << "Código do avião: " << codigo_aviao << endl;
        cout << "Nome do avião: " << nome_aviao << endl;
        cout << "Quantidade de assentos: " << qtd_assentos << endl;
        cout << "----------------------------" << endl;
    }

    arquivo.close();
}

void Aviao::cadastrarAviao() {
    int codigo;
    string nome;
    int qtdAssentos;

    cout << "Digite o código do avião: ";
    cin >> codigo;
    cout << "Digite o nome do avião: ";
    cin.ignore();
    getline(cin, nome);
    cout << "Digite a quantidade de assentos: ";
    cin >> qtdAssentos;

    Aviao aviao(codigo, nome, qtdAssentos);
    aviao.salvar();

    cout << "Avião cadastrado com sucesso!" << endl;
}

void Aviao::visualizarAvioes() {
    cout << "Aviões cadastrados no sistema:" << endl;
    this->carregar();
}
