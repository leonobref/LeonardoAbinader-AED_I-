#include <stdio.h>
#include <stdlib.h>

#include "hangar_pilha.h"

void inicializar_pilha(Pilha *P){
    P -> topo = NULL;
}

void reinicializar_pilha(Pilha *P){
    Elemento *apagar;
    Elemento *aux = P -> topo;
    while (aux != NULL){
        apagar = aux;
        aux = aux -> proximo;
        free (apagar);
    }
    P -> topo = NULL;
}

void remover_aviao(Pilha *P){
    if (P -> topo == NULL)
        return;
    Elemento *i =  P -> topo;
    P -> topo = P -> topo -> proximo;
    free(i);
}

void adicionar_aviao(Pilha *P, Aviao a){
    Elemento *i;
    i = malloc (sizeof(Elemento));
    if (i == NULL)
        return;
    i -> avi = a;
    i -> proximo = P -> topo;
    P -> topo = i;
}

int retornar_numero_avioes(Pilha *P){
    if (P -> topo == NULL)
        return 0;
    int tam = 0;
    Elemento *i = P -> topo;
    while (i != NULL){
        tam++;
        i = i ->proximo;
    }
    return tam;
}

void printar_avioes(Pilha *P){
    Elemento *i = P -> topo;
    if (i != NULL){
    printf("\n----------Listando Avioes do Hangar----------");
    int a = retornar_numero_avioes(P);
    while (i != NULL){
        printf("\nIdentificador: %d Aviao: %s ||| Posicao %d.", i->avi.identificador, i->avi.nomeaviao, a);
        i = i -> proximo;
        a--;
    }
    }
}

void printar_primeiro_aviao(Pilha *P){
    if (P -> topo != NULL){
    printf("\n----------Imprimindo Primeiro Aviao----------");
    printf("\nIdentificador: %d Aviao: %s", P -> topo -> avi.identificador, P -> topo ->avi.nomeaviao);
    }
}

Aviao primeiroAviao(Pilha *P){
    return P -> topo -> avi;
}

void remover_aviao_posicao(Pilha *P, int pos){
    Pilha a;
    inicializar_pilha(&a);
    if (pos > retornar_numero_avioes(P) || pos <= 0)
        return;
    int b = retornar_numero_avioes(P) - pos;
    for(int i = 0; i < b; i++){
        adicionar_aviao(&a, primeiroAviao(P));
        remover_aviao(P);
    }
    remover_aviao(P);
    for(int i = 0; i < b; i++){
        adicionar_aviao(P, primeiroAviao(&a));
        remover_aviao(&a);
    }
};