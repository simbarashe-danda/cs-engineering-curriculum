/* In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x.
Explain why.
Use this observation to write a faster version of bitcount. */

// this follows from the realization that subtracting a bit vector v by : v-1,
// is guaranteed to negate or invert strictly only the right most 1, and not alter any other 1 in v
// v' = v-1. it follows that v'' =  v' & v has exactly the right most 1 from v removed from it

int bitcount(unsigned x) {
    int i = 0;
    while(x) {x &= (x-1); ++i; } // keep doing x & x' until no 1s left in x
    return i;
}
/* O(K) where k is set bits */