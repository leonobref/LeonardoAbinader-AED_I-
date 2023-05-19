#include <stdio.h>
#include <stdlib.h>
#include "Cube.h"

Cube *create_cube(float l){
    Cube *out = malloc (sizeof(Cube));
    out-> side = l;
    return out;
}

void destroy_cube(Cube *cub){
    free(cub);
}

float side_cube(Cube *cub){
    return cub -> side;
}

float area_cube(Cube *cub){
    return (cub -> side) * (cub -> side);
}

float vol_cube(Cube *cub){
    return (cub -> side) * (cub -> side) * (cub -> side);
}