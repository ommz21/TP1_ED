#include <iostream>
#include "avariada.h"

//Implementacao dos metodos da classe Avariada.
Avariada::Avariada()
{
    tamanho = 0;
    celula_cabeca = new TipoCelula;
    ultima_nave = celula_cabeca;
}

Avariada::~Avariada()
{
    Limpa();
    delete celula_cabeca;
}

int Avariada::GetTamanho()
{
    return tamanho;
}

bool Avariada::Vazia()
{
    return tamanho == 0;
}

void Avariada::AdicionaNave(int nave)
{
    TipoCelula *nova = new TipoCelula();
    nova->item = nave;
    ultima_nave->prox = nova;
    ultima_nave = nova;
    tamanho++;
}

int Avariada::RemoveNave()
{
    int id_nave_retirada;
    TipoCelula *nave_retirada;
    if(tamanho == 0)
        throw std::invalid_argument("Nao possui nenhuma nave avariada.");
    nave_retirada = celula_cabeca;
    id_nave_retirada = nave_retirada->prox->item;
    celula_cabeca = nave_retirada->prox;
    delete nave_retirada;
    tamanho--;
    return id_nave_retirada;
}

void Avariada::Limpa()
{
    TipoCelula *removida;
    while(tamanho)
    {
        removida = celula_cabeca->prox;
        celula_cabeca = removida->prox;
        delete removida;
        tamanho--;
    }
    ultima_nave = celula_cabeca;
}

void Avariada::ImprimeNaves()
{
    TipoCelula *atual = celula_cabeca->prox;
    while(atual != nullptr)
    {
        printf("%d\n", atual->item);
        atual = atual->prox;
    }
}