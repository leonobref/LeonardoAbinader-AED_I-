#include <stdio.h>
#include <stdlib.h>

#include "deque.h"

int main()
{
    Aluno a;
    Deque D;
    inicializar_deque(&D);
    a.idade = 18;
    a.nome_aluno = "Rodrigo Tavares";
    inserir_inicio(&D, a);

    a.idade = 22;
    a.nome_aluno = "Jorge Salgado";
    inserir_final(&D, a);

    a.idade = 21;
    a.nome_aluno = "Eduardo Gomes";
    inserir_inicio(&D, a);

    a.idade = 19;
    a.nome_aluno = "Giorgian de Arrascaeta";
    inserir_final(&D, a);

    a.idade = 24;
    a.nome_aluno = "Yusef Abilio";
    inserir_inicio(&D, a);
    

    mostrar_deque(&D);

    printf("\n");
    exibe(&D, 2, "d");

    printf("\n");
    exibe(&D, 3, "i");

    return 0;
}
