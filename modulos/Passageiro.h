#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include <string>

class Passageiro {
private:
    int codigo_passageiro;
    std::string nome;
    std::string endereco;
    std::string telefone;
    bool fidelidade;
    int pontos_fidelidade;
    
public:
    Passageiro(int codigo_passageiro, std::string nome, std::string endereco, std::string telefone, bool fidelidade, int pontos_fidelidade);
    Passageiro();

    int getCodigoPassageiro();
    std::string getNome();
    std::string getEndereco();
    std::string getTelefone();
    bool isFidelidade();
    int getPontosFidelidade();

    void setCodigoPassageiro(int codigo_passageiro);
    void setNome(std::string nome);
    void setEndereco(std::string endereco);
    void setTelefone(std::string telefone);
    void setFidelidade(bool fidelidade);
    void setPontosFidelidade(int pontos_fidelidade);
    void cadastrarPassageiro();
};
#endif