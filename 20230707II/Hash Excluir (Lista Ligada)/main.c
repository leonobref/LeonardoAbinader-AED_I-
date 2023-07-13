#include <stdio.h>
#include "hash_ligada.h"

int main()
{
    Tabela_Hash A;
    Paciente P;
    inicializar_hash(A);


    P.cod_pac = 1290;
    P.nome = "Vinicius Jr";
    P.cpf = "545.683.238-92";
    P.idade = 18;
    inserir(A, P);
    
    P.cod_pac = 1191;
    P.nome = "Danilo Felix";
    P.cpf = "482.926.021-43";
    P.idade = 21;
    inserir(A, P);

    P.cod_pac = 1190;
    P.nome = "Caio Bertoldo";
    P.cpf = "453.178.287-91";
    P.idade = 19;
    inserir(A, P);

    imprimir_hash(A);

    excluir(A, 1290);
    printf("\n");
    imprimir_hash(A);
    return 0;
}
