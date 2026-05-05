/* Write code for a function with the following prototype: 
Do  rotating left shift. 
Assume 0<=n<w 
Examples when x = 0x12345678 and w = 32: 
n=4 -> 0x23456781, n=20 -> 0x67812345 
*/

#include <stdio.h>
unsigned rotate_left(unsigned, int); 

int main(void)
{
    /* testing */
    printf("0x%08X\n", rotate_left( 0x12345678, 4));  // should be 0x23456781
    printf("0x%08X\n", rotate_left( 0x12345678, 20)); // should be 0x67812345 
    printf("0x%08X\n", rotate_left( 0x12345678, 31)); // should be 0x091A2B3C
    printf("0x%08X\n", rotate_left( 0x12345678, 0));  // should be 0x12345678
 }

 /* circular left shift*/
unsigned rotate_left(unsigned x, int n) {
    unsigned w = sizeof(unsigned) << 3; // word size
    unsigned pos = w-n;  // w-n to determine location of wrapped bits

    /* move n left shifted bits of x to to the right most region */
    unsigned s1 = pos >> 1;   // incase n = 0, we dont want shift by w
    unsigned l_wrap =  (x >> s1) >> (pos-s1); // move l shift wrapped bits to right most region
    return (x << n) | l_wrap;  // circular left shift
}