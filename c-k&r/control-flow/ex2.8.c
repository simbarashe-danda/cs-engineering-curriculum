/* Exercise 2-8.
Write a function rightrot(x,n) that returns the value of the integer x rotated 
to the right by n positions. */
#include <stdio.h>
unsigned rightrot(unsigned, int);

int main(void)
{
    /* testing */
    printf("0x%08X\n",  rightrot(0x00000001, 33)); // must be 0x80000000, n = 33 is same as n = 1
    printf("0x%08X\n", rightrot(0xF0000000, 4)); // must be 0x0F000000
    printf("0x%08X\n", rightrot(0x12345678, 8)); // 0x78123456
    printf("0x%08X\n", rightrot(0x000000FF, 4)); // 0xF000000F
}

/* circular shift */
unsigned rightrot(unsigned x, int n) {
    unsigned w = 8 * sizeof(unsigned);  // word size
    /* assume w = 32, rotating n >= word is same as rotating n mod 32. */
    unsigned rmb_mask = ~(~0u << (n % w)); // right most bits mask 
    rmb_mask &= x;  // 1 if rmb is 1 and vice versa
    x >>= (n % w); // right shift x
    /* shift rmb to last position (w-1), set rmb to w-1 to w-n+1 position of x */
    return x | (rmb_mask << (w-(n % w)) % w);  // outer %w prevents shift by w when n = 0
    // w - (n mod w) came from the expr (w-1) - (n+1), given n < w
}