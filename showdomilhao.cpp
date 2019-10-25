#include <iostream>
#include <string>
#include "showdomilhao.h"

using namespace std;

Resultado::Resultado(){
    this->nomePessoa = nomePessoa;
    this->pontuacao = pontuacao;
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
}

string Resultado::get_nomePessoa(){
    return this->nomePessoa;
}

float Resultado::get_pontuacao(){
    return this->pontuacao;
}

int Resultado::get_dia(){
    return this->dia;
}

int Resultado::get_mes(){
    return this->mes;
}

int Resultado::get_ano(){
    return this->ano;
}

void Resultado::set_nomePessoa(string nomePessoa){
    this->nomePessoa = nomePessoa;
}

void Resultado::set_pontuacao(float pontuacao){
    this->pontuacao = pontuacao;
}

void Resultado::set_dia(int dia){
    this->dia = dia;
}

void Resultado::set_mes(int mes){
    this->mes = mes;
}

void Resultado::set_ano(int ano){
    this->ano = ano;
}

Pergunta::Pergunta(){
    this->respostaCorreta = respostaCorreta;
    this->dificuldade = dificuldade;
    this->pergunta = pergunta;
}

int Pergunta::get_respostaCorreta(){
    return this->respostaCorreta;
}

int Pergunta::get_dificuldade(){
    return this->dificuldade;
}

string Pergunta::pergunta(){
    return this->pergunta;
}

void Pergunta::set_respostaCorreta(int mes){
    this->respostaCorreta = respostaCorreta;
}

void Pergunta::set_dificuldade(int ano){
    this->dificuldade = dificuldade;
}

void Pergunta::set_pergunta(int mes){
    this->pergunta = pergunta;
}

bool Pergunta::verificaAcerto(int alternativaEscolhida){
    if(alternativaEscolhida = get_respostaCorreta())
        return 1;
    return 0;
}

void Pergunta::mostraAlternativas(){

}


int main(){
    int alternativaEscolhida;

    return 0;
}