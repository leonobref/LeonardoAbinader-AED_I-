#include <stdio.h>
#include <stdlib.h>

#include "lista_ligada_dinamica.h"

void inicializar_lista(Lista *L){
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
    if (i != NULL){
    printf("\n----------Imprimindo Elementos----------");
    while (i != NULL){
        printf("\nElemento: %d.", i->numero);
        i = i -> proximo;
    }
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

//Exercicio 2

Lista primeiro_vira_ultimo(Lista *L){
    Lista out;
    if (L -> inicio == NULL){
        out.inicio = NULL;
        return out;
    }
    inicializar_lista(&out);
    Elemento *i = L ->inicio ->proximo;
    while (i !=  NULL){
        inserir_numero_final(&out, i->numero);
        i = i ->proximo;
    }
    inserir_numero_final(&out, L->inicio->numero);
    return out;
};

void excluir_final(Lista *L){
    Elemento *i = L -> inicio;
    Elemento *ult = NULL;
    Elemento *penult = NULL;
    while(i != NULL){
        ult = i;
        i = i -> proximo;
    }
    i = L -> inicio;
    while(i != ult){
        penult = i;
        i = i -> proximo;
    }
    if (penult != NULL){
        penult->proximo = NULL;
        free(ult);
    }
    else if (penult == NULL && ult != NULL){
        excluir_numero_ordenado(L, ult->numero);
        L -> inicio = NULL;
    }
}
Lista inverter_lista(Lista *L){
    Lista out, aux;
    if (L -> inicio == NULL){
        out.inicio = NULL;
        return out;
    }
    Elemento *i, *ult;
    inicializar_lista(&out);
    lista_copiar(L, &aux);
    while(aux.inicio != NULL){
        i = aux.inicio;
        ult = NULL;
        while(i != NULL){
            ult = i;
            i = i ->proximo;
        }
        inserir_numero_final(&out, ult->numero);
        excluir_final(&aux);
    }
    return out;
}

//Exercício 3.
//Copia os elementos de L1 para L2 sendo L2 uma lista já inicializada.
void lista_copiar(Lista *L1, Lista *L2){
    if (!L2->inicio)
        reinicializar_lista(L2);
    else
        inicializar_lista(L2);
    Elemento *i = L1 -> inicio;

    while (i != NULL){
        inserir_numero_final(L2, i-> numero);
        i = i -> proximo;
    }
}

//Concatena os elementos de L2 em L1
void concatenar(Lista *L2, Lista *L1){
    Elemento *i = L1 ->inicio, *ult = NULL;
    while(i != NULL){
        ult = i;
        i = i -> proximo;
    }
    if (ult != NULL)
        ult -> proximo = L2 ->inicio;
    else
        L1 -> inicio = L2 -> inicio;
}

//Intercala L1 e L2 em uma nova Lista.
Lista intercalar(Lista *L1, Lista *L2){
    Lista out;
    inicializar_lista(&out);
    Elemento *i = L1 -> inicio;
    Elemento *j = L2 -> inicio;
    while(i != NULL || j != NULL){
        if (i != NULL){
            inserir_numero_final(&out, i->numero);
            i = i -> proximo;
        }
        if (j != NULL){
            inserir_numero_final(&out, j->numero);
            j = j -> proximo;
        }
    }
    return out;
}