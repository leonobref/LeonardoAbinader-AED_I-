typedef struct{
    int student_code;
    char student_name[100];
    int student_age;
    float student_coefficient;
} Aluno;

typedef struct{
    Aluno *students_list;
    int students_quantity;
} Turma;

Turma *create_class(int);
void insert_students(Turma *);
void destroy_class(Turma **);
void print_students (Turma *);
void search_student_sequential(Turma *, int);
void search_student_binary_recursive(Turma *, int, int, int);
