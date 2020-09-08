#include <iostream>
#include "combate.h"

//Implementacao dos metodos da classe Combate.
Combate::Combate()
{
    tamanho = 0;
    celula_cabeca = new TipoCelula;
    ultima_nave = celula_cabeca;
}

Combate::~Combate()
{
    Limpa();
    delete celula_cabeca;
}

int Combate::GetTamanho()
{
    return tamanho;
}

bool Combate::Vazia()
{
    return tamanho == 0;
}

void Combate::AdicionaNave(int nave)
{
    TipoCelula *nova = new TipoCelula();
    nova->item = nave;
    ultima_nave->prox = nova;
    ultima_nave = nova;
    tamanho++;
}

TipoCelula* Combate::PosicionaAntes(int nave)
{
    TipoCelula *retorno = celula_cabeca;
    while(retorno->prox->item != nave)
        retorno = retorno->prox;
    return retorno;
}

int Combate::RemoveNave(int nave)
{
    int id_nave_retirada;
    TipoCelula *nave_retirada;
    TipoCelula *aux;
    aux = PosicionaAntes(nave);
    if(aux == nullptr)
        throw std::invalid_argument("Nao possui nenhuma nave com esse id em combate.");
    nave_retirada = aux->prox;
    id_nave_retirada = nave_retirada->item;
    aux->prox = nave_retirada->prox;
    delete nave_retirada;
    tamanho--;
    if(aux->prox == nullptr)
        ultima_nave = aux;
    return id_nave_retirada;
}

void Combate::Limpa()
{
    TipoCelula *removida;
    while(tamanho)
    {
        removida = celula_cabeca->prox;
        celula_cabeca->prox = removida->prox;
        delete removida;
        tamanho--;
    }
    ultima_nave = celula_cabeca;
}