#include <iostream>
#include "repositorio.h"

int main (void) {

    // TESTE REPOSITORIO
    Repositorio repo = Repositorio();
    
    // LER PERGUNTAS
    vector<Pergunta> perguntas;
    perguntas = repo.sortearPerguntas(6);
    cout << perguntas[0].get_pergunta() << endl;
    cout << perguntas[1].get_pergunta() << endl;
    cout << perguntas[2].get_pergunta() << endl;
    cout << perguntas[3].get_pergunta() << endl;
    cout << perguntas[4].get_pergunta() << endl;
    cout << perguntas[5].get_pergunta() << endl;

    // SALVAR RESULTADO
    Resultado r = Resultado();
    r.set_nomePessoa("Bernardo Nunes");
    r.set_pontuacao(300000);
    r.set_ano(2019);
    r.set_mes(10);
    r.set_dia(26);
    repo.salvarResultado(r);


    // BUSCAR RESULTADOS
    vector<Resultado> resultados = repo.buscarResultados();
    for (vector<Resultado>::iterator it = resultados.begin() ; it != resultados.end(); ++it) {
        cout << it->get_nomePessoa() << endl;
    }
    
    return 0;
}