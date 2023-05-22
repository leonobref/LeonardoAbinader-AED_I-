typedef struct{
    float side;
} Cube;

Cube *create_cube (float l);
void destroy_cube (Cube *cub);
float side_cube(Cube *cub);
float area_cube(Cube *cub);
float vol_cube(Cube *cub);