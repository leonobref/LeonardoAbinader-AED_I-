#include <stdio.h>
#include <stdlib.h>

#include "lista_duplamente_ligada.h"

void inicaliza_lista(Lista *L){
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
    printf("\n----------Elementos da lista----------");
    while (i != NULL){
        printf("\nElemento %d", i->numero);
        i = i -> proximo;
    }
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

void inserir_elemento_ordenado(Lista *L, int novonumero){
    Elemento *predecessor;
    Elemento *i;
    i = busca_elemento_e_predecessor(L, novonumero, &predecessor);
    if (i != NULL) // Se já houber um número igual, encerrar função.
        return;
    
    i = malloc (sizeof(Elemento));
    i->numero = novonumero;
    if (predecessor == NULL) { //Insere um novo elemento no inicio da lista.
        i->proximo = L->inicio;
        i->anterior = NULL;
        L -> inicio = i;
    }
    else if (predecessor -> proximo == NULL) { //Insere um novo elemento no final da lista.
        i->proximo = predecessor -> proximo;
        i->anterior = predecessor;
        predecessor -> proximo = i;
    }
    else{ //Insere um novo elemento de forma ordenada.
        i -> proximo = predecessor -> proximo;
        i -> anterior = predecessor;
        predecessor -> proximo -> anterior = i;
        predecessor -> proximo = i;
    }
}

void inserir_elemento_final(Lista *L, int novonumero){
    Elemento *i , *j, *predecessor = NULL;
    i = retornar_endereco_elemento(L, novonumero);
    if (i != NULL) // Se já houber um número igual, encerrar função.
        return;
    j = L -> inicio;
    while (j != NULL){
        predecessor = j;
        j = j -> proximo;
    }
    i = malloc (sizeof(Elemento));
    i->numero = novonumero;
    if (predecessor == NULL) { //Insere um novo elemento no inicio da lista.
        i->proximo = L->inicio;
        i->anterior = NULL;
        L -> inicio = i;
    }
    else{ //Insere um novo elemento no final da lista.
        i->proximo = predecessor -> proximo;
        i->anterior = predecessor;
        predecessor -> proximo = i;
    }
}

void excluir_elemento(Lista *L, int numeroexcluir){
    Elemento *predecessor, *i;
    i = busca_elemento_e_predecessor(L, numeroexcluir, &predecessor);
    if (i  == NULL)
        return;
    if (predecessor == NULL){
        L -> inicio = i -> proximo;
        i -> proximo -> anterior = NULL;
    }
    else{
        predecessor -> proximo = i -> proximo;
        i -> proximo -> anterior = predecessor;
    }
    free(i);
}

Elemento *retornar_endereco_elemento(Lista *L, int numerobuscado){
    Elemento *atual = L -> inicio;
    while((atual != NULL) && (atual -> numero < numerobuscado)){
        atual = atual -> proximo; 
    }
    if ((atual != NULL) && (atual -> numero == numerobuscado))
        return atual;
    return NULL;
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

//Exercicio
int retornar_maior_numero(Lista *L){
    Elemento *i;
    i = L->inicio;
    if (i == NULL){
        return -1;
    }
    int maior = i ->numero;
    i = i -> proximo;
    while(i != NULL){
        if (i -> numero > maior){
            maior = i -> numero;
        }
        i = i -> proximo;
    }
    return maior;
}

void reoordena_e_transfere(Lista *L, Lista *K){
    inicaliza_lista(K);

    Elemento *i = L -> inicio;
    if (i == NULL){
        return;
    }
    Elemento *novoelemento = NULL, *sucessor = NULL;
    int maior;
    int tam = retornar_tamanho(L);

    for(int j = 0; j < tam; j++){
        maior = retornar_maior_numero(L);
        novoelemento = retornar_endereco_elemento(L, maior);
        if (novoelemento == NULL)
            break;
        
        if (novoelemento->anterior == NULL){
            L -> inicio = novoelemento -> proximo;
            if(novoelemento -> proximo != NULL)
                novoelemento->proximo->anterior = NULL;
        }
        else{
            novoelemento->anterior ->proximo = novoelemento -> proximo;
            if(novoelemento -> proximo != NULL)
                novoelemento->proximo ->anterior = novoelemento -> anterior;
        }

        sucessor = K -> inicio;
        K -> inicio = novoelemento;
        novoelemento -> proximo = sucessor;
        novoelemento -> anterior = NULL;
        if (sucessor != NULL)
            sucessor->anterior = novoelemento;
    }
    L -> inicio = NULL;
}