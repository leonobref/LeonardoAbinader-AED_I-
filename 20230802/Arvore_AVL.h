#ifndef ARVORE_AVL_H
#define ARVORE_AVL_H

typedef struct aux{
    int numero;
    struct aux* esquerda;
    struct aux* direita;
    int h;
} No;

typedef struct{
    No *Raiz;
} Arvore;

void inicializar_Arvore(Arvore *);
void adiciona_arvore(Arvore *, int);
void listar_arvore(Arvore *);
int contar_arvore(Arvore *);
No* buscar_no(Arvore *, int);

void listar_preordem(Arvore *);
void listar_inordem (Arvore *);
void listar_posordem(Arvore *);
#endif