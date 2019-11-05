#ifndef RANKING_H
#define RANKING_H

#include <iostream>
#include <vector>
#include "resultado.h"

using namespace std;

class Ranking{
	private:				
		vector<Resultado> resultados;
		
	public:
		
		Ranking(vector<Resultado> resultados);
		
		
		void set_resultado(vector<Resultado>  resultados); 
		                     
		void addToListaResultados(Resultado resultado);
				
		vector<Resultado> get_lista_resultados();		
		
		vector<Resultado> OrdenarPrimeiros();         
		vector<Resultado> OrdenarUltimos();           
		
		vector<Resultado> OrdenarMilhoes();          //ordenando por vitórias
		
		
};

#endif
