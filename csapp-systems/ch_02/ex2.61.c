/* Write C expressions that evaluate to 1 when the following conditions are true and 
to 0 when they are false. Assume x is of type int.
Assuming two's complement int. */

#include <limits.h> // for testing
#include <stdio.h> // for testing

/* "Any" means there exist */

/* A. Any bit of x equals 1. */
int funct(int x) {
    return x  != 0; // if there is no bit 1 then all are 0
}
/* B. Any bit of x equals 0 */
int funct2(int x) {
    return (~x) != 0; // if there is no bit 0 then all are 1, negation must make them all 0
}

/* C. Any bit in the least significant byte of x equals 1.*/
int funct3(int x) {
    return (x & 0xFF) != 0; // false if all bits in lsb are 0
}

/* D. Any bit in the most significant byte of x equals 0. */
int funct4(int x) {
    int r_shift = (sizeof(x)-1 ) << 3; // value to shift msb right so its lsb
    int msb = (x >> r_shift) & 0xFF; // most significant byte
    return (msb ^ 0xFF) != 0; // false if all bits in msb are 1;
}

int main(void)
{
    // /* test for A */
    printf("%d\n", funct(4)); // should be 1
    printf("%d\n", funct(0)); // should be 0
    printf("%d\n", funct(INT_MIN)); // should be 1

    /* test for B */
    printf("%d\n", funct2(~0)); // must be 0
    printf("%d\n", funct2(0x7FFFFFFF)); // must be 1
    printf("%d\n", funct2(20)); // must be 1

    /* test for C */
    printf("%d\n", funct3(0x7B00)); // should be 0
    printf("%d\n", funct3(0)); // should be 0
    printf("%d\n", funct3(0x2893)); // should be 1
    printf("%d\n", funct3(0x7FFFFFFF)); // should be 1

    // /* test for D */
    printf("%d\n", funct4(0)); // should be 1
    printf("%d\n", funct4(0x7FFFFFFF)); // should be 1
    printf("%d\n", funct4(INT_MIN)); // should be 1
    printf("%d\n", funct4(~0)); // should be 0
    
}
