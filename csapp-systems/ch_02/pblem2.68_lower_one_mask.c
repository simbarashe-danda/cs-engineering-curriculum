/* Write code for a function with the following prototype: */

/* Mask with least signficant n bits set to 1 
 Examples: n = 6 --> 0x3F, n = 17 -->   0x1FFFF
Assume 1 <= n <= w  */

#include <stdio.h>
int lower_one_mask(int); 

int main(void)
{
    /* testing */
    printf("0x%X\n", lower_one_mask(6)); // must be 0x3F
    printf("0x%X\n", lower_one_mask(17)); // must be 0x1FFFF
    printf("0x%X\n", lower_one_mask(32)); // must be 0xFFFFFFFF
}

int lower_one_mask(int n) {
    /* to handle case where n = w, we first divide n by 2 */
    int d = n >> 1; // integer division by 2
    /* 0u prevents left shifing negative int */
    n = (~0u << d) << (n-d); // split shift incase n = w
    return ~n;  // create mask
}
