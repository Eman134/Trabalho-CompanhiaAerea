#ifndef AVIAO_H
#define AVIAO_H

#include <string>
#include <iostream>

using namespace std;

class Aviao {
    private:
        int codigo_aviao;
        string nome_aviao;
        int qtd_assentos;
        bool disponivel;

    public:
        Aviao(int codigo_aviao, string nome_aviao, int qtd_assentos);
        Aviao();

        int getCodigoAviao() const;
        string getNomeAviao() const;
        int getQtdAssentos() const;
        bool getDisponivel() const;

        void setCodigoAviao(int codigo_aviao);
        void setNomeAviao(const string& nome_aviao);
        void setQtdAssentos(int qtd_assentos);

        void salvar(ostream& out) const;
        void carregar(istream& in);
};

#endif
