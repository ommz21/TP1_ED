#ifndef COMBATE_H
#define COMBATE_H

#include "celula.h"

//Assinatura dos atributos e metodos da classe Combate
class Combate
{
    public:
        Combate();
        ~Combate();
        int GetTamanho();
        bool Vazia();
        void AdicionaNave(int nave);
        TipoCelula* PosicionaAntes(int nave);
        int RemoveNave(int nave);
        void Limpa();

    private:
        int tamanho;
        TipoCelula* celula_cabeca;
        TipoCelula* ultima_nave;
};

#endif // COMBATE_H