#ifndef AGUARDA_H
#define AGUARDA_H

#include "celula.h"

//Assinatura dos atributos e metodos da classe Aguarda que eh uma pilha encadeada
class Aguarda
{
    public:
        Aguarda();
        ~Aguarda();
        void AdicionaNave(int nave);
        int RemoveNave();
        void ImprimeNaves();

    private:
        int tamanho;
        TipoCelula* nave_mais_apta;
};

#endif // AGUARDA_H