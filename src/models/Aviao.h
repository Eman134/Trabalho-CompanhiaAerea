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
        // Construtores
        Aviao(int codigo_aviao, string nome_aviao, int qtd_assentos, bool disponivel);
        Aviao();

        // Métodos para pegar as informações do avião
        int getCodigoAviao() const;
        string getNomeAviao() const;
        int getQtdAssentos() const;
        bool getDisponivel() const;

        // Métodos para setar as informações do avião
        void setDisponibilidade(bool disponibilidade);
        void setCodigoAviao(int codigo_aviao);
        void setNomeAviao(const string& nome_aviao);
        void setQtdAssentos(int qtd_assentos);

        // Métodos para salvar e carregar os dados do avião
        void salvar(ostream& out) const;
        void carregar(istream& in);
};

#endif
