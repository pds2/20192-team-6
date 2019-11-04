#include <iostream>
#include "repositorio.h"
#include "perguntaComAjuda.h"
#include "ajudaCartas.h"
#include "ajudaConhecido.h"
#include "ajudaUniversitarios.h"

int main (void) {

    // TESTE REPOSITORIO
    Repositorio repo = Repositorio();
    
    // LER PERGUNTAS
    vector<Pergunta> perguntas;
    perguntas = repo.sortearPerguntas(6);
    /*cout << perguntas[0].get_pergunta() << endl;
    cout << perguntas[1].get_pergunta() << endl;
    cout << perguntas[2].get_pergunta() << endl;
    cout << perguntas[3].get_pergunta() << endl;
    cout << perguntas[4].get_pergunta() << endl;
    cout << perguntas[5].get_pergunta() << endl;*/

    // SALVAR RESULTADO
    /*Resultado r = Resultado("Bernardo Nunes", 300000, 26, 10, 2019);    
    repo.salvarResultado(r);*/


    // BUSCAR RESULTADOS
    /*vector<Resultado> resultados = repo.buscarResultados();
    for (vector<Resultado>::iterator it = resultados.begin() ; it != resultados.end(); ++it) {
        cout << it->get_nomePessoa() << endl;
    }*/

    

    /*AjudaCartas ajudaCartas = AjudaCartas(perguntas[1]);
    cout << endl << "teste ajuda cartas" << endl;
    cout << "options: " + ajudaCartas.get_options() << endl;
    int option;
    cin >> option;
    ajudaCartas.choose_option(option);
    PerguntaComAjuda perguntaComAjuda = ajudaCartas.get_perguntaComAjuda();
    cout << perguntaComAjuda.get_pergunta() << endl;
    for(int i = 0; i < 4; i++){
        cout << perguntaComAjuda.get_alternativa(i) << endl;
    }
    cout << perguntaComAjuda.get_ajuda() << endl;*/

    /*cout << endl << endl << "teste ajuda conhecido" << endl;    
    AjudaConhecido ajudaConhecido = AjudaConhecido(perguntas[1]);
    cout << "options: " + ajudaConhecido.get_options() << endl;
    int option;
    cin >> option;
    ajudaConhecido.choose_option(option);
    PerguntaComAjuda perguntaComAjuda = ajudaConhecido.get_perguntaComAjuda();
    cout << perguntaComAjuda.get_pergunta() << endl;
    for(int i = 0; i < 4; i++){
        cout << perguntaComAjuda.get_alternativa(i) << endl;
    }
    cout << perguntaComAjuda.get_ajuda() << endl;*/

    cout << endl << endl << "teste ajuda universitarios" << endl;    
    AjudaUniversitarios ajudaUniversitarios = AjudaUniversitarios(perguntas[1]);
    PerguntaComAjuda perguntaComAjuda = ajudaUniversitarios.get_perguntaComAjuda();
    cout << "Pergunta: " << perguntaComAjuda.get_pergunta() << endl;
    for(int i = 0; i < 4; i++){
        cout << perguntaComAjuda.get_alternativa(i) << endl;
    }
    cout << perguntaComAjuda.get_ajuda() << endl;

    
    return 0;
}