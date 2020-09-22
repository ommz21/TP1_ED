#ifndef COMBATE_H
#define COMBATE_H

#include "celula.h"

//Assinatura dos atributos e metodos da classe Combate que eh uma lista encadeada
class Combate
{
    public:
        Combate();
        ~Combate();
        void AdicionaNave(int nave);
        TipoCelula* PosicionaAntes(int nave);
        int RemoveNave(int nave);

    private:
        int tamanho;
        TipoCelula* celula_cabeca;
        TipoCelula* ultima_nave;
};

#endif // COMBATE_H