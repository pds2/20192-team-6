#ifndef SHOWDOMILHAO_H
#define SHOWDOMILHAO_H

using namespace std;

class Resultado{

private:
    string nomePessoa;
    float pontuacao;
    int dia, mes, ano;

public:
    Resultado();

    string get_nomePessoa();
    float get_pontuacao();
    int get_dia();
    int get_mes();
    int get_ano();

    void set_nomePessoa(string nomePessoa);
    void set_pontuacao(float pontuacao);
    void set_dia(int dia);
    void set_mes(int mes);
    void set_ano(int ano);

};

class Pergunta{

private:
    int respostaCorreta;
    int dificuldade;
    string pergunta;

public:
    Pergunta();

    int get_respostaCorreta();
    int get_dificuldade();
    string get_pergunta();

    void set_respostaCorreta(int respostaCorreta);
    void set_dificuldade(int dificuldade);
    void set_pergunta(string pergunta);

    bool verificaAcerto(int respostaCorreta);
    void mostraAlternativas();

};

#endif // SHOWDOMILHAO_H