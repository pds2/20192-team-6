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

bool ordenacaoDecrescente(Resultado r1, Resultado r2){		//fun�ao complemetar para ajudar no sort (3� parametro do sort)
	return r1.get_pontuacao() > r2.get_pontuacao();
}

bool ordenacaoCrescente(Resultado r1, Resultado r2){ 		//fun�ao complemetar para ajudar no sort (3� parametro do sort)
	return r1.get_pontuacao() < r2.get_pontuacao();
}

vector<Resultado> Ranking::OrdenarPrimeiros(){
	sort(resultados.begin(), resultados.end(), ordenacaoDecrescente);	//ordenacao crescente, usando a funcao booleana decrescente
	return resultados;
}

void Ranking::PrintResultados(vector<Resultado> resultados){
	for(Resultado &i : resultados){
		cout << i.get_pontuacao() << " " << i.get_nomePessoa() << " " << "Data: " << i.get_dia() << " " << i.get_mes() << "/" << i.get_ano() << endl;
	}
}

vector<Resultado>  Ranking::OrdenarUltimos(){
	sort(resultados.begin(), resultados.end(), ordenacaoCrescente);		//ordenacao decrescente, usando a funcao booleana crescente
	return resultados;

}


vector<Resultado>  Ranking::OrdenarMilhoes(){
	//vector<int> milhoes;
	//if (resultado == 1000000) contador++;               //se o resultado for 1milh�o, adiciona 1 no contador daquele jogador, s� que ainda n�o sei como isso vai ser feito
	return resultados;
}

vector<Resultado> Ranking::get_resultados(){
	return this->resultados;
}
