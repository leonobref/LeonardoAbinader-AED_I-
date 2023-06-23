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
void inicializar_lista(Lista *);
void reinicializar_lista(Lista *);
int retornar_tamanho(Lista *);
void printar_lista(Lista *);
int retornar_vazia(Lista *);
void inserir_numero_ordenado_crescente(Lista *, int);
void inserir_numero_final(Lista *, int);
void excluir_numero_ordenado(Lista *, int);
void excluir_final(Lista *);

//Exercicio 2
Lista primeiro_vira_ultimo(Lista *);
Lista inverter_lista(Lista *);

//Exercício 3.
//Copia os elementos de L1 para L2.
void lista_copiar(Lista *, Lista *);
void concatenar(Lista *, Lista *);
Lista intercalar(Lista *L1, Lista *L2);
#endif