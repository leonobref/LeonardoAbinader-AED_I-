#include <stdio.h>
#include <stdlib.h>

#include "hash_array.h"

void inicializa_hash(Tabela_Hash tabela){
    for(int i = 0; i < MAX; i++){
        tabela[i] = NULL;
    }
};

int chave_hash(int cod_pac){
    return cod_pac % MAX;
}

void inserir_hash (Tabela_Hash tabela, Paciente novopaciente){
    int chave = chave_hash(novopaciente.cod_pac);
    if(tabela[chave] == NULL){
        tabela[chave] = malloc (sizeof(Paciente));
        *tabela[chave] = novopaciente;
        return;
    }
    else{
        while(tabela[chave] != NULL){
            if(tabela[chave]->cod_pac == novopaciente.cod_pac)
                return;
            chave = (chave + 1) % MAX;
        }
        tabela[chave] = malloc (sizeof(Paciente));
        *(tabela[chave]) = novopaciente;
        return;
    }
}

void imprimir_hash(Tabela_Hash tabela){
    for (int i = 0; i< MAX; i++){
        if(tabela[i] != NULL){
            printf("Paciente: %d", i + 1);
            printf(" Nome do paciente: %s\n", tabela[i]->nome);
        }
        else{
            printf("Paciente: %d VAZIO\n", i + 1);
        }
}
}

Paciente* busca(Tabela_Hash tabela, int cod_pac){
    int chave = chave_hash(cod_pac);
    if (tabela[chave] == NULL){
        return NULL;
    }
    while(tabela[chave] != NULL){
        if(tabela[chave]->cod_pac == cod_pac)
            return tabela[chave];
        chave = (chave + 1) % MAX;
    }
    return NULL;
}