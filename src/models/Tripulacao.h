#ifndef TRIPULACAO_H
#define TRIPULACAO_H

#include <string>
using namespace std;

class Tripulacao {
    private:
        int codigoTripulacao;
        string nomeTripulacao;
        string cargoTripulacao;
        string telefoneTripulacao;
        bool disponivel;

    public:

        // Construtores da classe Tripulacao
        Tripulacao();
        Tripulacao(int codigo, string nome, string cargo, string telefone, bool disponivel);

        // Métodos para pegar as informações do tripulante
        int getCodigoTripulacao() const;
        string getNomeTripulacao() const;
        string getCargoTripulacao() const;
        string getTelefoneTripulacao() const;
        bool getDisponivel() const;

        // Métodos para setar as informações do tripulante
        void setCodigoTripulacao(int codigo);
        void setNomeTripulacao(string nome);
        void setCargoTripulacao(string cargo);
        void setTelefoneTripulacao(string telefone);
        void setDisponivel(bool disponivel);

        // Métodos para salvar e carregar os dados do tripulante
        void salvar();
        void carregar();
};

#endif
