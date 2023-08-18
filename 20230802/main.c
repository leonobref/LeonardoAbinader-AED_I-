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


    listar_arvore(&a);
    return 0;
}
