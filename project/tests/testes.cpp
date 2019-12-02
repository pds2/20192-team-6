#include "doctest.h"

#include "ajuda.h"
#include "ajudaCartas.h"
#include "ajudaUniversitarios.h"
#include "ajudaConhecido.h"
#include "pergunta.h"


#include <string.h>
#include <iostream>

TEST_CASE("01 - Testando Ajuda Default") {
    string *alternativas = new string[4];
    alternativas[0] = "altA";
    alternativas[1] = "altB";
    alternativas[2] = "altC";
    alternativas[3] = "altD";
    Pergunta *p = new Pergunta("pergunta", alternativas, 1, 1);
    Ajuda ajuda(p);
    CHECK(ajuda.get_options().compare("") == 0);
    Ajuda ajudaUndefined;
    CHECK(ajudaUndefined.isUndefined);
}

TEST_CASE("02 - Testando Ajuda Cartas") {
    string *alternativas = new string[4];
    alternativas[0] = "altA";
    alternativas[1] = "altB";
    alternativas[2] = "altC";
    alternativas[3] = "altD";
    Pergunta *p = new Pergunta("pergunta", alternativas, 1, 1);
    AjudaCartas ajudaCartas(p);
    CHECK(ajudaCartas.get_options().compare("Existem 4 cartas na mesa, para virar uma digite um número de 1 a 4") == 0);
    CHECK_THROWS(ajudaCartas.choose_option(0));
    CHECK_THROWS(ajudaCartas.choose_option(5));

    ajudaCartas.choose_option(2);
    PerguntaComAjuda* perguntaComAjuda = ajudaCartas.get_perguntaComAjuda();

    int eliminadas = 0;
    for(int i = 0; i < 4; i++){
        string alt = perguntaComAjuda->get_alternativa(i);
        if (alt.find("[Alternativa Eliminada]") != std::string::npos) {
            eliminadas ++;
        }
    }
    CHECK(eliminadas >= 1);
    CHECK(eliminadas <= 3);
}

TEST_CASE("02 - Testando Ajuda Cartas") {
    string *alternativas = new string[4];
    alternativas[0] = "altA";
    alternativas[1] = "altB";
    alternativas[2] = "altC";
    alternativas[3] = "altD";
    Pergunta *p = new Pergunta("pergunta", alternativas, 1, 1);
    AjudaCartas ajudaCartas(p);
    CHECK(ajudaCartas.get_options().compare("Existem 4 cartas na mesa, para virar uma digite um número de 1 a 4") == 0);
    CHECK_THROWS(ajudaCartas.choose_option(0));
    CHECK_THROWS(ajudaCartas.choose_option(5));

    ajudaCartas.choose_option(2);
    PerguntaComAjuda* perguntaComAjuda = ajudaCartas.get_perguntaComAjuda();

    int eliminadas = 0;
    for(int i = 0; i < 4; i++){
        string alt = perguntaComAjuda->get_alternativa(i);
        if (alt.find("[Alternativa Eliminada]") != std::string::npos) {
            eliminadas ++;
        }
    }
    CHECK(eliminadas >= 1);
    CHECK(eliminadas <= 3);
}

TEST_CASE("03 - Testando Ajuda Universitários") {
    string *alternativas = new string[4];
    alternativas[0] = "altA";
    alternativas[1] = "altB";
    alternativas[2] = "altC";
    alternativas[3] = "altD";
    Pergunta *p = new Pergunta("pergunta", alternativas, 1, 1);
    AjudaUniversitarios ajudaUniversitarios(p);
    CHECK(ajudaUniversitarios.get_options().compare("") == 0);

    PerguntaComAjuda* perguntaComAjuda = ajudaUniversitarios.get_perguntaComAjuda();
    CHECK(perguntaComAjuda->get_ajuda().find("Votos dos universitários:") != std::string::npos);
}

TEST_CASE("04 - Testando Ajuda Conhecido") {
    string *alternativas = new string[4];
    alternativas[0] = "altA";
    alternativas[1] = "altB";
    alternativas[2] = "altC";
    alternativas[3] = "altD";
    Pergunta *p = new Pergunta("pergunta", alternativas, 1, 1);
    AjudaConhecido ajudaConhecido(p);
    CHECK(ajudaConhecido.get_options().compare("1- Ajuda do Irmão\n2- Ajuda do Pai\n3- Ajuda da Mãe\n4- Ajuda do Amigo") == 0);

    CHECK_THROWS(ajudaConhecido.choose_option(0));
    CHECK_THROWS(ajudaConhecido.choose_option(5));

    ajudaConhecido.choose_option(1);
    PerguntaComAjuda* perguntaComAjuda = ajudaConhecido.get_perguntaComAjuda();
    CHECK(perguntaComAjuda->get_ajuda().find("do Irmão") != std::string::npos);

    ajudaConhecido.choose_option(2);
    perguntaComAjuda = ajudaConhecido.get_perguntaComAjuda();
    CHECK(perguntaComAjuda->get_ajuda().find("do Pai") != std::string::npos);

    ajudaConhecido.choose_option(3);
    perguntaComAjuda = ajudaConhecido.get_perguntaComAjuda();
    CHECK(perguntaComAjuda->get_ajuda().find("da Mãe") != std::string::npos);

    ajudaConhecido.choose_option(4);
    perguntaComAjuda = ajudaConhecido.get_perguntaComAjuda();
    CHECK(perguntaComAjuda->get_ajuda().find("do Amigo") != std::string::npos);
}