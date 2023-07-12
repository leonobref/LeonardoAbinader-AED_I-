#ifndef HASH_LIGADA_H
#define HASH_LIGADA_H
//#define MAX 9
#define MAX 11

typedef struct aux{
    int numero;
    struct aux* proximo;
} Elemento;

typedef Elemento* Tabela_Hash[MAX];

void inicializar_hash(Tabela_Hash);
int chave_hash(int);
void inserir(Tabela_Hash, int);
void imprimir_hash(Tabela_Hash);
int* busca(Tabela_Hash , int);

#endif
