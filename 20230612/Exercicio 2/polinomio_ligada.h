#ifndef POLINOMIO_LIGADA_H
#define POLINOMIO_LIGADA_H

typedef struct{
    int coeficiente;
    int expoente;
} Monomio;

typedef struct aux{
    Monomio termo;
    struct aux *proximo;
} Elemento;

typedef struct{
    Elemento *inicio;
} Polinomio;

void inicializa_polinomio(Polinomio *);
void printar_polinomio(Polinomio *);
void inserir_elemento_decrescente(Polinomio *, Monomio);
void excluir_elemento_pelo_expoente(Polinomio *P, int expoente);

//Exercicio 2
Polinomio soma_polinomio(Polinomio *, Polinomio *);


#endif