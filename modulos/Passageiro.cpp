#include "Passageiro.h"
#include <iostream>
#include <vector>
#include <fstream>

vector<Passageiro> lista_passageiros;

using namespace std;

// Construtor que inicializa um passageiro com os dados fornecidos
Passageiro::Passageiro(int codigo_passageiro, string nome, string endereco, string telefone, bool fidelidade, int pontos_fidelidade) {
    this->codigo_passageiro = codigo_passageiro;
    this->nome = nome;
    this->endereco = endereco;
    this->telefone = telefone;
    this->fidelidade = fidelidade;
    this->pontos_fidelidade = pontos_fidelidade;
}

// Construtor padrão que inicializa um passageiro com valores padrão
Passageiro::Passageiro() {
    this->codigo_passageiro = 0;
    this->nome = "";
    this->endereco = "";
    this->telefone = "";
    this->fidelidade = false;
    this->pontos_fidelidade = 0;
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

// Função para verificar se já existe um passageiro com o mesmo código
bool Passageiro::verificarDuplicidade(int codigo_passageiro) {
    for (const auto& passageiro : lista_passageiros) {
        if (passageiro.getCodigoPassageiro() == codigo_passageiro) {
            return true; 
        }
    }
    return false; 
}

// Função para cadastrar um novo passageiro
void Passageiro::cadastrarPassageiro() {
    int codigo_passageiro;
    string nome;
    string endereco;
    string telefone;
    bool fidelidade;
    int pontos_fidelidade;

    cout << "Digite o código do passageiro: ";
    cin >> codigo_passageiro;

    // Verifica se o código já foi cadastrado
    if (verificarDuplicidade(codigo_passageiro)) {
        cout << "Erro: Passageiro com este código já existe!" << endl;
        return; 
    }
    // Solicita dados do passageiro
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

    // Cria um novo passageiro e adiciona na lista
    Passageiro novo_passageiro(codigo_passageiro, nome, endereco, telefone, fidelidade, pontos_fidelidade);
    lista_passageiros.push_back(novo_passageiro);

    // Chama a função para salvar os dados no arquivo
    salvarPassageiros();
    cout << "Passageiro cadastrado com sucesso!" << endl;
}

// Função para salvar a lista de passageiros em um arquivo
void Passageiro::salvarPassageiros() {
    ofstream arquivo("passageiros.txt");
    for (const auto& passageiro : lista_passageiros) {
        arquivo << passageiro.getCodigoPassageiro() << "\n"
                << passageiro.getNome() << "\n"
                << passageiro.getEndereco() << "\n"
                << passageiro.getTelefone() << "\n"
                << passageiro.isFidelidade() << "\n"
                << passageiro.getPontosFidelidade() << "\n";
    }
    arquivo.close(); 
}

// Função para carregar a lista de passageiros de um arquivo
void Passageiro::carregarPassageiros() {
    ifstream arquivo("passageiros.txt");
    if (!arquivo.is_open()) return; 

    int codigo_passageiro;
    string nome;
    string endereco;
    string telefone;
    bool fidelidade;
    int pontos_fidelidade;

    // Lê os dados do arquivo e adiciona na lista
    while (arquivo >> codigo_passageiro) {
        arquivo.ignore();
        getline(arquivo, nome);
        getline(arquivo, endereco);
        getline(arquivo, telefone);
        arquivo >> fidelidade;
        arquivo >> pontos_fidelidade;
        
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