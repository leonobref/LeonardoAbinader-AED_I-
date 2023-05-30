#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Turma.h"

int main()
{
    int a;
    Turma *class;
    printf("Digite o numero de alunos da turma: ");
    scanf("%d", &a);
    class = create_class(a);
    insert_students(class);
    print_students(class);
    
    printf("\n\nDigite o codigo do aluno que voce deseja ver as informacoes (Busca Sequencial): ");
    scanf("%d", &a);
    search_student_sequential(class,a);

    printf("\n\nDigite o codigo do aluno que voce deseja ver as informacoes (Busca Binaria Recursiva): ");
    scanf("%d", &a);
    search_student_binary_recursive(class,a, 0, class->students_quantity - 1);

    return 0;
}
