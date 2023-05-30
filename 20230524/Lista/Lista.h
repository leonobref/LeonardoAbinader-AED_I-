typedef struct{
    int quantity;
    int  *vec;
} List;

List *create_list (int capacity);
void destroy_list (List **vec);
void insert_numbersnio(List *vec);
void insert_numbersio(List *vec);
void print_list_iterative(List *vec);
void sequencial_search(List *vec, int number);
void sequencial_search_ordened(List *vec, int number);
void binary_search_iterative(List *lista, int number);
void binary_search_recursive(List *lista, int number, int first, int last, int comp);
void print_list_recursive(List *lista, int first, int last);
void search_biggest_number_iterative(List *lista);
void search_biggest_number_recursive(List *lista, int size, int maior);
void search_lowest_number_iterative(List *lista);
void search_lowest_number_recursive(List *lista, int size, int menor);
int sum_all_numbers_iterative(List *lista);
int sum_all_numbers_recursive(List *lista, int size);
int product_all_numbers_iterative(List *lista);
int product_all_numbers_recursive(List *lista, int size);