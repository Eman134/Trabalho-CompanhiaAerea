
# Trabalho-CompanhiaAerea

[Repositório no GitHub](https://github.com/Eman134/Trabalho-CompanhiaAerea)

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
    g++ main.cpp modulos/*.cpp -o TrabalhoCompanhiaAerea
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
7. **Cadastrar assento** – Definir os assentos disponíveis em cada voo.
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
8 - Cadastrar assento
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

## Autores

- **Kayke Emanoel** - [Eman134](https://github.com/Eman134)
- **Rafael Brant** - [rafaelbrant07](https://github.com/rafaelbrant07)
- **Carlos Eduardo** - [Cadu-santos32](https://github.com/Cadu-santos32)