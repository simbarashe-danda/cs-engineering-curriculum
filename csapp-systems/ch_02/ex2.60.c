/* 2.60 
Suppose we number the bytes in a w-bit word from 0 (least significant) to w/8 — 1  (most significant).
Write code for the following C function, which will return an  unsigned value in which byte i of argument x has been replaced by byte b: 
*/
#include <stdio.h>
unsigned replace_byte (unsigned, int, unsigned char); 
int main(void)
{
    /* tests */
    printf("%#X\n", replace_byte(0x12345678, 2, 0xAB));
    printf("%#X\n", replace_byte(0x12345678, 0, 0xAB));
    printf("%#X\n", replace_byte(0x12345678, 5, 0xAB));

    /* replace_byte(0x12345678, 2, OxAB) --> 0x12AB5678 
       replace_byte(0x12345678, 0, OxAB) --> 0x123456AB */
}
unsigned replace_byte (unsigned x, int i, unsigned char b) {
    if (i < sizeof x) { // prevent out of bound subscripts
        unsigned char* ptr = (unsigned char*)(&x); // ptr points to the first byte in x
        *(ptr+i) = b;
        return x;
    }
    printf("error!, max subscript value is %ld but %ld < %d\n", sizeof x, sizeof x, i);
    return x;
}

