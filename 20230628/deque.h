#ifndef DEQUE_H
#define DEQUE_H

typedef struct{
    char *nome_aluno;
    int idade;
} Aluno;

typedef struct aux{
    Aluno termo;
    struct aux *proximo;
    struct aux *anterior;
} Elemento;

typedef struct{
    Elemento *cabeca;
} Deque;

void inicializar_deque(Deque *);
int retornar_tamanho(Deque *);
void mostrar_deque(Deque *);
void inserir_inicio(Deque *, Aluno);
void inserir_final(Deque *, Aluno);
void excluir_inicio(Deque *);
void excluir_final(Deque *);
void reinicializar_deque(Deque *);

//Exercicio
void exibe (Deque *,int, char *);
#endif