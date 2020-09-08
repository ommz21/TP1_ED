#ifndef AGUARDA_H
#define AGUARDA_H

#include "celula.h"

//Assinatura dos atributos e metodos da classe Aguarda
class Aguarda
{
    public:
        Aguarda();
        ~Aguarda();
        int GetTamanho();
        bool Vazia();
        void AdicionaNave(int nave);
        int RemoveNave();
        void Limpa();
        void ImprimeNaves();

    private:
        int tamanho;
        TipoCelula* nave_mais_apta;
};

#endif // AGUARDA_H