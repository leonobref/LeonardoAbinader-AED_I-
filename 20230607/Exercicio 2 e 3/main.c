#include <stdio.h>
#include <stdlib.h>

#include "lista_ligada_dinamica.h"

int main()
{
    Lista a;
    inicializar_lista(&a);

    inserir_numero_ordenado_crescente(&a, 22);
    inserir_numero_ordenado_crescente(&a, 18);
    inserir_numero_ordenado_crescente(&a, 33);
    inserir_numero_ordenado_crescente(&a, 30);
    inserir_numero_ordenado_crescente(&a, 12);
    inserir_numero_ordenado_crescente(&a, 20);

    printar_lista(&a);

    Lista b;
    lista_copiar(&a, &b);
    printar_lista(&b);

    Lista c;
    inicializar_lista(&c);
    inserir_numero_ordenado_crescente(&c, 43);
    inserir_numero_ordenado_crescente(&c, 67);
    inserir_numero_ordenado_crescente(&c, 55);
    inserir_numero_ordenado_crescente(&c, 34);
    inserir_numero_ordenado_crescente(&c, 13);
    inserir_numero_ordenado_crescente(&c, 58);

    printar_lista(&c);

    lista_copiar(&a, &c);
    printar_lista(&c);

    Lista d = inverter_lista(&b);
    printar_lista(&d);

    return 0;
}
