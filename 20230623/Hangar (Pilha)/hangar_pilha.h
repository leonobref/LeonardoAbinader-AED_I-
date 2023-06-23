#ifndef HANGAR_PILHA_H
#define HANGAR_PILHA_H

typedef struct {
    char *nomeaviao;
    int identificador;
} Aviao;

typedef struct aux{
    Aviao avi;
    struct aux *proximo;
} Elemento;

typedef struct{
    Elemento *topo;
} Pilha;

void inicializar_pilha(Pilha *);
void reinicializar_pilha(Pilha *);
void adicionar_aviao(Pilha *, Aviao);
void remover_aviao(Pilha *);
int retornar_numero_avioes(Pilha *);
void printar_avioes(Pilha *);
void printar_primeiro_aviao(Pilha *);

void remover_aviao_posicao(Pilha *, int);

#endif