#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"

 int main(){
    int t, number;
    List *Lista1, *Lista2;
    printf("Digite o tamanho de uma lista: ");
    scanf("%d", &t);
    Lista1 = create_list(t);
    insert_numbersnio(Lista1);
    printf("\nElementos da Lista 1.\n");
    print_list_iterative(Lista1);
    printf("\n\nDigite um numero a ser procurado na lista 1: ");
    scanf("%d", &number);
    sequencial_search(Lista1, number);
    Lista2 = create_list(30);
    insert_numbersio(Lista2);
    printf("\n\nElementos da Lista 2.\n");
    print_list_recursive(Lista2, 0, Lista2->quantity);
    printf("\n\nDigite um numero a ser procurado na lista 2: ");
    scanf("%d", &number);
    sequencial_search(Lista2, number);
    sequencial_search_ordened(Lista2, number);
    binary_search_iterative(Lista2, number);
    binary_search_recursive(Lista2, number, 0, Lista2 -> quantity - 1, 1);
   
    printf("\n\nMaior e Menor elemento da lista 1: (Buscado de forma Iterativa)");
    search_biggest_number_iterative(Lista1);
    search_lowest_number_iterative(Lista1);

    printf("\n\nMaior e Menor elemento da lista 1: (Buscado de forma Recursiva)");
    search_biggest_number_recursive(Lista1, 0, 0);
    search_lowest_number_recursive(Lista1, 0, 0);

    printf("\n\nSoma dos elementos da lista 1: %d (Buscado de forma Iterativa)", sum_all_numbers_iterative(Lista1));
    printf("\nSoma dos elementos da lista 1: %d (Buscado de forma Recursiva)", sum_all_numbers_recursive(Lista1, 0));

    printf("\n\nProduto dos elementos da lista 1: %d (Buscado de Foram Iterativa)", product_all_numbers_iterative(Lista1));
    printf("\nProduto dos elementos da lista 1: %d (Buscado de Foram Recursiva)", product_all_numbers_recursive(Lista1, 0));

    return 0;
 }