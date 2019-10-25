#include "respositorio.h"

Repositorio::sortearPergunta(int dificuldade, int numPerguntas) {

    string caminho = caminhoPerguntas;
    int indexPerguntas[num_perguntas];

    switch(dificuldade) {
        case 1:
            caminho += "faceis.txt";
            break;
        
        case 2:
            caminho += "medias.txt";
            break;
        
        case 3:
            caminho += "dificeis.txt";
            break;    
    }


    for (int i = 0; i < numPerguntas; i++) {        
        //index_perguntas[i] = rand() % 1;
        indexPerguntas[i] = 0;
    }


    ofstream arquivo;
    arquivo.open (caminho);

    if (arquivo.is_open()) {
        int i = 0;
        string linha = "";

        while( get_line(arquivo, linha) ) {            
            
            if (i == indexPerguntas[0]) {
                cout << linha << endl;
            }

            i++;
        }
    }

    arquivo.close();

}

 Repositorio::salvarResultado(Resultado resultado) {

    string resultado_string = resultadoToString(); 

    ofstream arquivo;
    arquivo.open(caminhoResultados);

    if (arquivo.is_open()) {
        arquivo <<  resultado_string + "\n";
    }
 }


// Conversores de string para objeto //
string Repositorio::resultadoToString(Resultado resultado) {

    string linha = "";
    linha += resultado.get_nomePessoa() + "****";
    linha += resultado.get_pontuacao()  + "****";
    linha += resultado.get_dia()  + "****";
    linha += resultado.get_mes()  + "****";
    linha += resultado.get_ano()  + "****";

    return linha;
}

Resultado Repositorio::stringToResultado(string resultadoStr) {
    Resultado resultado = Resultado();

    return resultado;
}


string Repositorio::perguntaToString(Pergunta pergunta) {

    string linha = "";
    linha += pergunta.get_enunciado() + "****";
    linha += pergunta.get_alternativas(0)  + "****";
    linha += pergunta.get_alternativas(1)  + "****";
    linha += pergunta.get_alternativas(2)  + "****";
    linha += pergunta.get_alternativas(3)  + "****";
    linha += pergunta.get_alternativas(3)  + "****";
    linha += pergunta.get_respostaCorreta()  + "****";
    linha += pergunta.get_dificuldade()  + "****";

    return linha;
}

Pergunta Repositorio::stringToPergunta(string perguntaStr) {
    Pergunta pergunta = Pergunta();
    size_t pos = 0;

    // LÊ ENUNCIADO
    pos = perguntaStr.find(sequenciaSeparadora);
    pergunta.set_enunciado(s.substr(0, pos));
    s.erase(0, pos + sequenciaSeparadora.length());

    // LÊ ALTERNATIVAS
    for (int i=0; i<4; i++) {
        pos = perguntaStr.find(sequenciaSeparadora);
        pergunta.set_alternativas(i, (s.substr(0, pos));
        s.erase(0, pos + sequenciaSeparadora.length());
    }
    
    // LÊ RESPOSTA CORRETA
    pos = perguntaStr.find(sequenciaSeparadora);
    int resposta = 0;
    s.substr(0, pos) >> resposta;
    pergunta.set_respostaCorreta(resposta);
    s.erase(0, pos + sequenciaSeparadora.length());

    // LÊ DIFICULDADE
    pos = perguntaStr.find(sequenciaSeparadora);
    int dificuldade = 0;
    s.substr(0, pos) >> dificuldade;
    pergunta.set_dificuldade(dificuldade);
    s.erase(0, pos + sequenciaSeparadora.length());

    return pergunta;
}

 /* Getters and Setters //
 Repositorio::get_caminho_perguntas() {
    return caminho_perguntas;
 }

 Repositorio::get_caminho_resultados() {
    return caminho_resultados;
 } */