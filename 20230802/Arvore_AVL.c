#include <stdio.h>
#include <stdlib.h>

#include "Arvore_AVL.h"


void inicializar_Arvore(Arvore *a){
    a->Raiz = NULL;
}

No *criarno (int numero){
    No *novono = malloc(sizeof(No));
    novono->numero = numero;
    novono->h = 0;
    novono->esquerda = NULL;
    novono->direita = NULL;
    return (novono);
}

int altura (No *raiz){
    if(raiz == NULL)
        return -1;
    else
        return (raiz->h);
}

int maximo(int a, int b){
    if (a > b)
        return a;
    else
        return b;
}

No *rot_direita(No* no_desb){
    No* aux;
    aux = no_desb->esquerda;
    no_desb->esquerda = aux->direita;
    aux->direita = no_desb;

    no_desb->h = maximo(altura(no_desb->direita), altura(no_desb->esquerda)) + 1;

    aux->h = maximo(altura(aux->esquerda), altura(no_desb)) + 1;
    return (aux);
}

No *rot_esquerda(No* no_desb){
    No* aux;
    aux = no_desb->direita;
    no_desb->direita = aux->esquerda;
    aux->esquerda = no_desb;

    no_desb->h = maximo(altura(no_desb->direita), altura(no_desb->esquerda)) + 1;

    aux->h = maximo(altura(aux->direita), altura(no_desb)) + 1;
    return (aux);
}

No *rot_esquerda_direita(No* no_desb){
    no_desb->esquerda = rot_esquerda(no_desb->esquerda);
    return (rot_direita(no_desb));
}

No *rot_direita_esquerda(No* no_desb){
    no_desb->direita = rot_direita(no_desb->direita);
    return (rot_esquerda(no_desb));
}

No *inserir(No *raiz, No* novono){
    if (raiz == NULL)
        return novono;
    if (raiz->numero > novono->numero){
        raiz->esquerda = inserir(raiz->esquerda, novono);
        if ((altura(raiz->esquerda) - altura (raiz->direita)) == 2){
            if(novono->numero < raiz->esquerda->numero)
                raiz = rot_direita(raiz);
            else
                raiz = rot_esquerda_direita(raiz);
        }
    }
    else{ 
        if (raiz->numero < novono->numero){
        raiz->direita = inserir(raiz->direita, novono);
        if ((altura(raiz->direita) - altura (raiz->esquerda)) == 2){
            if(novono->numero > raiz->direita->numero)
                raiz = rot_esquerda(raiz);
            else
                raiz = rot_direita_esquerda(raiz);
        }
        }
    }
    raiz->h = maximo(altura(raiz->esquerda), altura(raiz->direita)) + 1;
    return raiz;
}

void adiciona_arvore(Arvore *a, int numero){
    No *novono = criarno(numero);
    a->Raiz = inserir(a->Raiz, novono);
}

void listar_nos(No *raiz){
    if (raiz != NULL){
        if(raiz->esquerda != NULL || raiz->direita != NULL){
        printf("Elemento: %d\n", raiz->numero);
        if(raiz->esquerda != NULL){
        if(raiz->esquerda->direita == NULL && raiz->esquerda->esquerda == NULL)
            printf("Elemento a esquerda de %d: %d (Folha)\n",raiz->numero, raiz->esquerda->numero);
        else
            printf("Elemento a esquerda de %d: %d\n",raiz->numero, raiz->esquerda->numero);
        if(raiz->direita == NULL)
            printf("\n");
        }
        if(raiz->direita != NULL){
        if(raiz->direita->esquerda == NULL && raiz->direita->direita == NULL)
            printf("Elemento a direita de %d: %d (Folha)\n\n",raiz->numero, raiz->direita->numero);
        else
            printf("Elemento a direita de %d: %d\n\n",raiz->numero, raiz->direita->numero);
        }
        listar_nos(raiz->esquerda);
        listar_nos(raiz->direita);
        }
    }
}

void listar_arvore(Arvore *a){
    printf("IMPRIMINDO ARVORE: \n");
    listar_nos(a->Raiz);
}