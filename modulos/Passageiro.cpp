#include "Passageiro.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<Passageiro> lista_passageiros;

// Construtor que inicializa um passageiro com os dados fornecidos
Passageiro::Passageiro(int codigo_passageiro, string nome, string endereco, string telefone, bool fidelidade, int pontos_fidelidade) {
    this->codigo_passageiro = codigo_passageiro;
    this->nome = nome;
    this->endereco = endereco;
    this->telefone = telefone;
    this->fidelidade = fidelidade;
    this->pontos_fidelidade = pontos_fidelidade;
    carregarPassageiros();
}

// Construtor padrão que inicializa um passageiro com valores padrão
Passageiro::Passageiro() {
    this->codigo_passageiro = 0;
    this->nome = "";
    this->endereco = "";
    this->telefone = "";
    this->fidelidade = false;
    this->pontos_fidelidade = 0;
    carregarPassageiros();
}

// Métodos getter para acessar os atributos privados de um passageiro
int Passageiro::getCodigoPassageiro() const { return this->codigo_passageiro; }
string Passageiro::getNome() const { return this->nome; }
string Passageiro::getEndereco() const { return this->endereco; }
string Passageiro::getTelefone() const { return this->telefone; }
bool Passageiro::isFidelidade() const { return this->fidelidade; }
int Passageiro::getPontosFidelidade() const { return this->pontos_fidelidade; }

// Métodos setter para modificar os atributos privados de um passageiro
void Passageiro::setCodigoPassageiro(int codigo_passageiro) { this->codigo_passageiro = codigo_passageiro; }
void Passageiro::setNome(string nome) { this->nome = nome; }
void Passageiro::setEndereco(string endereco) { this->endereco = endereco; }
void Passageiro::setTelefone(string telefone) { this->telefone = telefone; }
void Passageiro::setFidelidade(bool fidelidade) { this->fidelidade = fidelidade; }
void Passageiro::setPontosFidelidade(int pontos_fidelidade) { this->pontos_fidelidade = pontos_fidelidade; }

bool Passageiro::verificarDuplicidade(int codigo_passageiro) {
    for (const auto& passageiro : lista_passageiros) {
        if (passageiro.getCodigoPassageiro() == codigo_passageiro) {
            return true;
        }
    }
    return false;
}

void Passageiro::cadastrarPassageiro() {
    int codigo_passageiro;
    string nome;
    string endereco;
    string telefone;
    bool fidelidade;
    int pontos_fidelidade;

    cout << "Digite o codigo do passageiro: ";
    cin >> codigo_passageiro;

    if (verificarDuplicidade(codigo_passageiro)) {
        cout << "Erro: Passageiro com este codigo já existe!" << endl;
        return;
    }

    cout << "Digite o nome do passageiro: ";
    cin.ignore();
    getline(cin, nome);
    cout << "Digite o endereço do passageiro: ";
    getline(cin, endereco);
    cout << "Digite o telefone do passageiro: ";
    getline(cin, telefone);
    cout << "O passageiro possui fidelidade? (1 para sim, 0 para não): ";
    cin >> fidelidade;
    cout << "Digite os pontos de fidelidade do passageiro: ";
    cin >> pontos_fidelidade;

    Passageiro novo_passageiro(codigo_passageiro, nome, endereco, telefone, fidelidade, pontos_fidelidade);
    lista_passageiros.push_back(novo_passageiro);
    salvarPassageiros();
    cout << "Passageiro cadastrado com sucesso!" << endl;
}

// Função para salvar a lista de passageiros em um arquivo binário
void Passageiro::salvarPassageiros() {
    ofstream arquivo("./db/passageiros.bin", ios::binary);
    for (const auto& passageiro : lista_passageiros) {
        arquivo.write(reinterpret_cast<const char*>(&passageiro.codigo_passageiro), sizeof(passageiro.codigo_passageiro));
        size_t size = passageiro.nome.size();
        arquivo.write(reinterpret_cast<const char*>(&size), sizeof(size));
        arquivo.write(passageiro.nome.c_str(), size);
        size = passageiro.endereco.size();
        arquivo.write(reinterpret_cast<const char*>(&size), sizeof(size));
        arquivo.write(passageiro.endereco.c_str(), size);
        size = passageiro.telefone.size();
        arquivo.write(reinterpret_cast<const char*>(&size), sizeof(size));
        arquivo.write(passageiro.telefone.c_str(), size);
        arquivo.write(reinterpret_cast<const char*>(&passageiro.fidelidade), sizeof(passageiro.fidelidade));
        arquivo.write(reinterpret_cast<const char*>(&passageiro.pontos_fidelidade), sizeof(passageiro.pontos_fidelidade));
    }
    arquivo.close();
}

// Função para carregar a lista de passageiros de um arquivo binário
void Passageiro::carregarPassageiros() {
    ifstream arquivo("./db/passageiros.bin", ios::binary);
    if (!arquivo.is_open()) return;

    lista_passageiros.clear();

    int codigo_passageiro;
    string nome;
    string endereco;
    string telefone;
    bool fidelidade;
    int pontos_fidelidade;

    // Lê os dados do arquivo e adiciona na lista
    while (arquivo.read(reinterpret_cast<char*>(&codigo_passageiro), sizeof(codigo_passageiro))) {
        size_t size;
        arquivo.read(reinterpret_cast<char*>(&size), sizeof(size));
        nome.resize(size);
        arquivo.read(&nome[0], size);
        arquivo.read(reinterpret_cast<char*>(&size), sizeof(size));
        endereco.resize(size);
        arquivo.read(&endereco[0], size);
        arquivo.read(reinterpret_cast<char*>(&size), sizeof(size));
        telefone.resize(size);
        arquivo.read(&telefone[0], size);
        arquivo.read(reinterpret_cast<char*>(&fidelidade), sizeof(fidelidade));
        arquivo.read(reinterpret_cast<char*>(&pontos_fidelidade), sizeof(pontos_fidelidade));

        // Cria um objeto Passageiro e adiciona na lista
        Passageiro passageiro(codigo_passageiro, nome, endereco, telefone, fidelidade, pontos_fidelidade);
        lista_passageiros.push_back(passageiro);
    }
    arquivo.close();
}

// Função para buscar um passageiro pelo código
Passageiro* Passageiro::buscarPassageiro(int codigo_passageiro) {
    for (auto& passageiro : lista_passageiros) {
        if (passageiro.getCodigoPassageiro() == codigo_passageiro) {
            return &passageiro;
        }
    }
    return nullptr;
}

// Função para buscar um passageiro pelo nome
Passageiro* Passageiro::buscarPassageiro(const string& nome) {
    for (auto& passageiro : lista_passageiros) {
        if (passageiro.getNome() == nome) {
            return &passageiro;
        }
    }
    return nullptr;
}

vector<Passageiro> Passageiro::getListaPassageiros() const {
    vector<Passageiro> lista_passageiros_temp = lista_passageiros;
    for (int i = 0; i < lista_passageiros_temp.size(); i++) {
        for (int j = i + 1; j < lista_passageiros_temp.size(); j++) {
            if (lista_passageiros_temp[i].getCodigoPassageiro() == lista_passageiros_temp[j].getCodigoPassageiro()) {
                lista_passageiros_temp.erase(lista_passageiros_temp.begin() + j);
                j--;
            }
        }
    }
    return lista_passageiros_temp;
}
