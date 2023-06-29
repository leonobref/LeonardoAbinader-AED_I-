#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "deque.h"
void inicializar_deque(Deque *D){
    D->cabeca = malloc (sizeof (Elemento));
    D->cabeca -> anterior = D->cabeca;
    D->cabeca -> proximo = D->cabeca;
}

void reinicializar_deque(Deque *D){
    Elemento *apagar;
    Elemento *aux = D->cabeca->proximo;
    while(aux != D->cabeca){
        apagar = aux;
        aux = aux -> proximo;
        free(apagar);
    };
    D->cabeca -> anterior = D->cabeca;
    D->cabeca -> proximo = D->cabeca;
}

int retornar_tamanho(Deque *D){
    if (D->cabeca->proximo == D->cabeca && D->cabeca->anterior == D->cabeca)
        return 0;
    Elemento *i = D->cabeca->proximo;
    int tam = 0;
    while(i != D->cabeca){
        tam++;
        i = i->proximo;
    }
    return tam;
}

void mostrar_deque(Deque *D){
    Elemento *i = D -> cabeca -> proximo;
    printf("\n----------Imprimindo Alunos----------");
    while (i != D -> cabeca){
        printf("\nAluno: %s Idade %d.", i->termo.nome_aluno, i->termo.idade);
        i = i -> proximo;
    }
}

void inserir_inicio(Deque *D, Aluno novoaluno){
    Elemento *i = malloc (sizeof(Elemento));
    i -> termo = novoaluno;
    if (D->cabeca->proximo == D->cabeca && D->cabeca->anterior == D->cabeca){
        i->proximo = D->cabeca;
        i-> anterior = D->cabeca;
        D->cabeca -> proximo = i;
        D->cabeca -> anterior = i;
    }
    else{
        i-> proximo = D->cabeca-> proximo;
        i-> anterior = D -> cabeca;
        D->cabeca-> proximo = i;
        i->proximo -> anterior = i;
    }
}

void inserir_final(Deque *D, Aluno novoaluno){
    Elemento *i = malloc (sizeof(Elemento));
    i -> termo = novoaluno;
    if (D->cabeca->proximo == D->cabeca && D->cabeca->anterior == D->cabeca){
        i->proximo = D->cabeca;
        i-> anterior = D->cabeca;
        D->cabeca -> proximo = i;
        D->cabeca -> anterior = i;
    }
    else{
        i-> anterior = D-> cabeca -> anterior;
        i-> proximo = D -> cabeca;
        D->cabeca-> anterior = i;
        i->anterior->proximo = i;
    }
}

void excluir_inicio(Deque *D){
    if (D -> cabeca -> proximo == D -> cabeca)
        return;
    Elemento *i = D -> cabeca -> proximo;
    D->cabeca -> proximo = i-> proximo;
    i-> proximo->anterior = D -> cabeca;
    free(i);
}

void excluir_final(Deque *D){
    if (D -> cabeca -> proximo == D -> cabeca)
        return;
    Elemento *i = D -> cabeca -> anterior;
    D->cabeca -> anterior = i-> anterior;
    i-> anterior-> proximo = D -> cabeca;
    free(i);
}

//Exercicio
void exibe (Deque *D, int pos, char *ordem){
    if (D->cabeca->proximo == D->cabeca && D->cabeca->anterior == D->cabeca)
        return;

    int posicao = pos - 1;

    if (pos > retornar_tamanho(D)|| posicao < 0)
        return;

    if(strcmp("d", ordem) != 0 && strcmp("i", ordem) != 0)
        return;
    
    Elemento *aux = D->cabeca->proximo;
    for(int i = 0; i < posicao; i++)
        aux = aux ->proximo;

    if(strcmp("d", ordem) == 0){
            printf("\n-Exibindo Elementos na ordem direta a partir da posicao %d-", pos);
        while(aux != D->cabeca){
            printf("\nAluno: %s Idade %d.", aux->termo.nome_aluno, aux->termo.idade);
            aux = aux -> proximo;
        }
    }
    if(strcmp("i", ordem) == 0){
            printf("\n-Exibindo Elementos na ordem inversa a partir da posicao %d-", pos);
        while(aux != D->cabeca){
            printf("\nAluno: %s Idade %d.", aux->termo.nome_aluno, aux->termo.idade);
            aux = aux -> anterior;
        }
    }
}