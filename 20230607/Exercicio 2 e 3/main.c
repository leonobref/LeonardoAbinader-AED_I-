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

    Lista b = primeiro_vira_ultimo(&a);
    printar_lista(&b);

    Lista c;
    lista_copiar_nao_inicializada(&a, &c);
    printar_lista(&c);

    Lista d = inverter_lista(&a);
    printar_lista(&d);

    concatenar(&d , &c);
    printar_lista(&c);
    
    Lista e = intercalar(&a, &d);
    printar_lista(&e);

    return 0;
}
