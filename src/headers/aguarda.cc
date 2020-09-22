#include <iostream>
#include "aguarda.h"

//Implementacao do construtor da classe Aguarda.
Aguarda::Aguarda()
{
    tamanho = 0;
    nave_mais_apta = nullptr;
}

//Desaloca toda a memória alocada dinamicamente pela classe
Aguarda::~Aguarda()
{
    TipoCelula *removida;
    removida = nave_mais_apta;
    while(removida != nullptr)
    {
        nave_mais_apta = nave_mais_apta->prox_nave;
        delete removida;
        removida = nave_mais_apta;
    }
    tamanho = 0;
}

//Equivalente ao método Empilha visto em aula
void Aguarda::AdicionaNave(int nave)
{
    TipoCelula *nova = new TipoCelula();
    nova->id_nave = nave;
    nova->prox_nave = nave_mais_apta;
    nave_mais_apta = nova;
    tamanho++;
}

//Equivalente ao método Desempilha visto em aula
int Aguarda::RemoveNave()
{
    int id_nave_retirada;
    TipoCelula *nave_retirada;
    if(tamanho == 0)
        throw std::invalid_argument("Nao possui nenhuma nave aguardado.");
    nave_retirada = nave_mais_apta;
    nave_mais_apta = nave_mais_apta->prox_nave;
    id_nave_retirada = nave_retirada->id_nave;
    delete nave_retirada;
    tamanho--;
    return id_nave_retirada;
}

//Percorre toda a pilha imprimindo os identificadores(inicia no topo e termina na base da pilha)
void Aguarda::ImprimeNaves()
{
    TipoCelula *atual = nave_mais_apta;
    while(atual != nullptr)
    {
        printf("%d\n", atual->id_nave);
        atual = atual->prox_nave;
    }
}