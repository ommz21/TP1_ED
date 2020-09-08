#ifndef AVARIADA_H
#define AVARIADA_H

#include "celula.h"

//Assinatura dos atributos e metodos da classe Avariada
class Avariada
{
    public:
        Avariada();
        ~Avariada();
        int GetTamanho();
        bool Vazia();
        void AdicionaNave(int nave);
        int RemoveNave();
        void Limpa();
        void ImprimeNaves();

    private:
        int tamanho;
        TipoCelula* celula_cabeca;
        TipoCelula* ultima_nave;
};

#endif // AVARIADA_H