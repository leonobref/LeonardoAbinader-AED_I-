#include <stdio.h>
#include <stdlib.h>

#include "turma_ligada_dinamica.h"

void inicializa_turma(Turma *T){
    T -> inicio = NULL;
}

void reinicializar_turma(Turma *T){
    Elemento *apagar;
    Elemento *aux = T -> inicio;
    while (aux != NULL){
        Elemento *apagar = aux;
        aux = aux -> proximo;
        free (apagar);
    }
    T -> inicio = NULL;
}

int retornar_tamanho(Turma *T){
    int tam = 0;
    Elemento *i = T -> inicio;
    while (i != NULL){
        tam ++;
        i = i -> proximo;
    }
    return tam;
}

void printar_lista(Turma *T){
    Elemento *i = T -> inicio;
    printf("\n----------Imprimindo Alunos----------");
    while (i != NULL){
        printf("\nAluno: %s Matricula: %d Idade %d.", i->termo.nome, i ->termo.matricula, i->termo.idade);
        i = i -> proximo;
    }
}

int retornar_vazia(Turma *T){
    if (T -> inicio == NULL)
        return 1;
    else
        return -1;
}

Elemento *busca_elemento_e_predecessor(Turma *L, int numerobuscado, Elemento **pred){
    *pred = NULL;
    Elemento *atual = L -> inicio;
    while((atual != NULL) && (atual -> termo.matricula < numerobuscado)){
        *pred = atual;
        atual = atual -> proximo; 
    }
    if ((atual != NULL) && (atual -> termo.matricula == numerobuscado))
        return atual;
    return NULL;
}

void inserir_aluno_ordenado_crescente(Turma *T, Aluno novoaluno){
    int novo_cod = novoaluno.matricula;
    Elemento *pred, *i;
    i = busca_elemento_e_predecessor(T, novo_cod, &pred);
    if (i != NULL)
        return;
    i = malloc (sizeof(Elemento));
    i->termo = novoaluno;
        if (pred == NULL){
        i -> proximo = T -> inicio;
        T -> inicio = i;
    }
    else{
        i-> proximo = pred -> proximo;
        pred -> proximo = i;
    }
}

void inserir_aluno_final(Turma *T, Aluno novoaluno){
    Elemento *i = T ->inicio;
    Elemento *ult = NULL;
    
    if (i == NULL){
        i = malloc (sizeof(Elemento));
        i ->termo = novoaluno;
        i -> proximo = NULL;
        T ->inicio = i;
        return;
    }
    while(i != NULL){
        ult = i;
        i = i ->proximo;
    }
    i = malloc (sizeof(Elemento));
    i->termo = novoaluno;
    ult -> proximo = i;
    i -> proximo = NULL;
}

void excluir_elemento_pela_matricula(Turma *T, int matricula){
    Elemento *predecessor;
    Elemento *i;
    i = busca_elemento_e_predecessor(T, matricula, &predecessor);
    if (i == NULL)
        return;
    if (predecessor == NULL)
        T -> inicio = i -> proximo;
    else
        predecessor -> proximo = i -> proximo;
    free(i);
}