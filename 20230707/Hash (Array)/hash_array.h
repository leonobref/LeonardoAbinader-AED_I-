#ifndef HASH_ARRAY_H
#define HASH_ARRAY_H

#define MAX 100

typedef struct {
    int cod_pac;
    char *nome;
    char *cpf;
    int idade;
} Paciente;

typedef Paciente* Tabela_Hash[MAX];

void inicializa_hash(Tabela_Hash);
void inserir_hash (Tabela_Hash ,Paciente);
void imprimir_hash (Tabela_Hash);
Paciente* busca(Tabela_Hash, int);


#endif