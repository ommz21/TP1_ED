#include <iostream>
#include "headers/aguarda.h"
#include "headers/combate.h"
#include "headers/avariada.h"

int main()
{
    int num_frotas, id_nave, operacao;
    Aguarda naves_em_aguardo;
    Combate naves_em_combate;
    Avariada naves_avariadas;

    //Leitura da quantidade de naves e dos seus respectivos identificadores
    scanf("%d",&num_frotas);
    for(int i = 0; i < num_frotas; i++)
    {
        scanf("%d",&id_nave);
        //Armazena as naves em aguardo utilizando a classe Aguarda(pilha encadeada)
        naves_em_aguardo.AdicionaNave(id_nave);
    }

    //Laco de leitura da operacao a ser executada ate o fim da entrada
    while(scanf("%d", &operacao) != EOF)
    {
        switch (operacao)
        {
            //Operacao para remover a primeira nave em aguardo(desempilha)
            //e adiciona na lista de naves em combate
            case 0:
                id_nave = naves_em_aguardo.RemoveNave();
                printf("nave %d em combate\n", id_nave);
                naves_em_combate.AdicionaNave(id_nave);
                break;
            
            //Operacao para remover a nave que foi avariada ha mais tempo(desenfileira)
            //e adicionar na estrutura de naves em aguardo(empilha)
            case -1:
                id_nave = naves_avariadas.RemoveNave();
                printf("nave %d consertada\n", id_nave);
                naves_em_aguardo.AdicionaNave(id_nave);
                break;
            
            //Operacao para imprimir as naves em aguardo respeitando a ordem da estrutura(pilha)
            case -2:
                naves_em_aguardo.ImprimeNaves();
                break;
            
            //Operacao para imprimir as naves avariadas respeitando a ordem da estrutura(fila)
            case -3:
                naves_avariadas.ImprimeNaves();
                break;
            
            //Operacao para remover da lista de naves em combate a nave que possui o id informado
            //e adicionar na estrutura de naves avariadas(enfileira)
            default:
                id_nave = operacao;
                naves_em_combate.RemoveNave(id_nave);
                printf("nave %d avariada\n", id_nave);
                naves_avariadas.AdicionaNave(id_nave);
                break;
        }
    }
    return 0;
}