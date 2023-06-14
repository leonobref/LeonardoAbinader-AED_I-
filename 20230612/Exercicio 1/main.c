#include <stdio.h>
#include <stdlib.h>

#include "lista_duplamente_ligada.h"

int main()
{
    Lista L;
    inicaliza_lista(&L);

    inserir_elemento_final(&L, 22);
    inserir_elemento_final(&L, 18);
    inserir_elemento_final(&L, 33);
    inserir_elemento_final(&L, 30);
    inserir_elemento_final(&L, 12);
    inserir_elemento_final(&L, 20);

    printf("Printar elementos da Lista L.");
    printar_lista(&L);

    printf("\n\nCriar uma lista K ordenada com os elementos da lista L.");
    Lista K;
    reoordena_e_transfere(&L, &K);
    printar_lista(&K);

    return 0;
}
