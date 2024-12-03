#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H
#include <string>
#include <vector>

using namespace std;
// Classe Passageiro
class Passageiro {
private:
    int codigo_passageiro;      
    string nome;       
    string endereco;
    string telefone;
    bool fidelidade;         
    int pontos_fidelidade;
public:
    // Construtor com parâmetros para inicializar todos os atributos
    Passageiro(int codigo_passageiro, string nome, string endereco, string telefone, bool fidelidade, int pontos_fidelidade);
    
    // Construtor padrão, que inicializa os atributos com valores padrão
    Passageiro();

    // Métodos getter para acessar os atributos da classe:
    int getCodigoPassageiro() const;  
    string getNome() const;      
    string getEndereco() const;  
    string getTelefone() const;  
    bool isFidelidade() const;        
    int getPontosFidelidade() const;

    // Métodos setter para modificar os atributos da classe:
    void setCodigoPassageiro(int codigo_passageiro);  
    void setNome(string nome);                    
    void setEndereco(string endereco);            
    void setTelefone(string telefone);            
    void setFidelidade(bool fidelidade);               
    void setPontosFidelidade(int pontos_fidelidade);

    // Métodos estáticos para operações com a lista de passageiros:
    static bool verificarDuplicidade(int codigo_passageiro);
    static void cadastrarPassageiro();
    static void salvarPassageiros();
    static void carregarPassageiros();
    static Passageiro* buscarPassageiro(int codigo_passageiro);
    static Passageiro* buscarPassageiro(const string& nome);
};

// Declaração da lista de passageiros como uma variável global
extern vector<Passageiro> lista_passageiros;

#endif // PASSAGEIRO_H