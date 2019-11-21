#include <iostream>
#include <iomanip>
#include <locale.h>
#include <unistd.h>
#include "repositorio.h"
#include "perguntaComAjuda.h"
#include "ajuda.h"
#include "ajudaCartas.h"
#include "ajudaConhecido.h"
#include "ajudaUniversitarios.h"
#include <time.h>

using namespace std;

void menuOpcoes();
void regrasJogo();
int limpaTela();
int valorPergunta(int);
void ganhou1milhao();
void mostrarAjudas();
tm* getDataAtual();
void mostrarPergunta();
Ajuda* getAjuda(char alternativa, Pergunta *pergunta);

int ajudaCartasRestantes = 1;
int ajudaConhecidoRestantes = 1;
int ajudaUniversitariosRestantes = 1;
int pulosRestantes = 1;


int jogo = 1;
Repositorio repo = Repositorio();
vector<Pergunta*> perguntas;
int dinheiroGanho;
int opcaoEscolhida;
string nomeJogador;
int numeroPergunta;
int qtdAcertos;

bool delay = true;

int main (void) {

    setlocale(LC_ALL, ""); // Adiciona caracteres UTF-8
    jogo = 1;

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
    
        // LÊ PERGUNTAS
        perguntas = repo.sortearPerguntas(10);

        // INICIALIZA DINHEIRO GANHO
        dinheiroGanho = 0;
        
        limpaTela();

        opcaoEscolhida = 0; // Armazena a opção escolhida pelo jogador no menu de opções (1 para começar jogo, 2 para ver regras do jogo e 3 para ver ranking)        
        numeroPergunta = 1;
        qtdAcertos = 0;

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
            mostrarPergunta();            
        }

        // Salva o resultado do jogo    
        struct tm *data = getDataAtual();
        Resultado r(nomeJogador, dinheiroGanho, data->tm_mday, data->tm_mon+1, data->tm_year+1900);
        repo.salvarResultado(r);

        cout << "Digite 1 para voltar ao menu: ";
        cin >> jogo;

    } // Fim while(jogo>0)
    
    return 0;
}

//FUNÇÕES:

void mostrarPergunta(){
    limpaTela();

    char alternativaEscolhida = '#';

    // Animação de início de pergunta:
    cout << endl << endl;
    cout << "  V A L E N D O   R$" << valorPergunta(qtdAcertos) << ",00" << endl;
    
    if(delay) sleep(2);
    else delay = true;

    limpaTela();
    cout << "Você já tem R$" << valorPergunta(qtdAcertos-1) << ",00" << endl << endl;

    // IMPRIME PERGUNTA
    perguntas[numeroPergunta]->mostraAlternativas();
    mostrarAjudas();

    // MOSTRA AJUDAS

    cout << "Reposta: ";
    cin >> alternativaEscolhida;     
    alternativaEscolhida = tolower(alternativaEscolhida); 

    if(alternativaEscolhida == 'p'){
        numeroPergunta++;
        return;
    }      

    Ajuda *ajuda = getAjuda(alternativaEscolhida, perguntas[numeroPergunta]);
    if(!ajuda->isUndefined) {
        if(ajuda->get_options().compare("") != 0){
            cout << ajuda->get_options() << endl;
            int opcaoAjuda = -1;
            while(1){
                try{
                    cin >> opcaoAjuda;
                    ajuda->choose_option(opcaoAjuda);
                    break;
                }catch(exception& e){
                    cout << "Opção inválida, tente novamente." << endl;
                }
            }
        }
        perguntas[numeroPergunta] = ajuda->get_perguntaComAjuda();   
        delay = false;     
        return;
    }
    
    if(perguntas[numeroPergunta]->verificaAcerto(alternativaEscolhida)){
        limpaTela();
        
        if (qtdAcertos == 10) {
            limpaTela();
            ganhou1milhao();
            opcaoEscolhida = 2; // Opção escolhida diferente de 1 para que saia do loop                
            dinheiroGanho = valorPergunta(qtdAcertos);
        }else {
            
            cout << endl << "   PARABÉNS, VOCÊ ACERTOU!" << endl << endl;
            cout << "Digite 1 para ir para a proxima pergunta ou " << endl;
            cout << "Digite 2 para desistir e sair com R$" << (valorPergunta(qtdAcertos)/2) << ",00" << endl << endl;

            cin >> opcaoEscolhida;

            if(opcaoEscolhida == 2){
                limpaTela();
                dinheiroGanho = (valorPergunta(qtdAcertos)/2);
                cout << "Não foi 1 milhão mas é melhor do que nada! Você ganhou R$" << dinheiroGanho << ",00."<< endl;
                opcaoEscolhida = 2; //opção escolhida diferente de 1 para que saia do loop                    

            }else {
                numeroPergunta++;
                qtdAcertos++;
                dinheiroGanho = valorPergunta(qtdAcertos);
            }
        }

    }else{
        cout << "ALTERNATIVA INCORRETA! INFELIZMENTE VOCÊ PERDEU TUDO!" << endl;
        dinheiroGanho = 0;
        opcaoEscolhida = 2; //opção escolhida diferente de 1 para que saia do loop
    }
}

tm *getDataAtual() {
    //variável do tipo time_t para armazenar o tempo em segundos  
    time_t segundos;
    
    //obtendo o tempo em segundos  
    time(&segundos);   
    
    //utilizamos a função localtime para converter de segundos para o tempo local  
    return localtime(&segundos);  
}

int limpaTela() {
    //system("cls");
    return system("clear");
}

int valorPergunta(int qtdAcertos){ //Função que retorna o valor em dinheiro da pergunta de acordo com o numero da pergunta.
    int qtd = qtdAcertos + 1;
    switch(qtd){
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
        default:
            return 0;
            break;
    }
}

void menuOpcoes(){
    limpaTela(); // Limpa tela toda vez que a função menu opções é chamada
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

void mostrarAjudas(){
    if(ajudaCartasRestantes == 0 && ajudaUniversitariosRestantes == 0 && ajudaConhecidoRestantes == 0 && pulosRestantes == 0) {
        cout << "** Você já utilizou todas as ajudas disponíveis :(" << endl;
    }else{
        cout << "Ajudas restantes: " << endl;
        if(ajudaCartasRestantes == 1) cout << "'#' para pedir ajuda das cartas" << endl;
        if(ajudaUniversitariosRestantes == 1) cout << "'*' para pedir ajuda dos universitários" << endl;
        if(ajudaConhecidoRestantes == 1) cout << "'+' para pedir ajuda de um conhecido" << endl;
        if(pulosRestantes == 1) cout << "'P' para pular a pergunta" << endl;
        cout << endl;
    }
}

Ajuda* getAjuda(char alternativa, Pergunta *pergunta){
    switch(alternativa){
        case '#': 
            if(ajudaCartasRestantes == 0) throw invalid_argument("Ajuda já foi usada");
            ajudaCartasRestantes--;
            return new AjudaCartas(pergunta);
        case '*': 
            if(ajudaUniversitariosRestantes == 0) throw invalid_argument("Ajuda já foi usada");
            ajudaUniversitariosRestantes--;
            return new AjudaUniversitarios(pergunta);
        case '+': 
            if(ajudaConhecidoRestantes == 0) throw invalid_argument("Ajuda já foi usada");
            ajudaConhecidoRestantes--;
            return new AjudaConhecido(pergunta);

        default: return new Ajuda();
    }
}
