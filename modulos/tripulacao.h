#ifndef TRIPULACAO_H
#define TRIPULACAO_H

#include <string>
using namespace std;

class tripulacao {
    private:
        int codigoTripulacao;
        string nomeTripulacao;
        string cargoTripulacao;
        string telefoneTripulacao;

    public:
        tripulacao(int codigo, string nome, string cargo, string telefone);

        int getCodigoTripulacao() const;
        string getNomeTripulacao() const;
        string getCargoTripulacao() const;
        string getTelefoneTripulacao() const;

        void setCodigoTripulacao(int codigo);
        void setNomeTripulacao(string nome);
        void setCargoTripulacao(string cargo);
        void setTelefoneTripulacao(string telefone);

        void salvar();
        void carregar();
};

#endif
