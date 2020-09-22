#include <iostream>
#include "combate.h"

//Implementacao do metodo construtor da classe Combate(a lista possui celula cabeca).
Combate::Combate()
{
    tamanho = 0;
    celula_cabeca = new TipoCelula;
    ultima_nave = celula_cabeca;
}

//Desaloca todas as celulas alocadas pela lista(inclusive a celula cabeca)
Combate::~Combate()
{
    TipoCelula *removida;
    removida = celula_cabeca->prox_nave;
    while(removida != nullptr)
    {
        celula_cabeca->prox_nave = removida->prox_nave;
        delete removida;
        removida = celula_cabeca->prox_nave;
    }
    ultima_nave = celula_cabeca;
    tamanho = 0;
    delete celula_cabeca;
}

//Equivalente ao metodo visto em aula de adicionar um elemento ao final da lista encadeada
void Combate::AdicionaNave(int nave)
{
    TipoCelula *nova = new TipoCelula();
    nova->id_nave = nave;
    ultima_nave->prox_nave = nova;
    ultima_nave = nova;
    tamanho++;
}

//Metodo retorna o ponteiro da celula anterior a uma celula que possua o identificador de nave
//recebido como parametro
TipoCelula* Combate::PosicionaAntes(int nave)
{
    TipoCelula *retorno = celula_cabeca;
    while(retorno->prox_nave->id_nave != nave)
        retorno = retorno->prox_nave;
    return retorno;
}

//Equivalente ao metodo visto em aula para remover um elemento em qualquer posicao da lista encadeada
int Combate::RemoveNave(int nave)
{
    int id_nave_retirada;
    TipoCelula *nave_retirada;
    TipoCelula *aux;
    //Utiliza o metodo para encontrar a celula anterior a que se deseja remover da lista
    aux = PosicionaAntes(nave);
    if(aux == nullptr)
        throw std::invalid_argument("Nao possui nenhuma nave com esse id em combate.");
    nave_retirada = aux->prox_nave;
    id_nave_retirada = nave_retirada->id_nave;
    aux->prox_nave = nave_retirada->prox_nave;
    delete nave_retirada;
    tamanho--;
    if(aux->prox_nave == nullptr)
        ultima_nave = aux;
    return id_nave_retirada;
}