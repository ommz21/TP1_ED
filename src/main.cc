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
    scanf("%d",&num_frotas);
    for(int i = 0; i < num_frotas; i++)
    {
        scanf("%d",&id_nave);
        naves_em_aguardo.AdicionaNave(id_nave);
    }
    while(scanf("%d", &operacao) != EOF)
    {
        switch (operacao)
        {
            case 0:
                id_nave = naves_em_aguardo.RemoveNave();
                printf("nave %d em combate\n", id_nave);
                naves_em_combate.AdicionaNave(id_nave);
                break;
            
            case -1:
                id_nave = naves_avariadas.RemoveNave();
                printf("nave %d consertada\n", id_nave);
                naves_em_aguardo.AdicionaNave(id_nave);
                break;
            
            case -2:
                naves_em_aguardo.ImprimeNaves();
                break;
            
            case -3:
                naves_avariadas.ImprimeNaves();
                break;
            
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