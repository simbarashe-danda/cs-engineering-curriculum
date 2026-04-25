    /* Exercise 2-6.
    Write a function setbits(x,p,n,y) that returns x with the n bits that begin at 
    position p set to the rightmost n bits of y, leaving the other bits unchanged. */

    #include <stdio.h>
    unsigned setbits(unsigned, int, int, unsigned);

    int main(void)
    {
        unsigned x = 0xFFFF;    // [1111 1111 1111 1111]
        unsigned y = 0x00;    //   [0000 0000 0000 0000]
        printf("%b\n", setbits(x, 7, 4, y)); // should be [1111 1111 0000 1111]
        printf("0x%04X\n", setbits(x, 7, 4, y)); // hex format, should be 0xFF0F
    }

    /* assumes p and p are in range w-1 to 0, where w is word size */
    unsigned setbits(unsigned x, int p, int n, unsigned y) {

        unsigned rmy = y & ~(~0u << n); // right most n bits of y
        /* mask of n bits set to 0 starting at position p to n, 1 on rest */
        unsigned mask = ~(~(~0u << n) << (p+1-n));    

        x &= mask;  // eliminate x's bit on position p to n
        return x ^ (rmy << (p+1-n)); // if rmy bit is 1, its set, if 0, no need, 0 already there
    }

