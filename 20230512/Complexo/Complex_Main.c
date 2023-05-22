#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "Complex.h"

int main()
{
    Complex *cpx1, *cpx2;
    cpx1 = create_complex(2, 5);
    cpx2 = create_complex(1, 3);
    sum_complex(cpx1, cpx2);
    sub_complex(cpx1, cpx2);
    mult_complex(cpx1,cpx2);
    div_complex(cpx1,cpx2);
    destroy_complex(cpx1);
    destroy_complex(cpx2);
    return 0;
}
