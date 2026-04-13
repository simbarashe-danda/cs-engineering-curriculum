#include <stdio.h>
int main(void)
{
/* The least significant byte of x, with all other bits set to 0. [ 0x00000021*/
    __int32_t x = 0x87654321; // x is a 4 byte/ 32 bit integer
    __int32_t r = x & 0xFF;    // AND on 0 sets everthing to 0, with 1, everthing is unchanged

    printf("0x%.8x\n",r);

/* All but the least significant byte-of x complemented,
with the least significant  byte left unchanged. [Ox789ABC21] */
    __int32_t r2 = x ^ 0xFFFFFFFF ^ 0xFF; // xor on 1 compliments everthing, with zero everthing unchanged
    /* or*/ __int32_t r2b = x ^ ~0xFF;  // 1 compliments, 0 does nothing

    printf("0x%.8x\n",r2);
    printf("0x%.8x\n",r2b);

/* The least significant byte set to ·all ones, and all other bytes of x left ,unchanged. [Ox876543FF] */
    __int32_t r3 = x | 0xFF;   // OR with 0 doesnt change anthing, with 1 sets everthing to 1

    printf("0x%.8x\n",r3);

}


