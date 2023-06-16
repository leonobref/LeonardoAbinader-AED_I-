#include <stdio.h>
#include <stdlib.h>

#include "lista_ligada_dinamica.h"

int main()
{
    Lista a;
    inicializa_lista(&a);

    inserir_numero_ordenado_crescente(&a, 22);
    inserir_numero_ordenado_crescente(&a, 18);
    inserir_numero_ordenado_crescente(&a, 33);
    inserir_numero_ordenado_crescente(&a, 30);
    inserir_numero_ordenado_crescente(&a, 12);
    inserir_numero_ordenado_crescente(&a, 20);

    printar_lista(&a);

    inserir_numero_final(&a, 21);

    excluir_numero_ordenado(&a, 18);

    printar_lista(&a);

    return 0;
}
