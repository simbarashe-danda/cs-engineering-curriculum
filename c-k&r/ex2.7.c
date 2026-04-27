/* Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at 
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged. */

#include <stdio.h>
unsigned invert(unsigned, int, int);

int main(void)
{   /* testing */
    unsigned x = 0xFFFF;
    printf("0x%04X\n", invert(x,7,4)); // should be 0xFF0F
    printf("0x%04X\n", invert(0x0000,7,4)); // should be 0x00F0;
}

unsigned invert(unsigned x, int p, int n) {
    /* create n bits set to 1, then shift then into p-n position */
    unsigned mask = ~(~0u << n) << (p+1-n);  // create mask with 1s at p-n, 0 rest
    return x ^ mask;    // invert x's bits at p-n
}