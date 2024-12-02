#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include <string>
#include <vector>

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

    int getCodigoPassageiro() const;
    std::string getNome() const;
    std::string getEndereco() const;
    std::string getTelefone() const;
    bool isFidelidade() const;
    int getPontosFidelidade() const;

    void setCodigoPassageiro(int codigo_passageiro);
    void setNome(std::string nome);
    void setEndereco(std::string endereco);
    void setTelefone(std::string telefone);
    void setFidelidade(bool fidelidade);
    void setPontosFidelidade(int pontos_fidelidade);

    static bool verificarDuplicidade(int codigo_passageiro);
    static void cadastrarPassageiro();
    static void salvarPassageiros();
    static void carregarPassageiros();
    static Passageiro* buscarPassageiro(int codigo_passageiro);
    static Passageiro* buscarPassageiro(const std::string& nome);
};

extern std::vector<Passageiro> lista_passageiros;

#endif // PASSAGEIRO_H