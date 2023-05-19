typedef struct{
    float real;
    float imaginary;
} Complex;

Complex *create_complex (float x, float y);
void destroy_complex (Complex *cpx);
void sum_complex(Complex *cpx1, Complex *cpx2);
void sub_complex(Complex *cpx1, Complex *cpx2);
void mult_complex(Complex *cpx1, Complex *cpx2);
void div_complex(Complex *cpx1, Complex *cpx2);