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
    novopaciente.disponivel = 0;
    int chave = chave_hash(novopaciente.cod_pac);
    if(tabela[chave] == NULL || tabela[chave]->disponivel == 1){
        if(tabela[chave] == NULL){
            tabela[chave] = malloc (sizeof(Paciente));
            *tabela[chave] = novopaciente;
            return;
        }
        if(tabela[chave]->disponivel == 1){
            tabela[chave]->cod_pac = novopaciente.cod_pac;
            tabela[chave]->cpf = novopaciente.cpf;
            tabela[chave]->disponivel = novopaciente.disponivel;
            tabela[chave]->idade = novopaciente.idade;
            tabela[chave]->nome = novopaciente.nome;
            return;
        }
    }
    else{
        while(tabela[chave] != NULL && tabela[chave]-> disponivel != 1){
            if(tabela[chave]->cod_pac == novopaciente.cod_pac)
                return;
            chave = (chave + 1) % MAX;
        }
        if(tabela[chave] == NULL){
            tabela[chave] = malloc (sizeof(Paciente));
            *tabela[chave] = novopaciente;
            return;
        }
        if(tabela[chave]->disponivel == 1){
            tabela[chave]->cod_pac = novopaciente.cod_pac;
            tabela[chave]->cpf = novopaciente.cpf;
            tabela[chave]->disponivel = novopaciente.disponivel;
            tabela[chave]->idade = novopaciente.idade;
            tabela[chave]->nome = novopaciente.nome;
            return;
        }
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

//Exercicio
void excluir(Tabela_Hash tabela, int cod_pac){
    int chave = chave_hash(cod_pac);
    if (tabela[chave] == NULL)
        return;
    while(tabela[chave] != NULL){
        if (tabela[chave]->cod_pac == cod_pac)
            tabela[chave]->disponivel = 1;
        chave = (chave + 1) % MAX;
    }
}