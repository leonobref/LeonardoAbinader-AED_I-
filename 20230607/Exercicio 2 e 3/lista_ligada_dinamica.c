#include <stdio.h>
#include <stdlib.h>

#include "lista_ligada_dinamica.h"

void inicializa_lista(Lista *L){
    L -> inicio = NULL;
}

void reinicializar_lista(Lista *L){
    Elemento *apagar;
    Elemento *aux = L -> inicio;
    while (aux != NULL){
        Elemento *apagar = aux;
        aux = aux -> proximo;
        free (apagar);
    }
    L -> inicio = NULL;
}

int retornar_tamanho(Lista *L){
    int tam = 0;
    Elemento *i = L -> inicio;
    while (i != NULL){
        tam ++;
        i = i -> proximo;
    }
    return tam;
}

void printar_lista(Lista *L){
    Elemento *i = L -> inicio;
    printf("\n----------Imprimindo Elementos----------");
    while (i != NULL){
        printf("\nElemento: %d.", i->numero);
        i = i -> proximo;
    }
}

int retornar_vazia(Lista *L){
    if (L -> inicio == NULL)
        return 1;
    else
        return -1;
}

Elemento *busca_elemento_e_predecessor(Lista *L, int numerobuscado, Elemento **pred){
    *pred = NULL;
    Elemento *atual = L -> inicio;
    while((atual != NULL) && (atual -> numero < numerobuscado)){
        *pred = atual;
        atual = atual -> proximo; 
    }
    if ((atual != NULL) && (atual -> numero == numerobuscado))
        return atual;
    return NULL;
}

void inserir_numero_ordenado_crescente(Lista *L, int novonumero){
    Elemento *pred, *i;
    i = busca_elemento_e_predecessor(L, novonumero, &pred);
    if (i != NULL)
        return;
    i = malloc (sizeof(Elemento));
    i->numero = novonumero;
        if (pred == NULL){
        i -> proximo = L -> inicio;
        L -> inicio = i;
    }
    else{
        i-> proximo = pred -> proximo;
        pred -> proximo = i;
    }
}
void inserir_numero_final(Lista *L, int novonumero){
    Elemento *i = L ->inicio;
    Elemento *ult = NULL;
    
    if (i == NULL){
        i = malloc (sizeof(Elemento));
        i ->numero = novonumero;
        i -> proximo = NULL;
        L ->inicio = i;
        return;
    }
    while(i != NULL){
        ult = i;
        i = i ->proximo;
    }
    i = malloc (sizeof(Elemento));
    i->numero = novonumero;
    ult -> proximo = i;
    i -> proximo = NULL;
}

void excluir_numero_ordenado(Lista *L, int numero){
    Elemento *predecessor;
    Elemento *i;
    i = busca_elemento_e_predecessor(L, numero, &predecessor);
    if (i == NULL)
        return;
    if (predecessor == NULL)
        L -> inicio = i -> proximo;
    else
        predecessor -> proximo = i -> proximo;
    free(i);
}