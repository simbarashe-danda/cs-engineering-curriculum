/* Write a function div16 that returns the value x/16 for integer argument x.
Your function should not use division, modulus, multiplication, any conditionals (if or ?:),
any comparison operators (e.g., <, >,or==), or any loops.
You may assume that data type int  is 32 bits long and uses a two’s-complement representation, and
that right shifts are performed arithmetically.*/

#include <stdint.h>
#include <stdio.h>

int32_t div16(int32_t);

int main(void)
{
    printf("%d\n", div16(-65));
    printf("%d\n", div16(-65));
    return 0;
}

int32_t div16(int32_t x)
{
    /* compute bias. >> 31 is 0 if x>=0 */
    int32_t bias = (x >> 31) & 0xF; // 0 if x>=0 , else 15
    return (x + bias) >> 4;  // x / 2^4
}