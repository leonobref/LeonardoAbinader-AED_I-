#ifndef LISTA_LINEAR_SEQUENCIAL_H
#define LISTA_LINEAR_SEQUENCIAL_H

typedef struct {
    int elemento[100];
    int qtd_elementos;
} Lista;

void inicializa_lista(Lista **);
int tamanho_lista (Lista *);
int lista_cheia(Lista *);
int lista_vazia(Lista *);
void imprimir_elementos(Lista *);

void inserir_elemento_final(Lista *, int);
void inserir_elemento_comeco(Lista *, int);
void inserir_elemento_ordenado(Lista *, int);
void inserir_elemento_posicao(Lista *, int, int);

void excluir_elemento_posicao(Lista *, int);
void excluir_elemento_comeco(Lista *);
void excluir_elemento_final(Lista *);
void excluir_elemento_valor(Lista *, int);

void liberar_lista(Lista **);
#endif