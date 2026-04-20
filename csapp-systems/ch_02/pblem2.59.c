/* 2.59 
Write a C expression that will yield a word consisting of the least significant byte of 
x and the remaining bytes of y. For operands x = 0x89ABCDEF and y = 0x76543210, 
this would give 0x765432EF. */

#include <stdio.h>
int operation(int* ,int*);

int main(void)
{ /* test */
    int xi = 0x89ABCDEF;
    int yi = 0x76543210;
    printf("%#X\n",  operation(&yi , &xi));
}
int operation(int* y, int* x) {
    return (((*y >> 8) << 8) + (*x & 0xFF));
    /* right and left shift so that last byte of y is 0x00.
      mask x so that we only have last byte left */
}
/* right left shift will clear the added bits to the left, whether logical or arithmetic */