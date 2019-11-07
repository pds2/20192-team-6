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

bool ordenacaoDecrescente(Resutado r1, Resultado r2){		//funçao complemetar para ajudar no sort (3º parametro do sort)
	return r1.getPontuacao() > r2.getPontuacao();
}

bool ordenacaoCrescente(Resutado r1, Resultado r2){ 		//funçao complemetar para ajudar no sort (3º parametro do sort)
	return r1.getPontuacao() < r2.getPontuacao();
}

vector<Resultado> Ranking::OrdenarPrimeiros(){
	sort(resultados.begin(), resultados.end(), ordenacaoDecrescente);	//ordenacao crescente, usando a funcao booleana decrescente
	return resultados;
}

vector<Resultado>  Ranking::OrdenarUltimos(){
	sort(resultados.begin(), resultados.end(), ordenacaoCrescente);		//ordenacao decrescente, usando a funcao booleana crescente
	return resultados;

}

vector<Resultado>  Ranking::OrdenarMilhoes(){
	//vector<int> milhoes;
	//if (resultado == 1000000) contador++;               //se o resultado for 1milhão, adiciona 1 no contador daquele jogador, só que ainda não sei como isso vai ser feito
	return resultados;
}

vector<Resultado> Ranking::get_resultados(){
	return this->resultados;
}
