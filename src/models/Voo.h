#ifndef VOO_H
#define VOO_H

#include <string>
#include <vector>
#include "Assento.h"
#include "../../modulos/Passageiro.h"

using namespace std;

// Classe voo
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
        vector<Assento> assentos;
        int numAssentos;
    public:
        Voo();
        int getCodigoVoo() const;
        int getCodigoAviao() const;
        int getCodigoPiloto() const;
        int getCodigoCopiloto() const;
        int getCodigoComissario() const;
        string getData() const;
        int getHora() const;
        string getOrigem() const;
        string getDestino() const;
        string getStatus() const;
        float getTarifa() const;
        int getAssentosDisponiveis() const;
        int getAssentosTotais() const;
        Assento* getAssento(int numero);
        vector<Assento> getAssentos() const;
        vector<Assento> getAssentosOcupados() const;
        void exibirTabelaAssentos(int linhas, int colunas);
        bool reservarAssento(int numero, Passageiro* passageiro);
        void liberarAssento(int numero);
        void cadastrarAssento(int numero); // Adicionando a função de cadastrar assento

        void setCodigoVoo(int codigo_voo);
        void setCodigoAviao(int codigo_aviao);
        void setCodigoPiloto(int codigo_piloto);
        void setCodigoCopiloto(int codigo_copiloto);
        void setCodigoComissario(int codigo_comissario);
        void setData(const string& data);
        void setHora(int hora);
        void setOrigem(const string& origem);
        void setDestino(const string& destino);
        void setStatus(const string& status);
        void setTarifa(float tarifa);
        void setAssentosDisponiveis(int assentos_disponiveis);

        void salvar(ostream& out) const;
        void carregar(istream& in);
};

#endif
