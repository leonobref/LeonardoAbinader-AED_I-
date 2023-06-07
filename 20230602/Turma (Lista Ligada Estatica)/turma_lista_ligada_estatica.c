#include <stdio.h>
#include <stdlib.h>

#include "turma_lista_ligada_estatica.h"

void create_list(Listadealunos *lista){
    lista -> turma = malloc (100 * sizeof(Aluno));
    for (int i = 0; i < 99; i++)
        lista -> turma[i].next = i + 1;
    lista -> turma[99].next = -1;
    lista -> start = -1;
    lista -> disponivel = 0;
}

void free_list(Listadealunos *lista){
    Listadealunos *aux = lista;
    free(aux->turma);
    free(aux);
    lista = NULL;
}

int return_size(Listadealunos *lista){
    int size = 0;
    int i = lista -> start;
    while (i != -1){
        size++;
        i = lista -> turma[i].next;
    }
    return size;
};

void print_list(Listadealunos *lista){
    printf("\n----------ALUNOS DA TURMA----------");
    int i = lista -> start;
    while (i != -1){
        fflush(stdin);
        printf("\nNome: %s. ", lista->turma[i].student.student_name);
        fflush(stdin);
        printf("Codigo: %d. ", lista->turma[i].student.student_code);
        printf("Idade: %d.", lista->turma[i].student.student_age);
        i = lista->turma[i].next;
    }
}

void insert_student(Listadealunos *lista, Aluno new_student){
    if (lista -> disponivel == -1)
        return;
    int i = lista -> start;
    int antecessor = -1;
    while (i != -1 && (new_student.student_code > lista->turma[i].student.student_code)){
        antecessor = i;
        i = lista -> turma[i].next;
    }
    if (i != -1 && (new_student.student_code == lista->turma[i].student.student_code))
        return;
    int disp = lista -> disponivel;
    if (lista -> disponivel != -1)
        lista -> disponivel = lista -> turma[disp].next;
    lista -> turma[disp].student = new_student;
    if (antecessor == -1){ // Se for inserido no começo da lista.
        lista -> turma[disp].next = lista->start;
        lista -> start = disp;
    } else{ // Se for inserido depois de outro elemento.
        lista -> turma[disp].next = lista -> turma[antecessor].next;
        lista -> turma[antecessor].next = disp;
    }
}

void delete_student(Listadealunos *lista, int student_code){
    int i = lista -> start;
    int antecessor = -1;
    while (i != -1 && (lista -> turma[i].student.student_code < student_code)){
        antecessor = i;
        i = lista -> turma[i].next;
    }
    if (i != -1 && (lista -> turma[i].student.student_code != student_code))
        return;

    if (antecessor == -1)
        lista -> start = lista -> turma[i].next;
    else
        lista->turma[antecessor].next = lista -> turma[i].next;
    lista -> turma[i].next = lista -> disponivel;
    lista -> disponivel = i;
}

int return_full(Listadealunos *lista){
    if(return_size(lista) == 100)
        return 1;
    else
        return -1;
}

int return_empty(Listadealunos *lista){
    if(return_size(lista) == 0)
        return 1;
    else
        return -1;
}

void alterate_student_code(Listadealunos *lista, int code, int new_code){
    int i = lista -> start;
    while (i != -1 && (lista -> turma[i].student.student_code < code))
        i = lista -> turma[i].next;
    if (i != -1 && (lista -> turma[i].student.student_code != code))
        return;
    Aluno student = lista -> turma[i].student;
    student.student_code = new_code;
    delete_student(lista, lista -> turma[i].student.student_code);

    insert_student(lista, student);
}