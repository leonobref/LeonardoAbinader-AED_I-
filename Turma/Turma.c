#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Turma.h"

Turma *create_class(int quantity){
    Turma *out = malloc (sizeof(Turma));
    out -> students_quantity = quantity;
    out -> students_list = malloc(quantity * sizeof(Aluno));

    return out;
}

void insert_students (Turma *class){
    for(int i = 0; i < class->students_quantity; i++){
        class -> students_list[i].student_code = i + 1;
        printf("\nDigite o nome do aluno %d: ", i+1);
        fflush(stdin);
        scanf("%100[^\n]s", class->students_list[i].student_name);
        fflush(stdin);
        printf("Digite a idade do aluno %d: ", i+1);
        scanf("%d", &class->students_list[i].student_age);
        printf("Digite o coeficiente do aluno %d: ", i+1);
        scanf("%f", &class->students_list[i].student_coefficient);
    }
}

void print_students (Turma *class){
    printf("\n----------ALUNOS DA TURMA----------");
    for(int i = 0; i < class->students_quantity; i++){
        fflush(stdin);
        printf("\nNome: %s. ", class->students_list[i].student_name);
        fflush(stdin);
        printf("Codigo: %d", class->students_list[i].student_code);
    }
}

void search_student_sequential(Turma *class, int code){
    for(int i =0; i < class->students_quantity; i++){
        if(class->students_list[i].student_code == code){
            printf("\nNome: %s.", class->students_list[i].student_name);
            printf("\nCodigo: %d.", class->students_list[i].student_code);
            printf("\nIdade: %d.", class->students_list[i].student_age);
            printf("\nCoeficiente: %.2f.", class->students_list[i].student_coefficient);
            return;
        }
    }
    printf("\nEstudante nao encontrado.");
}

void search_student_binary_recursive(Turma *class, int code, int first, int last){
    int half = (first+last)/ 2;
    if (code == class -> students_list[half].student_code){
            printf("\nNome: %s.", class->students_list[half].student_name);
            printf("\nCodigo: %d.", class->students_list[half].student_code);
            printf("\nIdade: %d.", class->students_list[half].student_age);
            printf("\nCoeficiente: %.2f.", class->students_list[half].student_coefficient);
            return;
    }
    if (first > last){
        printf("\nEstudante nao encontrado.");
        return;
    }
    if (code < class -> students_list[half].student_code){
        search_student_binary_recursive(class, code, first, half -1);
    }else{
        search_student_binary_recursive(class, code, half + 1, last);
    }
}