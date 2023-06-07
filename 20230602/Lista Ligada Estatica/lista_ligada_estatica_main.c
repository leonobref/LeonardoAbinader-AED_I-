#include <stdio.h>
#include <stdlib.h>

#include "lista_ligada_estatica.h"

int main()
{
    Lista a;
    create_list(&a);

    insert_number(&a, 22);
    insert_number(&a, 18);
    insert_number(&a, 33);
    insert_number(&a, 30);
    insert_number(&a, 12);
    insert_number(&a, 20);
    
    printf("Imprimir a primeira lista.");
    print_list(&a);

    Lista b;
    create_list(&b);
    first_is_last(&a, &b);
    printf("\n\nImprimir a primeira lista com o primeiro elemento na ultima posicao.");
    print_list(&b);

    Lista c;
    create_list(&c);
    last_to_first(&a, &c);
    printf("\n\nImprimir a primeira lista ao contrario.\n");
    print_list(&c);

    Lista d;
    create_list(&d);

    insert_number(&d, 21);
    insert_number(&d, 19);
    insert_number(&d, 34);
    insert_number(&d, 15);
    insert_number(&d, 32);
    insert_number(&d, 43);
    printf("\n\nImprimir a segunda lista.\n");
    print_list (&d);

    Lista e = listcnt(&a, &d);
    printf("\n\nImprimir a concatenacao da primeira com a segunda lista.\n");
    print_list(&e);

    Lista f = listint(&a, &d);
    printf("\n\nImprimir a intercalacao (ordenada)da primeira com a segunda lista.\n");
    print_list(&f);

    free_list(&d);
    free_list(&a);
    free_list(&e);
    free_list(&f);
    return 0;
}
