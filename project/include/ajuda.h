#ifndef AJUDA_H
#define AJUDA_H

using namespace std;
#include <string>
#include "pergunta.h"
#include "perguntaComAjuda.h"
#include "util.h"

class Ajuda {

    protected:
        Pergunta pergunta;  
        PerguntaComAjuda perguntaComAjuda;

    public:
        Ajuda(Pergunta);        

        virtual string get_options();
        virtual void choose_option(int);
        virtual PerguntaComAjuda get_perguntaComAjuda();
};

#endif // AJUDA_H