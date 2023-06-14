#include <stdio.h>
#include <stdlib.h>

#include "polinomio_ligada.h"

void inicializa_polinomio(Polinomio *P){
    P -> inicio = NULL;
}

void printar_polinomio(Polinomio *P){
    Elemento *i = P-> inicio;
    int a, b;
    printf("\nImprimindo Polinomio\n");
    while (i != NULL){
        a = i -> termo.coeficiente;
        if (i -> termo.coeficiente < 0){
            a = abs(i -> termo.coeficiente);
        }


        if(i -> termo.expoente == 0)
            printf("%d", a);
        else if (a == 1 && i -> termo.expoente == 1)
            printf("x");
        else if(a == 1)
            printf("x^%d", i->termo.expoente);
        else if(i -> termo.expoente == 1)
            printf("%dx", a);
        else
            printf("%dx^%d", a, i->termo.expoente);


        if (i -> proximo != NULL){
            if (i -> proximo->termo.coeficiente < 0)
                printf(" - ");
            if (i -> proximo->termo.coeficiente > 0)
                printf(" + ");
        }
        i = i -> proximo;
    }
    printf("\n");
}

Elemento *buscaposicaoelemento(Polinomio *L, int expoente, Elemento ** predecessor){
    Elemento *i = L -> inicio;
    *predecessor = NULL;
    while ((i != NULL) && (i ->termo . expoente > expoente)){
        *predecessor = i;
        i = i ->proximo;
    }
    if ((i != NULL) && (i ->termo . expoente == expoente)){
        return i;
    }
    return NULL;
}

void excluir_elemento_pelo_expoente(Polinomio *P, int expoente){
    Elemento *predecessor;
    Elemento *i;
    i = buscaposicaoelemento(P, expoente, &predecessor);
    if (i == NULL)
        return;
    if (predecessor == NULL)
        P -> inicio = i -> proximo;
    else
        predecessor -> proximo = i -> proximo;
    free(i);
}

void inserir_elemento_decrescente(Polinomio *P, Monomio m){
    if (m.coeficiente == 0)
        return;
    int expo = m.expoente;
    Elemento *i, *predecessor;
    i = buscaposicaoelemento(P, expo, &predecessor);
    if (i != NULL){
        i ->termo.coeficiente += m.coeficiente;
        if (i -> termo.coeficiente == 0)
            excluir_elemento_pelo_expoente(P, m.expoente);
        return;
    }
    i = malloc (sizeof(Elemento));
    i->termo = m;
    if (predecessor == NULL){
        i -> proximo = P -> inicio;
        P -> inicio = i;
    }
    else{
        i-> proximo = predecessor -> proximo;
        predecessor -> proximo = i;
    }
    
};

Polinomio soma_polinomio(Polinomio *P1, Polinomio *P2){
    Polinomio P3;
    inicializa_polinomio(&P3);
    Elemento *i, *j;
    i = P1 ->inicio;
    j = P2 ->inicio;

    while (i != NULL){
        inserir_elemento_decrescente(&P3, i->termo);
        i = i -> proximo;
    }
    while (j != NULL){
        inserir_elemento_decrescente(&P3, j->termo);
        j = j -> proximo;
    }
    return P3;
};