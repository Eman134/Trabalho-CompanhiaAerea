#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H
#include <string>
#include <vector>

// Classe Passageiro
class Passageiro {
private:
    int codigo_passageiro;      
    std::string nome;           
    std::string endereco;      
    std::string telefone;       
    bool fidelidade;         
    int pontos_fidelidade;
public:
     // Construtor com parâmetros para inicializar todos os atributos
    Passageiro(int codigo_passageiro, std::string nome, std::string endereco, std::string telefone, bool fidelidade, int pontos_fidelidade);
    
    // Construtor padrão, que inicializa os atributos com valores padrão
    Passageiro();

    // Métodos getter para acessar os atributos da classe:
    int getCodigoPassageiro() const;  
    std::string getNome() const;      
    std::string getEndereco() const;  
    std::string getTelefone() const;  
    bool isFidelidade() const;        
    int getPontosFidelidade() const;

    // Métodos setter para modificar os atributos da classe:
    void setCodigoPassageiro(int codigo_passageiro);  
    void setNome(std::string nome);                    
    void setEndereco(std::string endereco);            
    void setTelefone(std::string telefone);            
    void setFidelidade(bool fidelidade);               
    void setPontosFidelidade(int pontos_fidelidade); 

    // Métodos estáticos da classe, utilizados para manipulação de múltiplos passageiros:
    static bool verificarDuplicidade(int codigo_passageiro);  
    static void cadastrarPassageiro(); 
    static void salvarPassageiros(); 
    static void carregarPassageiros();
    static Passageiro* buscarPassageiro(int codigo_passageiro);  
    static Passageiro* buscarPassageiro(const std::string& nome);
};
// Declaração de uma variável global que representa a lista de passageiros
extern std::vector<Passageiro> lista_passageiros;
#endif 
