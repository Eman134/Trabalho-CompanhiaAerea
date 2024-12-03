// test_voo.cpp
#define CATCH_CONFIG_MAIN  // Gera a função main() para os testes
#include "catch_amalgamated.hpp"  // Inclua o Catch2

// Inclua os arquivos do seu código
#include "Aviao.h"

TEST_CASE("Testando a classe Aviao") {
    Aviao aviao;

    SECTION("Testando o método setCodigoAviao()") {
        aviao.setCodigoAviao(1);
        REQUIRE(aviao.getCodigoAviao() == 1);
    }

    SECTION("Testando o método setNomeAviao()") {
        aviao.setNomeAviao("Boeing 737");
        REQUIRE(aviao.getNomeAviao() == "Boeing 737");
    }

    SECTION("Testando o método setQtdAssentos()") {
        aviao.setQtdAssentos(200);
        REQUIRE(aviao.getQtdAssentos() == 200);
    }

    SECTION("Testando o método carregar()") {
        aviao.setCodigoAviao(1);
        aviao.carregar();
        REQUIRE(aviao.getNomeAviao() == "Boeing 737");
        REQUIRE(aviao.getQtdAssentos() == 200);
    }
}
