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

int contar_nos(No *raiz, int tamanho){
    if (raiz != NULL){
        tamanho++;
        tamanho = contar_nos(raiz->esquerda, tamanho);
        tamanho = contar_nos(raiz->direita, tamanho);
    }
    return tamanho;
}

int contar_arvore(Arvore *a){
    int tamanho = contar_nos(a->Raiz, 0);
    return tamanho;
}

No *contem(No *raiz, int numero){
    if (raiz == NULL)
        return NULL;
    if (raiz->numero == numero)
        return raiz;
    if (raiz->numero > numero)
        return (contem (raiz->esquerda, numero));
    else
        return (contem (raiz->direita, numero));
}

No *buscar_no (Arvore *a, int numero){
    return contem(a->Raiz, numero);
}

void listar_nos_preordem (No *raiz){
    if(raiz != NULL){
        printf("%d- ", raiz->numero);
        listar_nos_preordem(raiz->esquerda);
        listar_nos_preordem(raiz->direita);
    }
}

void listar_preordem(Arvore *a){
    printf("IMPRIMINDO ARVORE PRE-ORDEM: \n");
    listar_nos_preordem(a->Raiz);
}

void listar_nos_inordem (No *raiz){
    if(raiz != NULL){
        listar_nos_inordem(raiz->esquerda);
        printf("%d- ", raiz->numero);
        listar_nos_inordem(raiz->direita);
    }
}

void listar_inordem(Arvore *a){
    printf("IMPRIMINDO ARVORE IN-ORDEM: \n");
    listar_nos_inordem(a->Raiz);
}

void listar_nos_posordem (No *raiz){
    if(raiz != NULL){
        listar_nos_posordem(raiz->esquerda);
        listar_nos_posordem(raiz->direita);
        printf("%d- ", raiz->numero);
    }
}

void listar_posordem(Arvore *a){
    printf("IMPRIMINDO ARVORE POS-ORDEM: \n");
    listar_nos_posordem(a->Raiz);
}