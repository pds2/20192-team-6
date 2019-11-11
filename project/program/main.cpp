#include <iostream>
#include <iomanip>
#include <locale.h>
#include <unistd.h>
#include "repositorio.h"
#include "perguntaComAjuda.h"
#include "ajudaCartas.h"
#include "ajudaConhecido.h"
#include "ajudaUniversitarios.h"

using namespace std;

void menuOpcoes();
void regrasJogo();

int main (void) {

    setlocale(LC_ALL, "");

    // TESTE REPOSITORIO
    Repositorio repo = Repositorio();
    
    // LER PERGUNTAS
    vector<Pergunta> perguntas;
    perguntas = repo.sortearPerguntas(10);
    /*cout << perguntas[0].get_pergunta() << endl;
    cout << perguntas[1].get_pergunta() << endl;
    cout << perguntas[2].get_pergunta() << endl;
    cout << perguntas[3].get_pergunta() << endl;
    cout << perguntas[4].get_pergunta() << endl;
    cout << perguntas[5].get_pergunta() << endl;*/

    // SALVAR RESULTADO
    /*Resultado r = Resultado("Bernardo Nunes", 300000, 26, 10, 2019);    
    repo.salvarResultado(r);*/

    int i = 1;
    int opcaoEscolhida = 0; //Armazena a opção escolhida pelo jogador no menu de opções (1 para começar jogo, 2 para ver regras do jogo e 3 para ver ranking)
    string nomeJogador;

    while(opcaoEscolhida == 0){

        if(i==1){ //Condicional para assegurar que o jogador só digite o seu nome uma vez.
            cout << "Digite o seu nome: ";
            cin >> nomeJogador;
            i++;
        }

        menuOpcoes(); // Escreve o menu na tela
        cin >> opcaoEscolhida;

        if(opcaoEscolhida==2){ // Se opção escolhida = 2, imprime as regras do jogo.
            system("cls");
            regrasJogo();
            cin >> opcaoEscolhida;//Opção para voltar ao menu
        }
        else if(opcaoEscolhida==3){
            //Imprimir Ranking
        }
    }
    while(opcaoEscolhida==1){
        system("cls");

        int numeroPergunta = 1;
        cout << "Pergunta número " << numeroPergunta << ":" << endl;

        //Escolher Pergunta do arquivo

        cout << "Digite 2 para desistir e sair com metade do que já tem." << endl;
        cin >> opcaoEscolhida;
        if (opcaoEscolhida==2){
            break;
        }
        numeroPergunta++;
    }

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

//FUNÇÕES:

void menuOpcoes(){
    system("cls");
    cout << "   ________________________________________ "  << endl;
    cout << "  |    ________________________________    |" << endl;
    cout << "  |  _|                                |_  |" << endl;
    cout << "  | |               S H O W              | |" << endl;
    cout << "  | |                 D O                | |" << endl;
    cout << "  | |_            M I L H Ã O           _| |" << endl;
    cout << "  |   |________________________________|   |" << endl;
    cout << "  |________________________________________|"  << endl;
    cout << endl;
    sleep(1);
    cout << "    MENU:                                     " << endl;
    cout << "    - Digite 1 para jogar                     " << endl;
    cout << "    - Digite 2 para ver Regras do Jogo        " << endl;
    cout << "    - Digite 3 para ver Ranking               " << endl << endl;
    cout << "Resposta: ";
}

void regrasJogo(){
    cout << " REGRAS DO JOGO:      " << endl;
    cout << "  1- O seu objetivo neste jogo é ganhar a máxima quantidade de dinheiro que conseguir, sendo o prêmio maximo de 1 milhão de reais;" << endl;
    cout << "  2- Você vai ganhando dinheiro à medida que vai acertando as perguntas;" << endl;
    cout << "  3- Cada pergunta possui 4 alternativas, sendo apenas uma verdadeira;" << endl;
    cout << "  4- Você pode pedir ajuda de universitários, de um conhecido ou usar as cartas, mas só pode usar cada tipo de ajuda apenas 1 vez em cada jogo." << endl << endl;
    sleep(3);
    cout << " BOM JOGO! Digite 0 para voltar ao menu: ";
}