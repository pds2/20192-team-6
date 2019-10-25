#ifndef REPOSITORIO_H
#define REPOSITORIO_H

#include "showdomilhao.h"
#include <iostream>
#include <fstream>      /* ofstream */
#include <string>       /* string */
#include <stdlib.h>     /* srand, rand */

using namespace std;

class Repositorio{

    private:
        string caminhoPerguntas = ".\\resources\\perguntas\\";
        string caminhoResultados = ".\\resources\\resultados\\resultados.txt";
        string sequenciaSeparadora = "****";

        string resultadoToString(Resultado);
        Resultado stringtoResultado(string);
        string perguntaToString(Pergunta);
        Pergunta stringToPergunta(string);


    public:
        Repositorio() {};
        Pergunta sortearPergunta(int, int);
        void salvarResultado(Resultado);
       // string get_caminhoPerguntas();
       // string get_caminhoResultados();

};