#include "PassageiroController.h"
#include "../models/Passageiro.h"
#include <iostream>
#include <vector>
#include <fstream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

using namespace std;

// Construtor padrão que inicializa a lista de passageiros
PassageiroController::PassageiroController() {
    carregarPassageiros();
}

// Função para verificar se já existe um passageiro com o mesmo código
bool PassageiroController::verificarDuplicidade(int codigo_passageiro) {
    for (const auto& passageiro : lista_passageiros) {
        if (passageiro.getCodigoPassageiro() == codigo_passageiro) {
            return true;
        }
    }
    return false;
}

// Função para cadastrar um novo passageiro
void PassageiroController::cadastrarPassageiro() {
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
void PassageiroController::salvarPassageiros() {
    ofstream arquivo("./db/passageiros.bin", ios::binary);
    for (const auto& passageiro : lista_passageiros) {
        int codigo_passageiro = passageiro.getCodigoPassageiro();
        string nome = passageiro.getNome();
        string endereco = passageiro.getEndereco();
        string telefone = passageiro.getTelefone();
        bool fidelidade = passageiro.isFidelidade();
        int pontos_fidelidade = passageiro.getPontosFidelidade();

        arquivo.write(reinterpret_cast<const char*>(&codigo_passageiro), sizeof(codigo_passageiro));
        size_t size = nome.size();
        arquivo.write(reinterpret_cast<const char*>(&size), sizeof(size));
        arquivo.write(nome.c_str(), size);
        size = endereco.size();
        arquivo.write(reinterpret_cast<const char*>(&size), sizeof(size));
        arquivo.write(endereco.c_str(), size);
        size = telefone.size();
        arquivo.write(reinterpret_cast<const char*>(&size), sizeof(size));
        arquivo.write(telefone.c_str(), size);
        arquivo.write(reinterpret_cast<const char*>(&fidelidade), sizeof(fidelidade));
        arquivo.write(reinterpret_cast<const char*>(&pontos_fidelidade), sizeof(pontos_fidelidade));
    }
    arquivo.close();
}

// Função para carregar a lista de passageiros de um arquivo binário
void PassageiroController::carregarPassageiros() {
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
Passageiro* PassageiroController::buscarPassageiro(int codigo_passageiro) {
    for (auto& passageiro : lista_passageiros) {
        if (passageiro.getCodigoPassageiro() == codigo_passageiro) {
            return &passageiro;
        }
    }
    return nullptr;
}

// Função para buscar um passageiro pelo nome
Passageiro* PassageiroController::buscarPassageiro(const string& nome) {
    for (auto& passageiro : lista_passageiros) {
        if (passageiro.getNome() == nome) {
            return &passageiro;
        }
    }
    return nullptr;
}

// Função para obter a lista de passageiros
vector<Passageiro> PassageiroController::getListaPassageiros() const {
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

// Função para pesquisar um passageiro
void PassageiroController::pesquisarPassageiro() {
    cout << YELLOW << "Digite o codigo ou o nome do passageiro para pesquisa: " << RESET << endl;
    string codigo;
    cin >> codigo;

    bool isNumero = true;
    for (char c : codigo) {
        if (!isdigit(c)) {
            isNumero = false;
            break;
        }
    }

    if (isNumero) {
        int numero = stoi(codigo);
        Passageiro* passageiro = buscarPassageiro(numero);
        if (passageiro) {
            cout << GREEN << "Passageiro encontrado: " << RESET << passageiro->getNome() << endl;
            cout << "Nome: " << passageiro->getNome() << endl;
            cout << "Codigo: " << passageiro->getCodigoPassageiro() << endl;
            cout << "Telefone: " << passageiro->getTelefone() << endl;
        } else {
            cout << RED << "Passageiro não encontrado." << RESET << endl;
        }
    } else {
        Passageiro* passageiro = buscarPassageiro(codigo);
        if (passageiro) {
            cout << GREEN << "Passageiro encontrado: " << RESET << passageiro->getNome() << endl;
            cout << "Nome: " << passageiro->getNome() << endl;
            cout << "Codigo: " << passageiro->getCodigoPassageiro() << endl;
            cout << "Telefone: " << passageiro->getTelefone() << endl;
        } else {
            cout << RED << "Passageiro não encontrado." << RESET << endl;
        }
    }
}