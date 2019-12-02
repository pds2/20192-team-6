# Show do Milhão - C++

Projeto desenvolvido como trabalho final da disciplina PDS II (grupo 6)
Slides primeira apresentação: https://github.com/pds2/20192-team-6/blob/master/Trabalho%20Final%201%C2%AA%20apresenta%C3%A7%C3%A3o.pdf

Projeto desenvolvido pelos alunos:
- Bernardo 
- Fernando
- Otávio
- Vinícius



## Documentação
O projeto Show do milhão foi desenvolvido com o intuito de explorar e colocar em prática os conhecimentos obtidos na disciplina Programação de Desenvolvimento de Software 2 (PDS2), no curso de Sistemas de Informação na UFMG. Dentre os vários conteúdos aplicados neste projeto, o foco foi na orientação à objetos, principalmente nos conceitos de herança, encapsulamento, poliformismo, entre outros.

O projeto foi realizado no segundo semestre de 2019.
Os desenvolvedores do projeto tiveram forte inspiração no show de TV da SBT chamado "Show do milhão". Inclusive, todas as perguntas contidas neste jogo foram retiradas de lá, todos os créditos das perguntas pertencem à SBT. 

### Fluxo Principal


### Perguntas


#### Classe Pergunta

#### Classe PerguntaComAjuda
- PerguntaComAjuda(Pergunta \*pergunta, string ajuda) - O objeto é construído com uma instância de Pergunta e uma string, que é a ajuda que alguma classe Ajuda retornou
- PerguntaComAjuda::get_ajuda() - Retorna a ajuda que alguma classe Ajuda retornou
- PerguntaComAjuda::mostraAlternativas() - Escreve as alternativas usando o método mostraAlternativas() da classe Pergunta e logo abaixo escreve a string ajuda


### Resultados


### Repositório


### Rankings


### Ajudas

#### Classe Ajuda
A classe Ajuda é uma classe com o objetivo de servir para representar ajudas indefinidas (inválidas) e servir para ser o modelo (pai), para as classes AjudaConhecido, AjudaCartas e AjudaUniversitarios herdarem. Cada uma das classes filhas de comportam de uma forma.

*Ajuda(Pergunta\*) - Constrói-se a classe com uma pergunta*

- string Ajuda::get_options() - Retorna as opções que o usuário tem para usar a ajuda
- void Ajuda::choose_option(int) - Seleciona a opção da ajuda, este método já constroi a PerguntaComAjuda nas classes que herdam Ajuda.
- PerguntaComAjuda* Ajuda::get_perguntaComAjuda() - Retorna uma instância de PerguntaComAjuda, que é a Pergunta que foi passada no construtor já adaptada

#### Classe AjudaConhecido
- string AjudaConhecido::get_options() - Retorna as opções: Ajuda do irmão, do pai, da mãe ou do amigo
- void AjudaConhecido::choose_option(int) - Seleciona a opção da ajuda, a dica que a opção dá tem 80% de chance de acerto

#### Classe AjudaCartas
- string AjudaCartas::get_options() - Retorna as opções: Carta 1, 2, 3 ou 4
- void AjudaCartas::choose_option(int) - Seleciona a carta, ao selecionar, a Pergunta com Ajuda será gerada com 1, 2 ou 3 alternativas eliminadas

#### Classe AjudaUniversitarios
- AjudaUniversitarios(Pergunta\*) - Constrói-se a classe com uma pergunta e já a modifica sorteando de forma inteligente porcentagens de recomendações dosuniversitários. Há uma grande chance de que a maioria dos universitários recomende a alternativa correta, porém a chance não é de 100%, algumas vezes os universitários falham
- string AjudaUniversitarios::get_options() - Retorna uma string vazia
- void AjudaUniversitarios::choose_option(int) - Método vazio, não faz nada


