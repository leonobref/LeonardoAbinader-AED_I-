#include <stdio.h>

#include "turma_lista_ligada_estatica.h"

int main()
{
    Listadealunos a;
    create_list(&a);
    if(return_empty(&a) == 1)
        printf("Lista esta vazia.");
    else
        printf("\nLista nao esta vazia.");
    if(return_full(&a) == 1)
        printf("\nLista esta cheia.\n");
    else
        printf("\nLista nao esta cheia.\n");
    
    Aluno student;
    student.student_code = 22;
    student.student_name = "Rodrigo Alves";
    student.student_age = 23;
    insert_student(&a, student);

    student.student_code = 18;
    student.student_name = "Bandeira de Mello";
    student.student_age = 25;
    insert_student(&a, student);

    student.student_code = 33;
    student.student_name = "Leonardo Nobre";
    student.student_age = 20;
    insert_student(&a, student);

    student.student_code = 30;
    student.student_name = "Jorge Salgado";
    student.student_age = 17;
    insert_student(&a, student);

    student.student_code = 12;
    student.student_name = "Paulo Brax";
    student.student_age = 40;
    insert_student(&a, student);

    student.student_code = 20;
    student.student_name = "Fullano Ciclano";
    student.student_age = 18;
    insert_student(&a, student);

    print_list(&a);
    printf("\nA quantidade de elementos validos da lista: %d", return_size(&a));
    delete_student(&a, 30);
    printf("\n");
    print_list(&a);
    printf("\nA quantidade de elementos validos da lista: %d", return_size(&a));

    if(return_empty(&a) == 1)
        printf("\n\nLista esta vazia.");
    else
        printf("\n\nLista nao esta vazia.");
    if(return_full(&a) == 1)
        printf("\nLista esta cheia.\n");
    else
        printf("\nLista nao esta cheia.\n");
    
    alterate_student_code(&a, 12, 32);
    print_list(&a);
    printf("\nA quantidade de elementos validos da lista: %d", return_size(&a));

    free_list(&a);
    return 0;
}
