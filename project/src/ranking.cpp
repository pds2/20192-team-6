#include "ranking.h"
#include <algorithm>

Ranking::Ranking (int resultado){
	this->resultado = resultado;

}

void Ranking::set_resultados(int resultado){      
	this->resultado = resultado;
}

void Ranking::set_lista_resultados(std::vector<int>& lista_resultados, resutado){   //adiciona � lista os resultados
	lista_resultados.push_back(this->resultado);
}

int Ranking::get_resultados(){
	return(this->resultados);
}

std::vector Ranking::OrdenarPrimeiros(){                         //ordena primeiro e depois pega os 10 primeiros
	sort(lista_resultados.begin(), lista_resultados.end());
	for (int i=0; i<10; i++){
		std::cout<< lista_resultados[i] << std::endl;
	}
}

std::vector Ranking::OrdenarUltimos(){                          //ordena primeiro e depois pega os 10 �ltimos
	sort(lista_resultados.begin(), lista_resultados.end());
	for(int j = 10; j>0; j--){
		std::cout << lista_resultados[j] << std::endl;
	}
}

std::vector Ranking::OrdenarMilhoes(){
	vector<int> milhoes;
	if (resultado == 1000000) contador++;               //se o resultado for 1milh�o, adiciona 1 no contador daquele jogador, s� que ainda n�o sei como isso vai ser feito
}
