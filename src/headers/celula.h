#ifndef CELULA_H
#define CELULA_H

//Assinatura dos atributos e metodos da classe TipoCelula
class TipoCelula
{
    public:
        TipoCelula();

    private:
        int id_nave;
        TipoCelula *prox_nave;

        //Permite que as TADs possam acessar os atributos privados de TipoCelula
        friend class Aguarda;
        friend class Combate;
        friend class Avariada;
};

#endif // CELULA_H