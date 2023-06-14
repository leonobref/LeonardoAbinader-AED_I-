#include <stdio.h>
#include <stdlib.h>

#include "polinomio_ligada.h"

int main()
{
    Polinomio P1, P2;
    inicializa_polinomio(&P1);
    inicializa_polinomio(&P2);

    Monomio a;
    a.coeficiente = -10;
    a.expoente = 1;
    inserir_elemento_decrescente(&P1, a);
    a.coeficiente = 4;
    a.expoente = 2;
    inserir_elemento_decrescente(&P1, a);
    a.coeficiente = -5;
    a.expoente = 0;
    inserir_elemento_decrescente(&P1, a);

    printf("Imprimir o Polinomio P1.");
    printar_polinomio(&P1);

    a.coeficiente = 12;
    a.expoente = 0;
    inserir_elemento_decrescente(&P2, a);
    a.coeficiente = 6;
    a.expoente = 1;
    inserir_elemento_decrescente(&P2, a);

    printf("\nImprimir o Polinomio P2.");
    printar_polinomio(&P2);

    Polinomio S = soma_polinomio(&P1, &P2);
    printf("\nImprimir a soma (Polinomio S) de P1 e P2.");
    printar_polinomio(&S);

    return 0;
}


