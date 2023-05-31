#include <stdlib.h>
#include <stdio.h>

#include "lista_sequencial.h"

LIST *create_list(){
    LIST *out = malloc(sizeof(LIST));
    if (out != NULL)
        out -> students_quantity = 0;
    return out;
}

void destroy_lista(LIST **students_list){
    LIST *vec = *students_list;

    free(vec -> students_registration);
    free(vec);
    *students_list = NULL;
}

int return_students_quantity(LIST *students_list){
    if (students_list = NULL)
        return -1;
    else
        return students_list->students_quantity;
}

int full_list(LIST *students_list){
    
}
