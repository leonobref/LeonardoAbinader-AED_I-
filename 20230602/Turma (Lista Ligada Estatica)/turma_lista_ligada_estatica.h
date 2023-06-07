#ifndef TURMA_LISTA_LIGADA_H
#define TURMA_LISTA_LIGADA_H

typedef struct{
    int student_code;
    char *student_name;
    int student_age;
} Aluno;

typedef struct{
    Aluno student;
    int next;
} Elemento;

typedef struct{
    Elemento *turma;
    int start;
    int disponivel;
} Listadealunos;

void create_list(Listadealunos *);
void free_list(Listadealunos *);
int return_size(Listadealunos *);
void print_list(Listadealunos *);
void insert_student(Listadealunos *, Aluno);
void delete_student(Listadealunos *, int);
int return_full(Listadealunos *);
int return_empty(Listadealunos *);
void alterate_student_code(Listadealunos *, int, int);

#endif