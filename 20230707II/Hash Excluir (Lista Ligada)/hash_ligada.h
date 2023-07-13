#ifndef HASH_LIGADA_H
#define HASH_LIGADA_H
#define MAX 100

typedef struct {
    int cod_pac;
    char *nome;
    char *cpf;
    int idade;
} Paciente;

typedef struct aux{
    Paciente pac;
    struct aux* proximo;
} Elemento;

typedef Elemento* Tabela_Hash[MAX];

void inicializar_hash(Tabela_Hash);
void inserir(Tabela_Hash, Paciente);
void imprimir_hash(Tabela_Hash);
Paciente* busca(Tabela_Hash , int);

//Exercicio
void excluir(Tabela_Hash, int);

#endif
