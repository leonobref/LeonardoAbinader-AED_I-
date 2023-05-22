#include <stdio.h>
#include <stdlib.h>
#include "Cube.h"

int main()
{
    Cube *cubo;
    float lado;
    float ladofunc, area, volume;
    printf("Digite o lado do cubo: ");
    scanf("%f", &lado);
    cubo = create_cube(lado);

    printf("\nLado do cubo: %.1f\n", side_cube(cubo));
    printf("\nArea do cubo: %.1f\n", area_cube(cubo));
    printf("\nVolume do cubo: %.1f\n",vol_cube(cubo));
    free(cubo);

    return 0;
}
