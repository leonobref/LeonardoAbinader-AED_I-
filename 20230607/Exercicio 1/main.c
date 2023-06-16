#include <stdio.h>
#include <stdlib.h>

#include "turma_ligada_dinamica.h"

int main()
{
    Turma a;
    inicializa_turma(&a);

    Aluno student;
    student.matricula = 22;
    student.nome = "Rodrigo Alves";
    student.idade = 23;
    inserir_aluno_ordenado_crescente(&a, student);

    student.matricula = 18;
    student.nome = "Bandeira de Mello";
    student.idade = 25;
    inserir_aluno_ordenado_crescente(&a, student);

    student.matricula = 33;
    student.nome = "Leonardo Nobre";
    student.idade = 20;
    inserir_aluno_ordenado_crescente(&a, student);

    student.matricula = 30;
    student.nome = "Jorge Salgado";
    student.idade = 17;
    inserir_aluno_ordenado_crescente(&a, student);

    student.matricula = 12;
    student.nome = "Paulo Brax";
    student.idade = 40;
    inserir_aluno_ordenado_crescente(&a, student);

    student.matricula = 20;
    student.nome = "Fullano Ciclano";
    student.idade = 18;
    inserir_aluno_ordenado_crescente(&a, student);

    printar_lista(&a);

    student.matricula = 21;
    student.nome = "Diogo Gomes";
    student.idade = 18;
    inserir_aluno_final(&a, student);

    printar_lista(&a);

    return 0;
}
