#include <stdio.h>
#include <stdlib.h>

#include "pista_fila.h"

int main()
{   
    Fila Pista;
    inicializar_fila(&Pista);

    Aviao a;
    a.identificador = 1;
    a.nomeaviao = "Boing 777";
    adicionar_aviao(&Pista, a);

    a.identificador = 2;
    a.nomeaviao = "Omnibus Espacial 3000";
    adicionar_aviao(&Pista, a);

    a.identificador = 3;
    a.nomeaviao = "Reino do Urubu";
    adicionar_aviao(&Pista, a);

    printar_avioes(&Pista);
    printar_primeiro_aviao(&Pista);

    printf("\n%d Avioes na fila para para Decolar.", retornar_numero_avioes(&Pista));
    
    printf("\n\nDecolando o aviao: %d", Pista.inicio->avi.identificador);
    decolar(&Pista);
    printar_avioes(&Pista);
    printf("\n\nDecolando o aviao: %d", Pista.inicio->avi.identificador);
    decolar(&Pista);
    printar_avioes(&Pista);
    return 0;
}
