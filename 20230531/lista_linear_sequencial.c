#include <stdlib.h>
#include <stdio.h>

#include "lista_linear_sequencial.h"

void inicializa_lista(Lista **L){
    *L = malloc (sizeof(Lista));
    (*L)->qtd_elementos=0;
}

int tamanho_lista (Lista *L){
    if (L == NULL)
        return -1;
    else
        return L -> qtd_elementos;
};

int lista_cheia(Lista *L){
    if (L == NULL)
        return -1;
    if(L -> qtd_elementos == 100)
        return 1;
    else
        return -1;
};

int lista_vazia(Lista *L){
    if (L == NULL)
        return -1;
    if(L -> qtd_elementos == 0)
        return 1;
    else
        return -1;
};

void imprimir_elementos(Lista *L){
    printf("\n----------Elementos da lista----------");
    for (int i = 0; i< L ->qtd_elementos; i++)
        printf("\nElemento %d", L->elemento[i]);
};

void inserir_elemento_final(Lista *L, int novoelemento){
    if(lista_cheia(L) == 1)
        return;
    L ->elemento[L->qtd_elementos] = novoelemento;
    L -> qtd_elementos++;
}

void inserir_elemento_comeco(Lista *L, int novoelemento){
    if(lista_cheia(L) == 1)
        return;

    for (int i = L->qtd_elementos - 1; i >= 0; i--){
        L -> elemento[i + 1] = L ->elemento[i];
    }
    L ->elemento[0] = novoelemento;
    L -> qtd_elementos++;
}

int buscar_posicao_ordenado(Lista *L, int elemento){
    int i = 0;
    while ((i < L->qtd_elementos) && (L -> elemento[i] < elemento))
        i++;
    if ((i < L->qtd_elementos) && (L -> elemento[i] == elemento))
        return i;
    return -1;
}

int buscar_predecessor(Lista *L, int elemento){
    int predecessor = -1, i = 0;
    while ((i < L->qtd_elementos) && (L -> elemento[i] < elemento)){
        predecessor = i;
        i++;
    }
    return predecessor;
}

void inserir_elemento_ordenado(Lista *L, int novoelemento){
    if(lista_cheia(L) == 1)
        return;

    int i = buscar_posicao_ordenado(L, novoelemento);
    int predecessor = buscar_predecessor(L, novoelemento);

    if (i != -1)
        return;

    for(i = L->qtd_elementos - 1; i > predecessor; i--){
        L -> elemento[i + 1] = L ->elemento[i];
    }
    L ->elemento[predecessor + 1] = novoelemento;
    L -> qtd_elementos++;
}

void inserir_elemento_posicao(Lista *L, int pos, int novoelemento){
    if(lista_cheia(L) == 1 || pos -1 > 100 || pos -1 < 0)
        return;
    for (int i = L ->qtd_elementos-1; i>= pos -1; i--)
        L->elemento[i+1] = L->elemento[i];
    L->elemento[pos - 1] = novoelemento;
    L-> qtd_elementos++;
}

void excluir_elemento_posicao(Lista *L, int pos){
    if(lista_vazia(L) == 1)
        return;
    for (int i = pos -1; i < L ->qtd_elementos-1; i++){
        L ->elemento[i] = L -> elemento [i + 1];
    }
    L ->qtd_elementos--;
};

void excluir_elemento_comeco(Lista *L){
    excluir_elemento_posicao(L, 1);
}

void excluir_elemento_final(Lista *L){
    excluir_elemento_posicao(L, L ->qtd_elementos);
}

void excluir_elemento_valor(Lista *L, int elemento){
    if(lista_vazia(L) == 1)
        return;

    int pos = -1;

    for (int i = 0; i < L ->qtd_elementos; i++){
        if (L ->elemento[i] == elemento){
            pos = i;
            break;
        }
    }
    if (pos == -1)
        return;
    
    for (int i = pos; i < L ->qtd_elementos-1; i ++)
        L ->elemento[i] = L -> elemento [i + 1];

    L ->qtd_elementos--;
}

void liberar_lista(Lista **lista){
    Lista *vec_ref = *lista;

    free(vec_ref ->elemento);
    free(vec_ref);
    *lista = NULL;
}

void alterar_elemento_valor(Lista *L, int novoelemento, int velhoelemento){
    excluir_elemento_valor(L, velhoelemento);
    inserir_elemento_ordenado(L, novoelemento);
};