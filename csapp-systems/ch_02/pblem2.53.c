/* Fill in the following macro definitions to generate the double-precision values +infinity, 
—infinity, and —0; 

You cannot use any include files (such as math. h), but youcan make use of the 
fact that the largest finite number that can be represented with double precision 
is around 1.8 x 10^308.*/

#include <stdio.h>

#define POS_INFINITY (1.8e308 * 2.0)
#define NEG_INFINITY (1.8e308 * -2.0)
#define NEG_ZERO (1.0 / NEG_INFINITY)

int main(void) {   
    /* tests and results */
    printf("%lf\n", POS_INFINITY); // inf
    printf("%lf\n", NEG_INFINITY); // -inf
    printf("%lf\n", NEG_ZERO); // -0.00000
    return 0;
}

