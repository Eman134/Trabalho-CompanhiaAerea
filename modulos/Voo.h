#ifndef VOO_H
#define VOO_H

#include <string>

using namespace std;

class Voo {
    private:
        int codigo_voo;
        int codigo_aviao;
        int codigo_piloto;
        int codigo_copiloto;
        int codigo_comissario;
        string data;
        int hora;
        string origem;
        string destino;
        string status;
        float tarifa;
        int assentos_disponiveis;
    public:
        void cadastrarVoo();
};

#endif
