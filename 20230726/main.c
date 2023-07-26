#include <stdio.h>
#include "Arvore.h"

int main()
{
    Arvore a;
    inicializar_arvore(&a);

    adiciona_arvore(&a, 24);
    adiciona_arvore(&a, 10);
    adiciona_arvore(&a, 32);
    adiciona_arvore(&a, 5);
    adiciona_arvore(&a, 12);
    adiciona_arvore(&a, 29);
    adiciona_arvore(&a, 35);

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
