/* 2.63 
Fill in code for the following C functions.

Function srl performs a logical right shift using an arithmetic right shift (given by value xsra),
followed by other operations not including right shifts or division.

Function sra performs an arithmetic  right shift using a logical right shift (given by value xsrl),
followed by other operations not including right shifts or division.
 
You may use the computation  8*sizeof (int) to determine w, the number of bits in data type int.
The shift amount k can range from 0 to w — 1. 
*/
#include <stdio.h>

unsigned srl(unsigned x, int k) { 
/* Perform shift arithmetically */ 
unsigned xsra = (int) x >> k;  // xrsa currently has shift bits to 1 if msb was 1

unsigned w = 8 * sizeof(unsigned); // compute word size
/* generate mask 0x00FF...*/
unsigned mask = ~0u;    // compute unsigned val with all bits set to 1
mask = ~(mask << (w-k-1));  // if k from (x >> k) is 8 then mask is 0x00FFF...
xsra = xsra ^ mask; // negate to 0 if bit is 1 and 1 if 0
/* logical right shift */
return ~xsra; // negation will turn arithmetic bits to 0 and rest to original

/* if xrsa originally had shift bits set to 0, then process wont do harm, 
   since masking will turn them to 1 and final negating on xrsa will turn them back to 0. */
} 

int sra (int x, int k){
    /* Perform shift logically */ 
    int xsrl = (unsigned) x >> k; // currently has shift bits set to 0

    /* isolate msb */
    int w = 8 * sizeof(int); // compute word size
    int msb_mask = 1 << (w-1); // msb_mask now has bit 1 on position w-1, 0 rest
    int msb = x & msb_mask; // what remains is msb val on w-1, 1 or 0; rest is 0

    /* generate mask */
    int mask = !msb; // if msb was non zero, it is now 0 and vice versa
    // by mask-1, if mask was 1,bits  now all 1; if was 0, bits now all 0
    mask = (mask-1 << (w-k-1)); // final mask. either 0xFF00... or 0x00..

    /* arithmetic right shift */
    return (xsrl | mask);  // shift bits 1 if msb was 1, 0 otherwise
}

/* testing */
int main(void)
{
    printf("0x%08X\n", srl(0xFFFFFFFF, 15)); // should be 0X0000FFFF
    printf("0x%08X\n", sra(-1, 15)); // should be 0xFFFFFFFF
    printf("0x%08X\n", sra(0x7FFFFFFF, 15)); // should be 0x0000FFFF

}