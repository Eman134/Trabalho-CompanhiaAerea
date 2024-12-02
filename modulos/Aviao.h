#ifndef AVIAO_H
#define AVIAO_H

#include <string>

using namespace std;

class Aviao {
    private:
        int codigo_aviao;
        string nome_aviao;
        int qtd_assentos;

    public:
        Aviao(int codigo_aviao, string nome_aviao, int qtd_assentos);
        Aviao();

        int getCodigoDisponivel();
        int getCodigoAviao();
        string getNomeAviao();
        int getQtdAssentos();

        void setCodigoAviao(int codigo_aviao);
        void setNomeAviao(string nome_aviao);
        void setQtdAssentos(int qtd_assentos);

        void salvar();
        void carregar();
        void visualizarAvioes();
        void cadastrarAviao();
};

#endif
