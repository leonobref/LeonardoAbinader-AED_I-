#ifndef LISTA_H
#define LISTA_H

typedef struct
{
    int students_quantity;
    int students_registration[100];
} LIST;

LIST *create_list();
void free_list (LIST **);
int return_students_quantity(LIST *);

#endif
