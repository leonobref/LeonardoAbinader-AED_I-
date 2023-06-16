#ifndef TURMA_LIGADA_H
#define TURMA_LIGADA_H

typedef struct{
    int matricula;
    char *nome;
    int idade;
} Aluno;

typedef struct aux{
    Aluno termo;
    struct aux *proximo;
} Elemento;

typedef struct{
    Elemento *inicio;
} Turma;

void inicializa_turma(Turma *);
void reinicializar_turma(Turma *);
int retornar_tamanho(Turma *);
void printar_lista(Turma *);
int retornar_vazia(Turma *);
void inserir_aluno_ordenado_crescente(Turma *, Aluno);
void inserir_aluno_final(Turma *, Aluno);
void excluir_elemento_pela_matricula(Turma *, int);

#endif