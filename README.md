
# Trabalho-CompanhiaAerea

[Repositório no GitHub](https://github.com/Eman134/Trabalho-CompanhiaAerea)

## Autores

- **Kayke Emanoel** - [Eman134](https://github.com/Eman134)
- **Rafael Brant** - [rafaelbrant07](https://github.com/rafaelbrant07)
- **Carlos Eduardo** - [Cadu-santos32](https://github.com/Cadu-santos32)

## Sobre o projeto

O projeto é uma aplicação de uma companhia aérea fictícia, onde é possível realizar a compra de passagens aéreas, visualizar os voos disponíveis, visualizar os voos já comprados e realizar o check-in.

**OBS:** O projeto foi desenvolvido para a disciplina de Programação Orientada a Objetos, do curso de Engenharia de Software da PUC Minas.

## Como Executar?

Para executar o projeto, basta clonar o repositório e executar o arquivo `TrabalhoCompanhiaAerea.exe`, localizado na pasta principal do projeto. 

Se preferir, você pode compilar o projeto com `g++` ou outro compilador de sua preferência.

## Como compilar o projeto?

### Pré-requisitos:
- **g++** instalado ou qualquer outro compilador C++.
- No **Windows**, é recomendado o uso do MinGW ou WSL (Windows Subsystem for Linux) para compilar.
- No **Linux/macOS**, o `g++` pode ser instalado facilmente via gerenciador de pacotes.

### Passos para compilar:

1. Clone o repositório:

    ```bash
    git clone https://github.com/Eman134/Trabalho-CompanhiaAerea.git
    cd Trabalho-CompanhiaAerea
    ```

2. Compile o projeto com o seguinte comando:

    ```bash
    g++ main.cpp src/*/*.cpp -o TrabalhoCompanhiaAerea
    ```

3. Após compilar, execute o programa gerado (no Windows, será um arquivo `TrabalhoCompanhiaAerea.exe`):

    ```bash
    ./TrabalhoCompanhiaAerea
    ```

## Como Utilizar?

Após a execução do programa, o sistema irá exibir um menu com várias opções de interação. O usuário pode:

1. **Cadastrar avião** – Registrar novos aviões no sistema.
2. **Visualizar aviões** – Exibir a lista de aviões cadastrados.
3. **Cadastrar tripulação** – Registrar os membros da tripulação de cada voo.
4. **Visualizar tripulações** – Exibir a lista de tripulações cadastradas.
5. **Cadastrar passageiro** – Registrar os passageiros que vão realizar viagens.
6. **Cadastrar voo** – Registrar novos voos no sistema.
7. **Visualizar voos** – Registrar novos voos no sistema.
8. **Fazer reserva** – Permitir ao passageiro reservar um assento em um voo.
9. **Baixa reserva** – Cancelar a reserva feita anteriormente.
10. **Pesquisa** – Realizar pesquisas de voos, passageiros ou outros itens.
11. **Fidelidade** – Gerenciar o programa de pontos de fidelidade dos passageiros.
12. **Sair** – Encerrar o programa.

Ao selecionar uma opção, o programa vai executar a ação correspondente e, ao final, perguntará se o usuário deseja voltar ao menu inicial digitando `RETORNAR`.

## Funcionalidades

- **Cadastro de Aviões**: O sistema permite que novos aviões sejam cadastrados com um código único, nome e quantidade de assentos.
- **Cadastro de Tripulação**: Você pode cadastrar os membros da tripulação que irão operar os voos.
- **Cadastro de Passageiros**: A cada novo voo, os passageiros podem ser registrados.
- **Reserva de Assentos**: Os passageiros podem realizar a reserva de seus assentos, garantindo que consigam viajar.
- **Check-in**: Ao realizar o check-in, os passageiros confirmam sua presença no voo e podem embarcar.
- **Pesquisa e Gestão de Dados**: O sistema oferece funções para pesquisar e visualizar voos, passageiros e outros dados relevantes.

## Layout

O layout do sistema é textual, utilizando menus simples de navegação no console. O usuário interage por meio da digitação de números para selecionar as opções desejadas, e o programa exibe informações no formato de texto para as operações realizadas.

### Exemplos de interação com o sistema:

Menu principal do sistema:

```text
1 - Cadastrar avião
2 - Visualizar aviões
3 - Cadastrar tripulação
4 - Visualizar tripulações
5 - Cadastrar passageiro
6 - Pesquisar passageiros
7 - Cadastrar voo
8 - Visualizar voos
9 - Fazer reserva
10 - Baixa reserva
11 - Fidelidade
12 - Sair

Digite a opção desejada:
```

Sistema de retorno ao menu principal:

```text
Caso deseje voltar ao menu inicial, digite 'R': 
```

O usuário pode então digitar o número correspondente à operação que deseja realizar. Após concluir a ação, o programa oferece a opção de retornar ao menu principal.

## Modelo Conceitual

A aplicação utiliza um modelo de dados orientado a objetos para representar os principais elementos do sistema. Os objetos são:

- **Avião**: Representa um avião, com informações como código, nome e quantidade de assentos.
- **Tripulação**: Representa a equipe responsável por um voo específico.
- **Passageiro**: Armazena informações dos passageiros, como nome, número de passagens e status de check-in.
- **Voo**: Representa os voos disponíveis, com informações sobre o avião, origem, destino e horários.

Cada um desses objetos tem métodos para manipulação dos dados, como cadastro, visualização e exclusão.

## Tecnologias Utilizadas

- **C++**: Linguagem de programação utilizada para a implementação do sistema.
- **g++**: Compilador utilizado para compilar o código-fonte em C++.
- **STL (Standard Template Library)**: Utilizada para manipulação de dados, como vetores e strings.
- **Arquivos binários**: Os dados são salvos em arquivos binários para persistência.

As funções descritas nas classes AviaoController, PassageiroController, TripulacaoController, VooController, e ReservaController são responsáveis pela manipulação dos dados associados a seus respectivos modelos (como Aviao, Passageiro, Tripulacao, Voo, Reserva). Elas servem como intermediárias entre as camadas de dados (modelos) e a interface do usuário ou outras partes do sistema que requerem acesso a esses dados.

Lista de assinaturas das funções e parâmetros do programa:

Classe AviaoController:
    AviaoController();
    void carregarAvioes();
    void salvarAvioes();
    Aviao* buscarAviao(int codigo_aviao);
    vector<Aviao> getListaAvioes() const;
    void cadastrarAviao();
    void editarAviao(int codigo_aviao);
    void excluirAviao(int codigo_aviao);
    void visualizarAvioes() const;
    void setDisponibilidade(int codigo_aviao, bool disponibilidade);
    int avioesDisponiveis() const;
    int avioesCadastrados() const;
    int getProximoCodigo() const;

Classe PassageiroController:
    PassageiroController();
    void carregarPassageiros();
    void salvarPassageiros();
    Passageiro* buscarPassageiro(int codigo_passageiro);
    vector<Passageiro> getListaPassageiros() const;
    void cadastrarPassageiro();
    void editarPassageiro(int codigo_passageiro);
    void excluirPassageiro(int codigo_passageiro);
    void visualizarPassageiros() const;
    int getProximoCodigo() const;

Classe TripulacaoController:
    TripulacaoController();
    vector<Tripulacao> getTripulacoes() const;
    int getQtdPiloto() const;
    int getQtdCopiloto() const;
    int getQtdComissario() const;
    void cadastrarTripulacao();
    void listarTripulacao();
    void salvarTripulacao();
    void carregarTripulacao();

Classe VooController:
    VooController();
    void carregarVoos();
    Voo* buscarVoo(int codigo_voo);
    int getNumeroVoos() const;
    vector<Voo> getListaVoos() const;
    void salvarVoos();
    void cadastrarVoo(AviaoController* aviaoController, TripulacaoController* tripulacaoController);
    void visualizarVoos() const;
    void darBaixaVoo(int codigo_voo);
    int voosCadastrados() const;
    int getProximoCodigo() const;

Classe ReservaController:
    ReservaController();
    void cadastrarReserva(VooController* vooController, PassageiroController* passageiroController);
    void exibirDetalhesReserva(Reserva* reserva);
    Reserva* buscarReserva(int codigo_reserva);
    vector<Reserva> getListaReservas() const;
    void salvarReservas();
    void carregarReservas();
    void excluirReservasVoo(int codigo_voo);
    void listarReservas();
    void exibirTabelaAssentos(int codigo_voo);
    void reservarAssento(int codigo_voo, int assento, Passageiro* passageiro);
    int getProximoCodigoReserva() const;
    bool estaReservado(int codigo_voo, int assento)

Models para os tipos de dados:
    Aviao
    Passageiro
    Tripulacao
    Voo
    Reserva
    Assento

Aviao:
    Aviao(int codigo_aviao, string nome_aviao, int qtd_assentos, bool disponivel);
    Aviao();
    int getCodigoAviao() const;
    string getNomeAviao() const;
    int getQtdAssentos() const;
    bool getDisponivel() const;
    void setDisponibilidade(bool disponibilidade);
    void setCodigoAviao(int codigo_aviao);
    void setNomeAviao(const string& nome_aviao);
    void setQtdAssentos(int qtd_assentos);
    void salvar(ostream& out) const;
    void carregar(istream& in);

Passageiro:
    Passageiro(int codigo_passageiro, string nome, string endereco, string telefone, bool fidelidade, int pontos_fidelidade);
    Passageiro();
    int getCodigoPassageiro() const;
    string getNome() const;
    string getEndereco() const;
    string getTelefone() const;
    bool isFidelidade() const;
    int getPontosFidelidade() const;
    void setCodigoPassageiro(int codigo_passageiro);
    void setNome(string nome);
    void setEndereco(string endereco);
    void setTelefone(string telefone);
    void setFidelidade(bool fidelidade);
    void setPontosFidelidade(int pontos_fidelidade);

Tripulacao:
    Tripulacao(int codigo, string nome, string cargo, string telefone, bool disponivel);
    Tripulacao();
    int getCodigoTripulacao() const;
    string getNomeTripulacao() const;
    string getCargoTripulacao() const;
    string getTelefoneTripulacao() const;
    bool getDisponivel() const;
    void setCodigoTripulacao(int codigo);
    void setNomeTripulacao(string nome);
    void setCargoTripulacao(string cargo);
    void setTelefoneTripulacao(string telefone);
    void setDisponivel(bool disponivel);
    void salvar();
    void carregar();

Voo:
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

Reserva:
    Reserva();
    Reserva(int codigoReserva, int codigo_voo, int codigoPassageiro, int pontos_fidelidade, int assento,
            string nomePassageiro, string endereco, string telefone, string dataVoo, bool fidelidade, int hora,
            string dataReserva, float tarifa);
    int getCodigoPassageiro() const;
    int getCodigoReserva() const;
    int getNumeroVoo() const;
    int getAssento() const;
    string getNomePassageiro() const;
    string getdataVoo() const;
    string getdataReserva() const;
    float getTarifa() const;
    int getHora() const;
    int getPontosFidelidade() const;
    string getEndereco() const;
    string getTelefone() const;
    bool isFidelidade() const;
    void setCodigoPassageiro(int codigoPassageiro);
    void setCodigoReserva(int codigoReserva);
    void setNumeroVoo(int codigo_voo);
    void setAssento(int assento);
    void setNomePassageiro(string nomePassageiro);
    void setdataVoo(string dataVoo);
    void setdataReserva(string dataReserva);
    void setTarifa(float tarifa);
    void setHora(int hora);
    void setPontosFidelidade(int pontos_fidelidade);
    void setEndereco(string endereco);
    void setTelefone(string telefone);
    void setFidelidade(bool fidelidade);