#ifndef AVARIADA_H
#define AVARIADA_H

#include "celula.h"

//Assinatura dos atributos e metodos da classe Avariada que eh uma fila encadeada
class Avariada
{
    public:
        Avariada();
        ~Avariada();
        void AdicionaNave(int nave);
        int RemoveNave();
        void ImprimeNaves();

    private:
        int tamanho;
        TipoCelula* frente;
        TipoCelula* tras;
};

#endif // AVARIADA_H