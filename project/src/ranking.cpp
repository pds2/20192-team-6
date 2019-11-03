#include "ranking.h"
#include <algorithm>

Ranking::Ranking (vector<Resultado> resultados){
	this->resultados = resultados;

}


void Ranking::addToListaResultados(Resultado resultado){   //adiciona à lista os resultados
	resultados.push_back(resultado);
}



vector<Resultado> Ranking::OrdenarPrimeiros(){                         //ordena primeiro e depois pega os 10 primeiros
	//sort(resultados.begin(), resultados.end());
	return resultados;
}

vector<Resultado>  Ranking::OrdenarUltimos(){                          //ordena primeiro e depois pega os 10 últimos
	//sort(resultados.begin(), resultados.end());
	return resultados;
}

vector<Resultado>  Ranking::OrdenarMilhoes(){
	//vector<int> milhoes;
	//if (resultado == 1000000) contador++;               //se o resultado for 1milhão, adiciona 1 no contador daquele jogador, só que ainda não sei como isso vai ser feito
	return resultados;
}
