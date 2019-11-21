#ifndef RANKING_H
#define RANKING_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "resultado.h"

using namespace std;

class Ranking{
	private:				
		vector<Resultado> resultados;
		
	public:
		
		Ranking(vector<Resultado> resultados);
		
		
		void set_resultados(vector<Resultado>  resultados); 
		                     
		void addToListaResultados(Resultado resultado);
				
		vector<Resultado> get_lista_resultados();	
		
		vector<Resultado> OrdenarPrimeiros();
		
		static void PrintResultados(vector<Resultado>);
		     
		vector<Resultado> OrdenarUltimos();		
		
		vector<Resultado> OrdenarMilhoes();          //ordenando por vit�rias
		
		vector<Resultado> get_resultados();
		
		
};

#endif
