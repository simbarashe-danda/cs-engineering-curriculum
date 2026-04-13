#include <stdint.h>
#include <stdio.h>

/* application of fermat's little theorem.
computing the inverse k ^(p-2) of k modulo  a prime p for large integers */
int main(void) {
    /* test case */
    uint64_t base = 3;       // k
    uint64_t exp = 5;        // p - 2
    uint64_t p = 7;          // p
    uint64_t result = 1;     // Accumulator
    // YOUR LOOP HERE
    while (exp != 0) {
        if (exp & 1UL) // if least bit is 1
            result = (((__uint128_t)result) * base) % p; // result modulo p
        // temporary cast to 128-bit int
        base = (((__uint128_t) base) * base)%p;
        exp = exp >> 1;   // logical r-shift
    /* casting to u128int makes us apply mod p to large integers without overflow */
    }
    printf("Result: %lu\n", result);
    return 0;
}   