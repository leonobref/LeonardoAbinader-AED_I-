#include <stdio.h>
#include <stdlib.h>

#include "hash_inteiro_ligada.h"

void inicializar_hash(Tabela_Hash tabela){
    for(int i = 0; i < MAX ; i++)
        tabela[i] = NULL;
}

int chave_hash(int chave){
    return (((2 * chave) + 5 ) % MAX);
}

void inserir(Tabela_Hash tabela, int numero){
    int chave = chave_hash(numero);
    Elemento *anterior = NULL;
    Elemento *i= tabela[chave];
    while(i != NULL){
        if(i -> numero == numero)
            return;
        anterior = i;
        i = i -> proximo;
    }
    if (i == NULL){
        i = malloc (sizeof(Elemento));
        i -> numero = numero;
        i -> proximo = NULL;
        if (anterior == NULL)
            tabela[chave] = i;
        else
            anterior ->proximo = i;
    }
}

void imprimir_hash(Tabela_Hash tabela){
    Elemento *i;
    for(int j = 0; j < MAX; j++){
        if (tabela[j] != NULL){
            i = tabela[j];
            printf("Modulo: %d ||", j);
            while(i != NULL){
                printf(" Elemento: %d -->", i->numero);
                i = i -> proximo;
            }
            printf(" VAZIO\n");
        }
        else
            printf("Modulo: %d VAZIO\n", j);
    }
}

int* busca(Tabela_Hash tabela, int numero){
    int chave = chave_hash(numero);
    Elemento *i= tabela[chave];
    while (i != NULL){
        if(i ->numero == numero)
            return &i->numero;
        i = i -> proximo;
    }
    return NULL;
}