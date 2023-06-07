#ifndef LISTA_LIGADA_ESTATICA_H
#define LISTA_LIGADA_ESTATICA_H

typedef struct{
    int l;
    int next;
} Elemento;

typedef struct{
    Elemento list[100];
    int inicio;
    int disponivel;
} Lista;

//Funções padrões para um TDA de uma Lista Ligada Estática.
void create_list(Lista *);
void free_list(Lista *);
int return_size(Lista *);
void print_list(Lista *);
void insert_number(Lista *, int);
void delete_number(Lista *, int);
int return_full(Lista *);
int return_empty(Lista *);
void alterate_number(Lista *, int, int);

//Exercício 2.
void first_is_last(Lista *, Lista *);
void last_to_first(Lista *, Lista *);

//Exercício 3.
void listcpy(Lista *, Lista *);
Lista listcnt(Lista *, Lista *);
Lista listint(Lista *, Lista *);

#endif