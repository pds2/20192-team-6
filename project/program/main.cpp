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
void limpaTela();
int valorPergunta(int);
void ganhou1milhao();

int main (void) {

    setlocale(LC_ALL, ""); // Adiciona caracteres UTF-8
    int jogo = 1;

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

    while(jogo>0){ // Loop infinito para o jogador sempre poder voltar ao Menu Principal
    
        limpaTela();

        int opcaoEscolhida = 0; // Armazena a opção escolhida pelo jogador no menu de opções (1 para começar jogo, 2 para ver regras do jogo e 3 para ver ranking)
        string nomeJogador;
        int numeroPergunta = 1;

        cout << "Digite o seu nome: ";
        cin >> nomeJogador;

        while(opcaoEscolhida == 0){

            menuOpcoes(); // Escreve o menu na tela
            cin >> opcaoEscolhida;

            if(opcaoEscolhida==2){ // Se opção escolhida = 2, imprime as regras do jogo.
                limpaTela();
                regrasJogo();
                cin >> opcaoEscolhida; // Opção para voltar ao menu
            }
            else if(opcaoEscolhida==3){
                //Imprimir Ranking
            }
        }
        while(opcaoEscolhida==1){

            limpaTela();

            int alternativaEscolhida = 0;
            int dinheiroGanho = 0;

            // Animação de início de pergunta:
            cout << endl << endl;
            cout << "  V A L E N D O   R$" << valorPergunta(numeroPergunta) << ",00" << endl;
            sleep(2);
            limpaTela();
            cout << "Você já tem R$" << valorPergunta(numeroPergunta-1) << ",00" << endl << endl;

            // Escolher Pergunta do arquivo

            cout << "Digite 5 para desistir e sair com R$" << (valorPergunta(numeroPergunta)/2) << ",00" << endl << endl;
            cin >> alternativaEscolhida;
            
            if(alternativaEscolhida==5){
                limpaTela();
                dinheiroGanho = (valorPergunta(numeroPergunta)/2);
                cout << "Não foi 1 milhão mas é melhor do que nada! Você ganhou R$" << dinheiroGanho << ",00."<< endl;
                opcaoEscolhida = 2; //opção escolhida diferente de 1 para que saia do loop
            }
            else if(Pergunta::verificaAcerto(alternativaEscolhida)){
                limpaTela();
                cout << endl << "   PARABÉNS, VOCÊ ACERTOU!" << endl << endl;
                cout << "Digite 1 para ir para a proxima pergunta: ";
                cin >> opcaoEscolhida;
                numeroPergunta++;
                dinheiroGanho = valorPergunta(numeroPergunta);
            }else{
                cout << "ALTERNATIVA INCORRETA! INFELIZMENTE VOCÊ PERDEU TUDO!" << endl;
                dinheiroGanho = 0;
                opcaoEscolhida = 2; //opção escolhida diferente de 1 para que saia do loop
            }

            if(numeroPergunta==10){
                limpaTela();
                ganhou1milhao();
                opcaoEscolhida = 2; // Opção escolhida diferente de 1 para que saia do loop
            }
            
        }
        cout << "Digite 1 para voltar ao menu: ";
        cin >> jogo;

    } // Fim while(jogo>0)

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

void limpaTela(){
    system("cls");
}

int valorPergunta(int numeroPergunta){ //Função que retorna o valor em dinheiro da pergunta de acordo com o numero da pergunta.
    switch(numeroPergunta){
        case 1:
            return 1000;
            break;
        case 2:
            return 2000;
            break;
        case 3:
            return 5000;
            break;
        case 4:
            return 10000;
            break;
        case 5:
            return 50000;
            break;
        case 6:
            return 100000;
            break;
        case 7:
            return 250000;
            break;
        case 8:
            return 500000;
            break;
        case 9:
            return 1000000;
            break;
    }
}

void menuOpcoes(){
    system("cls"); // Limpa tela toda vez que a função menu opções é chamada
    cout << "   ________________________________________ "  << endl;
    cout << "  |   __________________________________   |" << endl;
    cout << "  |  _)                                (_  |" << endl;
    cout << "  | |             S  H  O  W             | |" << endl;
    cout << "  | |                D  O                | |" << endl;
    cout << "  | |_         M  I  L  H  Ã  O         _| |" << endl;
    cout << "  |   )________________________________(   |" << endl;
    cout << "  |________________________________________|"  << endl;
    cout << endl;
    cout << "    MENU:                                     " << endl;
    cout << "    - Digite 1 para jogar                     " << endl;
    cout << "    - Digite 2 para ver Regras do Jogo        " << endl;
    cout << "    - Digite 3 para ver Ranking               " << endl << endl;
    cout << "Resposta: ";
}

void regrasJogo(){
    cout << " REGRAS DO JOGO:" << endl << endl;
    cout << "  1- O seu objetivo neste jogo é ganhar a máxima quantidade de dinheiro que conseguir, sendo o prêmio maximo de 1 milhão de reais;" << endl;
    cout << "  2- Você vai ganhando dinheiro à medida que vai acertando as perguntas;" << endl;
    cout << "  3- Cada pergunta possui 4 alternativas, sendo apenas uma verdadeira;" << endl;
    cout << "  4- Você pode pedir ajuda de universitários, de um conhecido ou usar as cartas, mas só pode usar cada tipo de ajuda apenas 1 vez em cada jogo." << endl << endl;
    sleep(2);
    cout << " BOM JOGO! Digite 0 para voltar ao menu: ";
}

void ganhou1milhao(){
    cout << "         ______________________________________________________________________ " << endl;
    cout << "       /|                                                                      |" << endl;
    cout << "      / |                          P A R A B É N S,                            |" << endl;
    cout << "     /  |                                                                      |" << endl;
    cout << "    /   |    V O C Ê   G A N H O U   1   M I L H Ã O   D E   R E A I S !!!     |" << endl;
    cout << "   |    |                                                                      |" << endl;
    cout << "   |    |______________________________________________________________________|" << endl;
    cout << "   |   /                                                                      / " << endl;
    cout << "   |  /                                                                      /  " << endl;
    cout << "   | /                                                                      /   " << endl;
    cout << "   |/______________________________________________________________________/    " << endl << endl;;
}