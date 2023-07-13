#include <stdio.h>
#include <stdlib.h>

#include "hash_ligada.h"

void inicializar_hash(Tabela_Hash tabela){
    for(int i = 0; i < MAX ; i++)
        tabela[i] = NULL;
}

int chave_hash(int cod_pac){
    return (cod_pac % MAX);
}

void inserir(Tabela_Hash tabela, Paciente pac){
    int chave = chave_hash(pac.cod_pac);
    Elemento *anterior = NULL;
    Elemento *i= tabela[chave];
    while(i != NULL){
        if(i -> pac.cod_pac == pac.cod_pac)
            return;
        anterior = i;
        i = i -> proximo;
    }
    if (i == NULL){
        i = malloc (sizeof(Elemento));
        i -> pac = pac;
        i -> proximo = NULL;
        if (anterior == NULL)
            tabela[chave] = i;
        else
            anterior ->proximo = i;
    }
}

void imprimir_hash(Tabela_Hash tabela){
    Elemento *i;
    for(int j = 0; j < MAX; j++){
        if (tabela[j] != NULL){
            i = tabela[j];
            printf("Paciente: %d", j + 1);
            while(i != NULL){
                printf(" Nome: %s -->", i->pac.nome);
                i = i -> proximo;
            }
            printf(" VAZIO\n");
        }
        else
            printf("Paciente: %d VAZIO\n", j + 1);
    }
}

Paciente* busca(Tabela_Hash tabela, int cod_pac){
    int chave = chave_hash(cod_pac);
    Elemento *i= tabela[chave];
    while (i != NULL){
        if(i -> pac.cod_pac == cod_pac)
            return &i->pac;
        i = i -> proximo;
    }
    return NULL;
}

//Exercicio
void excluir (Tabela_Hash tabela, int cod_pac){
    int chave = chave_hash(cod_pac);
    Elemento *i = tabela[chave];
    if (i == NULL)
        return;
    Elemento *anterior = NULL;
    while (i != NULL){
        if (i->pac.cod_pac == cod_pac){
            if (anterior == NULL)
                tabela[chave] = i -> proximo;
            else
                anterior -> proximo = i -> proximo;
            free (i);
            return;
        }
        anterior = i;
        i = i -> proximo;
    }
};
