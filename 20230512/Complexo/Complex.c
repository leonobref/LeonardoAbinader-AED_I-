#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "Complex.h"

Complex *create_complex(float a, float b){
    Complex *out = malloc (sizeof(Complex));
    out->real = a;
    out->imaginary =b;
    return out;
}

void destroy_complex(Complex *cpx){
    free(cpx);
}

void sum_complex(Complex *cpx1, Complex *cpx2){
    Complex *cpxsum;
    float cpxsumreal = cpx1 -> real + cpx2 -> real;
    float cpxsumimaginary = cpx1 -> imaginary + cpx2 -> imaginary;
    cpxsum = create_complex(cpxsumreal, cpxsumimaginary);
    printf("\nO resultado da soma dos numeros complexos I e II eh: %.1f + (%.1f)i", cpxsum -> real, cpxsum -> imaginary);
    free(cpxsum);
}

void sub_complex(Complex *cpx1, Complex *cpx2){
    Complex *cpxsub;
    float cpxsubreal = cpx1 -> real - cpx2 -> real;
    float cpxsubimaginary = cpx1 -> imaginary - cpx2 -> imaginary;
    cpxsub = create_complex(cpxsubreal, cpxsubimaginary);
    printf("\nO resultado da subtracao dos numeros complexos I e II eh: %.1f + (%.1f)i", cpxsub -> real, cpxsub -> imaginary);
    free(cpxsub);
}

void mult_complex(Complex *cpx1, Complex *cpx2){
    Complex *cpxmult;
    float cpxmultreal = (cpx1 -> real * cpx2 -> real) - (cpx1 -> imaginary * cpx2 -> imaginary);
    float cpxmultimaginary = (cpx1 -> real * cpx2 -> imaginary) + (cpx1 -> imaginary * cpx2 -> real);
    cpxmult = create_complex(cpxmultreal, cpxmultimaginary);
    printf("\nO resultado da multiplicacao dos numeros complexos I e II eh: %.1f + (%.1f)i", cpxmult -> real, cpxmult -> imaginary);
    free(cpxmult);
}

void div_complex(Complex *cpx1, Complex *cpx2){
    Complex *cpxdiv;
    float a = cpx1 -> real;
    float b = cpx1 -> imaginary;
    float c = cpx2 -> real;
    float d = cpx2 -> imaginary;
    float cpxdivreal = ((a*c) + (b*d))/((c*c)+(d*d));
    float cpxdivimaginary = ((c*b)-(a*d))/((c*c)+(d*d));
    cpxdiv = create_complex(cpxdivreal, cpxdivimaginary);
    printf("\nO resultado da divisao dos numeros complexos I e II eh: %.1f + (%.1f)i", cpxdiv -> real, cpxdiv -> imaginary);
    free(cpxdiv);
}
