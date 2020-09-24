#include <iostream>
#include "avariada.h"

//Implementacao do metodo construtor da classe Avariada(a fila possui uma celula cabeca).
Avariada::Avariada()
{
    tamanho = 0;
    frente = new TipoCelula;
    tras = frente;
}

//Desaloca todas as celulas alocadas pela fila(inclusive a celula cabeca)
Avariada::~Avariada()
{
    TipoCelula *removida;
    removida = frente;
    while(removida != nullptr)
    {
        frente = removida->prox_nave;
        delete removida;
        removida = frente;
    }
    tamanho = 0;
    delete frente;
}

//Equivalente ao metodo Enfileira visto em aula
void Avariada::AdicionaNave(int nave)
{
    TipoCelula *nova = new TipoCelula();
    nova->id_nave = nave;
    tras->prox_nave = nova;
    tras = nova;
    tamanho++;
}

//Equivalente ao metodo Desenfileira visto em aula
int Avariada::RemoveNave()
{
    int id_nave_retirada;
    TipoCelula *nave_retirada;
    if(tamanho == 0)
        throw std::invalid_argument("Nao possui nenhuma nave avariada.");
    nave_retirada = frente;
    id_nave_retirada = nave_retirada->prox_nave->id_nave;
    frente = nave_retirada->prox_nave;
    delete nave_retirada;
    tamanho--;
    return id_nave_retirada;
}

//Percorre toda a fila imprimindo os identificadores(percorre a fila indo da celula cabeca ate a ultima nave)
void Avariada::ImprimeNaves()
{
    TipoCelula *atual = frente->prox_nave;
    if(tamanho == 0)
        throw std::invalid_argument("Nao possui nenhuma nave avariada.");
    while(atual != nullptr)
    {
        printf("%d\n", atual->id_nave);
        atual = atual->prox_nave;
    }
}