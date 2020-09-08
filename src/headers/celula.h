#ifndef CELULA_H
#define CELULA_H

//Assinatura dos atributos e metodos da classe TipoCelula
class TipoCelula
{
    public:
        TipoCelula();

    private:
        int item;
        TipoCelula *prox;
        friend class Aguarda;
        friend class Combate;
        friend class Avariada;
};

#endif // CELULA_H