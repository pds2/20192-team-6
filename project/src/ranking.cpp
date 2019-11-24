#include "ranking.h"
#include "resultado.h"


Ranking::Ranking (vector<Resultado> resultados){
	this->resultados = resultados;
}


void Ranking::set_resultados(vector<Resultado>  resultados){
	this->resultados = resultados;
}


void Ranking::addToListaResultados(Resultado resultado){	//adiciona a lista cada resultado obtido
	resultados.push_back(resultado);
}

bool ordenacaoCrescente(Resultado r1, Resultado r2){		//fun�ao complemetar para ajudar no sort (3� parametro do sort)
	return r1.get_pontuacao() > r2.get_pontuacao();
}

bool ordenacaoDecrescente(Resultado r1, Resultado r2){ 		//fun�ao complemetar para ajudar no sort (3� parametro do sort)
	return r1.get_pontuacao() < r2.get_pontuacao();
}

void Ranking::OrdenarPrimeiros(){
	sort(this->resultados.begin(), this->resultados.end(), ordenacaoCrescente);	//ordenacao crescente
}

void Ranking::PrintResultados(){
	for(Resultado &i : this->resultados){
		cout << i.get_pontuacao() << " " << i.get_nomePessoa() << " \t" << "Data: " << i.get_dia() << " " << i.get_mes() << "/" << i.get_ano() << endl;
	}
}

void  Ranking::OrdenarUltimos(){
	sort(this->resultados.begin(), this->resultados.end(), ordenacaoDecrescente);		//ordenacao decrescente
}


vector<Resultado>  Ranking::OrdenarMilhoes(){
	//vector<int> milhoes;
	//if (resultado == 1000000) contador++;               //se o resultado for 1milh�o, adiciona 1 no contador daquele jogador, s� que ainda n�o sei como isso vai ser feito
	return resultados;
}

vector<Resultado> Ranking::get_resultados(){
	return this->resultados;
}
