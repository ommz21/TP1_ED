#include <iostream>
#include "aguarda.h"

//Implementacao dos metodos da classe Aguarda.
Aguarda::Aguarda()
{
    tamanho = 0;
    nave_mais_apta = nullptr;
}

Aguarda::~Aguarda()
{
    Limpa();
}

int Aguarda::GetTamanho()
{
    return tamanho;
}

bool Aguarda::Vazia()
{
    return tamanho == 0;
}

void Aguarda::AdicionaNave(int nave)
{
    TipoCelula *nova = new TipoCelula();
    nova->item = nave;
    nova->prox = nave_mais_apta;
    nave_mais_apta = nova;
    tamanho++;
}

int Aguarda::RemoveNave()
{
    int id_nave_retirada;
    TipoCelula *nave_retirada;
    if(tamanho == 0)
        throw std::invalid_argument("Nao possui nenhuma nave aguardado.");
    nave_retirada = nave_mais_apta;
    nave_mais_apta = nave_mais_apta->prox;
    id_nave_retirada = nave_retirada->item;
    delete nave_retirada;
    tamanho--;
    return id_nave_retirada;
}

void Aguarda::Limpa()
{
    TipoCelula *removida;
    removida = nave_mais_apta;
    while(removida != nullptr)
    {
        nave_mais_apta = nave_mais_apta->prox;
        delete removida;
        removida = nave_mais_apta;
    }
    tamanho = 0;
}

void Aguarda::ImprimeNaves()
{
    TipoCelula *atual = nave_mais_apta;
    while(atual != nullptr)
    {
        printf("%d\n", atual->item);
        atual = atual->prox;
    }
}