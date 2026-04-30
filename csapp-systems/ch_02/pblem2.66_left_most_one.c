/* Write code to implement the following function: 
Generate mask indicating leftmost 1 in x. Assume w=32. 
Your code should contain a total of at most 15 arithmetic, bitwise, and logical 
operations. 
For example, OxFFOO —-> 0x8000, and 0x6600 --> 0x4000. 
If x = 0, then return 0. 
*/
#include <stdio.h>
int leftmost_one(unsigned); 

int main(void)
{
    /* testing */
    printf("0x%04x\n", leftmost_one(0xFF00)); // must be 0x8000
    printf("0x%04x\n", leftmost_one(0x6600)); // must be 0x4000
}

/* same method of divide and conquer or folding as pblem2.65 */
/* Assuming W=32 for unsigned int */
int leftmost_one(unsigned x) {
    /* set all bits right to highest oder 1 value bit to 1 */
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
    /* invert all bits right of highest 1 value bit  to 0. */
    return x ^ (x >> 1);
    /* 12 operations used,
    O(log_2_W) time where W is word size*/
}