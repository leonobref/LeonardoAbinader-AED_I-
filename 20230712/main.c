#include "hash_inteiro_ligada.h"
#include <stdio.h>

int main()
{
    Tabela_Hash A;
    inicializar_hash(A);
    inserir(A, 12);
    inserir(A, 44);
    inserir(A, 13);
    inserir(A, 88);
    inserir(A, 23);
    inserir(A, 94);
    inserir(A, 11);
    inserir(A, 39);
    inserir(A, 20);
    inserir(A, 16);
    inserir(A, 5);
    printf("\nImprimindo a Tabela Hash para MAX = %d\n\n", MAX);

    imprimir_hash(A);
    return 0;
}
