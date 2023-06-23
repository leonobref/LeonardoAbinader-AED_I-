#include <stdio.h>
#include <stdlib.h>

#include "pista_fila.h"

void inicializar_fila(Fila *F){
    F -> inicio = NULL;
    F -> fim = NULL;
}

void reinicializar_fila(Fila *F){
    Elemento *apagar;
    Elemento *aux = F -> inicio;
    while (aux != NULL){
        apagar = aux;
        aux = aux -> proximo;
        free (apagar);
    }
    F -> inicio = NULL;
    F -> fim = NULL;
}

void adicionar_aviao(Fila *F, Aviao a){
    Elemento *i;
    i = malloc (sizeof(Elemento));
    if (i == NULL)
        return;
    i->avi = a;
    i-> proximo = NULL;
    if (F -> inicio == NULL){
        F -> inicio = i;
        F -> fim = i;
    }
    else{
        F -> fim -> proximo = i;
        F -> fim = i;
    }
}

void decolar(Fila *F){
    if (F -> inicio == NULL)
        return;
    Elemento *i =  F->inicio;
    F -> inicio = F -> inicio -> proximo;
    free(i);
}

int retornar_numero_avioes(Fila *F){
    if (F -> inicio == NULL)
        return 0;
    int tam = 0;
    Elemento *i = F -> inicio;
    while (i != NULL){
        tam++;
        i = i ->proximo;
    }
    return tam;
}

void printar_avioes(Fila *F){
    Elemento *i = F -> inicio;
    if (i != NULL){
    printf("\n----------Listando Avioes----------");
    while (i != NULL){
        printf("\nIdentificador: %d Aviao: %s", i->avi.identificador, i->avi.nomeaviao);
        i = i -> proximo;
    }
    }
}

void printar_primeiro_aviao(Fila *F){
    if (F -> inicio != NULL){
    printf("\n----------Imprimindo Primeiro Aviao----------");
    printf("\nIdentificador: %d Aviao: %s", F -> inicio->avi.identificador, F -> inicio->avi.nomeaviao);
    }
}