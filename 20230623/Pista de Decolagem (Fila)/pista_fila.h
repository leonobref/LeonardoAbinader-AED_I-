#ifndef PISTA_FILA_H
#define PISTA_FILA_H

typedef struct {
    char *nomeaviao;
    int identificador;
} Aviao;

typedef struct aux{
    Aviao avi;
    struct aux *proximo;
} Elemento;

typedef struct{
    Elemento *inicio;
    Elemento *fim;
} Fila;

void inicializar_fila(Fila *);
void reinicializar_fila(Fila *);
void adicionar_aviao(Fila *, Aviao);
void decolar(Fila *);
int retornar_numero_avioes(Fila *);
void printar_avioes(Fila *);
void printar_primeiro_aviao(Fila *);

#endif