#include <stdlib.h>
#include <stdio.h>

#include "lista_linear_sequencial.h"

int main()
{
    Lista *L;
    inicializa_lista(&L);

    printf("Tamanho lista: %d\n", tamanho_lista(L));

    inserir_elemento_comeco(L, 22);
    inserir_elemento_ordenado(L , 18);
    inserir_elemento_ordenado(L , 33);
    inserir_elemento_ordenado(L , 30);
    inserir_elemento_ordenado(L , 12);
    inserir_elemento_ordenado(L , 20);
    inserir_elemento_ordenado(L , 12);

    inserir_elemento_final(L, 4);
    inserir_elemento_posicao(L, 3, 45);

    excluir_elemento_final(L);
    excluir_elemento_comeco(L);
    inserir_elemento_ordenado(L, 12);
    excluir_elemento_valor(L, 45);

    imprimir_elementos(L);
    printf("\nTamanho lista: %d\n", tamanho_lista(L));

    liberar_lista(&L);
    return 0;
}


