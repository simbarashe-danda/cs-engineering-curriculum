/* Write code for the function with the following prototype: 
Return 1 when x can be represented as an n-bit, 2's-complement number;
O otherwise 
Assume 1 <= n <= W
*/

#include <stdio.h>
int fits_bits(int, int);

int main(void)
{
    /* testing */
    printf("%d\n", fits_bits(1,1)); // must  be 0. if word was 1, 1 cant be represented(2's compliment)
    printf("%d\n", fits_bits(1,2)); // must be 1
    printf("%d\n", fits_bits(-1, 6)); // must be 1
    printf("%d\n", fits_bits(0xFFFF, 15)); // must be 0
}

/* The function is asking:
"If I had a 2's compliment computer where the word size was only n bits,
could it hold the value of x? "*/
int fits_bits(int x, int n) {
    int w = sizeof(int) << 3;   // word size
    int shft_size = w - n; // used in a test shift to determine if x pass the test
    int d = shft_size >> 1;    // incase n = 0, we dont want shift by w

    /* test shifting */
    int test = ((unsigned)x << d) << (shft_size - d); // discard all bits in x and leave only right most n
    test = (test >> d) >> (shft_size - d);    // shift back n bits to original position

    return x == test;   // if x == test then the test shift did not make x lose its value
}