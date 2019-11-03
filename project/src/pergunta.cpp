#include <iostream>
#include <string>
#include "pergunta.h"

using namespace std;

// Construtor vazio
Pergunta::Pergunta() {
    this->alternativas = new string[4];
}

Pergunta::Pergunta(string pergunta, string *alternativas, int respostaCorreta, int dificuldade){    
    this->pergunta = pergunta;    

    this->alternativas = new string[4];
    for(int i = 0; i < 4; i++){
        this->alternativas[i] = alternativas[i];
    }    
    
    this->respostaCorreta = respostaCorreta;
    this->dificuldade = dificuldade;    
}

int Pergunta::get_respostaCorreta(){
    return this->respostaCorreta;
}

int Pergunta::get_dificuldade(){
    return this->dificuldade;
}

string Pergunta::get_pergunta(){
    return this->pergunta;
}

string Pergunta::get_alternativa(int i) {
    return this->alternativas[i];
}

void Pergunta::set_respostaCorreta(int respostaCorreta){
    this->respostaCorreta = respostaCorreta;
}

void Pergunta::set_dificuldade(int dificuldade){
    this->dificuldade = dificuldade;
}

void Pergunta::set_pergunta(string pergunta){
    this->pergunta = pergunta;
}

void Pergunta::set_alternativa(int i, string alternativa){
    this->alternativas[i] = alternativa;
}

bool Pergunta::verificaAcerto(int alternativaEscolhida){
    if(alternativaEscolhida == get_respostaCorreta())
        return 1;
    return 0;
}

void Pergunta::mostraAlternativas(){

}


/*int main(){
    int alternativaEscolhida;

    return 0;
} */