#include "Passageiro.h"
#include <iostream>
#include <vector>
#include <fstream>

std::vector<Passageiro> lista_passageiros;

// Construtor que inicializa um passageiro com os dados fornecidos
Passageiro::Passageiro(int codigo_passageiro, std::string nome, std::string endereco, std::string telefone, bool fidelidade, int pontos_fidelidade) {
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
std::string Passageiro::getNome() const { return this->nome; }
std::string Passageiro::getEndereco() const { return this->endereco; }
std::string Passageiro::getTelefone() const { return this->telefone; }
bool Passageiro::isFidelidade() const { return this->fidelidade; }
int Passageiro::getPontosFidelidade() const { return this->pontos_fidelidade; }

// Métodos setter para modificar os atributos privados de um passageiro
void Passageiro::setCodigoPassageiro(int codigo_passageiro) { this->codigo_passageiro = codigo_passageiro; }
void Passageiro::setNome(std::string nome) { this->nome = nome; }
void Passageiro::setEndereco(std::string endereco) { this->endereco = endereco; }
void Passageiro::setTelefone(std::string telefone) { this->telefone = telefone; }
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
    std::string nome;
    std::string endereco;
    std::string telefone;
    bool fidelidade;
    int pontos_fidelidade;

    std::cout << "Digite o código do passageiro: ";
    std::cin >> codigo_passageiro;

    // Verifica se o código já foi cadastrado
    if (verificarDuplicidade(codigo_passageiro)) {
        std::cout << "Erro: Passageiro com este código já existe!" << std::endl;
        return; 

    // Solicita dados do passageiro
    std::cout << "Digite o nome do passageiro: ";
    std::cin.ignore();
    std::getline(std::cin, nome);
    std::cout << "Digite o endereço do passageiro: ";
    std::getline(std::cin, endereco);
    std::cout << "Digite o telefone do passageiro: ";
    std::getline(std::cin, telefone);
    std::cout << "O passageiro possui fidelidade? (1 para sim, 0 para não): ";
    std::cin >> fidelidade;
    std::cout << "Digite os pontos de fidelidade do passageiro: ";
    std::cin >> pontos_fidelidade;

    // Cria um novo passageiro e adiciona na lista
    Passageiro novo_passageiro(codigo_passageiro, nome, endereco, telefone, fidelidade, pontos_fidelidade);
    lista_passageiros.push_back(novo_passageiro);

    // Chama a função para salvar os dados no arquivo
    salvarPassageiros();
    std::cout << "Passageiro cadastrado com sucesso!" << std::endl;
}

// Função para salvar a lista de passageiros em um arquivo
void Passageiro::salvarPassageiros() {
    std::ofstream arquivo("passageiros.txt");
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
    std::ifstream arquivo("passageiros.txt");
    if (!arquivo.is_open()) return; 

    int codigo_passageiro;
    std::string nome;
    std::string endereco;
    std::string telefone;
    bool fidelidade;
    int pontos_fidelidade;

    // Lê os dados do arquivo e adiciona na lista
    while (arquivo >> codigo_passageiro) {
        arquivo.ignore();
        std::getline(arquivo, nome);
        std::getline(arquivo, endereco);
        std::getline(arquivo, telefone);
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
Passageiro* Passageiro::buscarPassageiro(const std::string& nome) {
    for (auto& passageiro : lista_passageiros) {
        if (passageiro.getNome() == nome) {
            return &passageiro; 
        }
    }
    return nullptr; 
}