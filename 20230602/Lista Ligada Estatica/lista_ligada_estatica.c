#include <stdio.h>
#include <stdlib.h>

#include "lista_ligada_estatica.h"

//Funções padrões para um TDA de uma Lista Ligada Estática.
void create_list(Lista *vec){
    for (int i = 0; i < 99; i++)
        vec -> list[i].next = i + 1;
    vec -> list[99].next = -1;
    vec -> inicio = -1;
    vec -> disponivel = 0;
}

void free_list(Lista *vec){
    Lista *aux = vec;
    free(aux);
    vec = NULL;
}

int return_size(Lista *vec){
    int size = 0;
    int i = vec -> inicio;
    while (i != -1){
        size++;
        i = vec -> list[i].next;
    }
    return size;
};

void print_list(Lista *vec){
    printf("\n----------Elementos da lista----------");
    int i = vec -> inicio;
    while (i != -1){
        printf("\nElemento: %d. ", vec->list[i].l);
        i = vec->list[i].next;
    }
}

void insert_number(Lista *vec, int new_element){
    if (vec -> disponivel == -1)
        return;
    int i = vec -> inicio;
    int antecessor = -1;
    while (i != -1 && (new_element > vec->list[i].l)){
        antecessor = i;
        i = vec -> list[i].next;
    }
    if (i != -1 && (new_element == vec->list[i].l))
        return;
    int disp = vec -> disponivel;
    if (vec -> disponivel != -1)
        vec -> disponivel = vec -> list[disp].next;
    vec -> list[disp].l = new_element;
    if (antecessor == -1){ // Se for inserido no começo da lista.
        vec -> list[disp].next = vec->inicio;
        vec -> inicio = disp;
    } else{ // Se for inserido depois de outro elemento.
        vec -> list[disp].next = vec -> list[antecessor].next;
        vec -> list[antecessor].next = disp;
    }
}

void insert_last_number(Lista *vec, int new_element){
    if (vec -> disponivel == -1)
        return;
    int i = vec -> inicio;
    int antecessor = -1;
    while (i != -1){
        antecessor = i;
        i = vec -> list[i].next;
    }
    int disp = vec -> disponivel;
    if (vec -> disponivel != -1)
        vec -> disponivel = vec -> list[disp].next;
    vec -> list[disp].l = new_element;
    if (antecessor == -1){ // Se for inserido no começo da lista.
        vec -> list[disp].next = vec->inicio;
        vec -> inicio = disp;
    } else{ // Se for inserido depois de outro elemento.
        vec -> list[disp].next = vec -> list[antecessor].next;
        vec -> list[antecessor].next = disp;
    }
}

void delete_number(Lista *vec, int element){
    int i = vec -> inicio;
    int antecessor = -1;
    while (i != -1 && (vec -> list[i].l < element)){
        antecessor = i;
        i = vec -> list[i].next;
    }
    if (i != -1 && (vec -> list[i].l != element))
        return;

    if (antecessor == -1)
        vec -> inicio = vec -> list[i].next;
    else
        vec->list[antecessor].next = vec -> list[i].next;
    vec -> list[i].next = vec -> disponivel;
    vec -> disponivel = i;
}

int return_full(Lista *lista){
    if(return_size(lista) == 100)
        return 1;
    else
        return -1;
}

int return_empty(Lista *lista){
    if(return_size(lista) == 0)
        return 1;
    else
        return -1;
}

void alterate_number(Lista *vec, int element, int new_element){
    int i = vec -> inicio;
    while (i != -1 && (vec -> list[i].l < element))
        i = vec -> list[i].next;
    if (i != -1 && (vec -> list[i].l != element))
        return;
    delete_number(vec, vec -> list[i].l);
    insert_number(vec, new_element);
}
//Exercício 2.
//O primeiro elemento da lista se torna o último.
void first_is_last(Lista *L, Lista *L1){
    listcpy(L, L1);
    int ult;
    int i = L1 -> inicio;
    int primeiro = i;
    L1 -> inicio = L1 ->list[primeiro].next;
   while (i != -1){
        ult = i;
        i = L1->list[i].next;
    }
    L1 -> list[ult].next = primeiro;
    L1 -> list[primeiro].next = -1;
}

//Inverte a Lista
void last_to_first(Lista *L, Lista *L1){
    listcpy(L, L1);
    int ult;
    int i = L1 -> inicio;
    int vec[100], j = 1;
    int primeiro = i;
    vec[0] = i;
    int sum = 0;

    while (i != -1){
        ult = i;
        vec[j] = L1 -> list[i].next;
        j++;
        sum++;
        i = L1->list[i].next;
    }
    L1 -> inicio = ult;
    int l = L1 -> inicio;

    while (sum >= 0){
        L1 -> list[l].next = vec[sum - 1];
        l = L1 -> list[l].next;
        sum--;
    }

    L1 -> list[primeiro].next = -1;
}

//Exercício 3.
//Copia os elementos de L1 para L2.
void listcpy(Lista *L1, Lista *L2){
    L2 -> disponivel = L1 -> disponivel;
    L2 -> inicio = L1 -> inicio;
    for (int i = 0; i < 100; i++){
        L2 -> list[i].l = L1 ->list[i].l;
        L2 -> list[i].next = L1 -> list[i].next;
    }
}

//Concatena a Lista L1 com a Lista L2 em uma nova Lista.
Lista listcnt(Lista *L1, Lista *L2){
    Lista L3;
    if (return_size(L1) + return_size(L2) > 100)
        return L3;

    listcpy(L1, &L3);
    int i = L2 -> inicio;
    while (i != -1){
        insert_last_number(&L3, L2 -> list[i].l);
        i = L2 -> list[i].next;
    }
    return L3;
}

//Insere os Elementos de L1 e de L2 em uma nova lista de forma intercalada.
Lista listint(Lista *L1, Lista *L2){
    Lista L3;
    create_list(&L3);
    if (return_size(L1) + return_size(L2) > 100)
        return L3;
    
    int i = L1 -> inicio;
    int j = L2 -> inicio;

    while (i != -1 || j != -1){
        if (i != -1){
            insert_last_number(&L3, L1 ->list[i].l);
            i = L1 ->list[i].next;
        }
        if (j != -1){
            insert_last_number(&L3, L2 ->list[j].l);
            j = L2 ->list[j].next;
        }
    }
    return L3;
}
