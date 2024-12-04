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
        bool disponibilidade;

    public:
        Tripulacao();
        Tripulacao(int codigo, string nome, string cargo, string telefone, bool disponivel);

        int getCodigoTripulacao() const;
        string getNomeTripulacao() const;
        string getCargoTripulacao() const;
        string getTelefoneTripulacao() const;
        bool getDisponivel() const;

        void setCodigoTripulacao(int codigo);
        void setNomeTripulacao(string nome);
        void setCargoTripulacao(string cargo);
        void setTelefoneTripulacao(string telefone);
        void setdisponibilidade(bool disponivel);

        void salvar();
        void carregar();
};

#endif
