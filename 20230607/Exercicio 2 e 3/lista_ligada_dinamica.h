#ifndef LISTA_LIGADA_DINAMICA
#define LISTA_LIGADA_DINAMICA

typedef struct aux{
    int numero;
    struct aux *proximo;
} Elemento;

typedef struct{
    Elemento *inicio;
} Lista;


//Funcoes padrao da Lista Ligada Dinamica
void inicializa_lista(Lista *);
void reinicializar_lista(Lista *);
int retornar_tamanho(Lista *);
void printar_lista(Lista *);
int retornar_vazia(Lista *);
void inserir_numero_ordenado_crescente(Lista *, int);
void inserir_numero_final(Lista *, int);
void excluir_numero_ordenado(Lista *, int);

#endif