#include <stdio.h>
#include "Arvore_AVL.h"

int main()
{
    Arvore a;
    inicializar_Arvore(&a);

    adiciona_arvore(&a, 1);
    adiciona_arvore(&a, 2);
    adiciona_arvore(&a, 3);
    adiciona_arvore(&a, 4);
    adiciona_arvore(&a, 5);
    adiciona_arvore(&a, 6);
    adiciona_arvore(&a, 7);
    adiciona_arvore(&a, 15);
    adiciona_arvore(&a, 14);
    adiciona_arvore(&a, 13);
    adiciona_arvore(&a, 12);
    adiciona_arvore(&a, 11);
    adiciona_arvore(&a, 10);
    adiciona_arvore(&a, 9);
    adiciona_arvore(&a, 8);

    printf("Numero de elementos da arvore: %d\n\n", contar_arvore(&a));
    listar_arvore(&a);

    printf("\nBuscando o Elemento que contem o numero 10.\n\n");
    No* Buscado = buscar_no(&a, 10);
    printf("Resultado da Busca: \n");
    printf("Numero Buscado: %d\n", Buscado->numero);
    printf("Numero a esquerda do Buscado: %d\n", Buscado->esquerda->numero);
    printf("Numero a direita do Buscado: %d\n", Buscado->direita->numero);
    
    printf("\n");
    listar_preordem(&a);
    printf("\n");
    listar_inordem(&a);
    printf("\n");
    listar_posordem(&a);

    return 0;
}
