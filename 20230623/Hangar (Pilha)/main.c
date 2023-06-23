#include <stdio.h>
#include <stdlib.h>

#include "hangar_pilha.h"

int main()
{   
    Pilha Hangar;
    inicializar_pilha(&Hangar);

    Aviao a;
    a.identificador = 1;
    a.nomeaviao = "Boing 777";
    adicionar_aviao(&Hangar, a);

    a.identificador = 2;
    a.nomeaviao = "Omnibus Espacial 3000";
    adicionar_aviao(&Hangar, a);

    a.identificador = 3;
    a.nomeaviao = "Reino do Urubu";
    adicionar_aviao(&Hangar, a);

    a.identificador = 4;
    a.nomeaviao = "Aviao do Palmeiras";
    adicionar_aviao(&Hangar, a);

    a.identificador = 5;
    a.nomeaviao = "Starlink do Elonmusk";
    adicionar_aviao(&Hangar, a);

    a.identificador = 6;
    a.nomeaviao = "Submarino Implodido";
    adicionar_aviao(&Hangar, a);

    a.identificador = 7;
    a.nomeaviao = "Titanic Voador";
    adicionar_aviao(&Hangar, a);

    a.identificador = 8;
    a.nomeaviao = "Jatinho do Neymar";
    adicionar_aviao(&Hangar, a);

    a.identificador = 9;
    a.nomeaviao = "FlaEmirates";
    adicionar_aviao(&Hangar, a);

    printar_avioes(&Hangar);

    remover_aviao(&Hangar);
    remover_aviao(&Hangar);

    printf("\n\nListar avioes apos remover dois do topo.");
    printar_avioes(&Hangar);

    printf("\n\nListar avioes apos remover o aviao da posicao 3.");
    remover_aviao_posicao(&Hangar, 3);

    printar_avioes(&Hangar);
    return 0;
}