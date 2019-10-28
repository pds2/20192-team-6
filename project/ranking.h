#ifndef RANKING
#define RANKING

#include <iostream>
#include <vector>

class Ranking{
	private:
		
		int resultado;
		std::vector<int> lista_resultados;
		
	public:
		
		Ranking(int resultado);
		
		
		void set_resultado(int resultado);                      //setters
		void set_lista_resultados(std::vector<int>& lista_resultados, resultado);
		
		int get_resultado();                                   //getters
		std::vector get_lista_resultados();		
		
		std::vector OrdenarPrimeiros();         //ainda não sei de onde o parâmentro resultado vai vir, ent deixei apenas "resultados"
		std::vector OrdenarUltimos();           //ordenação dos melhores/piores
		
		std::vector OrdenarMilhoes();          //ordenando por vitórias, q eu coloquei como milhoes
		
		
};

#endif
