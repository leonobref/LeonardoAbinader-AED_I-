#ifndef LISTA_DUPLAMENTE_LIGADA_H
#define LISTA_DUPLAMENTE_LIGADA_H

typedef struct aux{
    int numero;
    struct aux *anterior;
    struct aux *proximo;
} Elemento;

typedef struct{
    Elemento *inicio;
} Lista;

//Funcoes padroes Lista Duplamente Ligada
void inicaliza_lista(Lista *);
int retornar_tamanho(Lista *);
void printar_lista(Lista *);
void inserir_elemento_ordenado(Lista *, int);
void inserir_elemento_final(Lista *, int);
void excluir_elemento(Lista *, int);
Elemento *retornar_endereco_elemento(Lista *, int);
void reinicializar_lista (Lista *);

//Exercicio
void reoordena_e_transfere(Lista *, Lista *);

#endif