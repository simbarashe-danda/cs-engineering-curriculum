/* 2.65 
Write code to implement the following function: 
 Return 1 when x contains an odd number of 1s; O otherwise. 
Assume w=32. You may assume that data type int has w = 32 bits. 
Your code should contain a total of at most 12 arithmetic, bitwise, and logical 
operations. */ 
#include <stdio.h>
int odd_ones(unsigned); 

int main(void)
{
    /* testing */
    printf("%d\n", odd_ones(1u)); // must be 1
    printf("%d\n", odd_ones(0xF)); // must be 0
    printf("%d\n", odd_ones(-1)); // conversion to U_max. must be 0
    printf("%d\n", odd_ones(0x7FFFFFFFu)); // T_max, must be 1
}
/* This comes from realization that given bit sequence Y = [b_w-1, b_w-2,..., b1, b0 ],
b_w-1 ^ b_w-2 ^ ... ^ b1 ^ b0 will determine parity of the number of bit 1s in Y.
But doing this linearly is inefficient , O(W) time where W is word size

Below code is inspired by divide and conquer.
It comes from realizing that given |Y| = 2 where Y is bit vector, then
Y ^ (Y >> 2) is like folding the vector in half then apply XOR,
in other words we apply XOR of half the bits which are right most bits against half which left most.

Final realization was that shifting Y' >> k and appling XOR until last step k = 1:
expressed as Z = Y' ^ (Y >> 1), then
z0 represents our desired expression, that is to say
z0 = (b_w-1 ^ b_w-2 ^ ....^ b_1 ^ b_0).

This is O(log_2_W) time where W is word size
*/

int odd_ones(unsigned x) {
    /* assuming W = 32. */
    x ^= (x >> 16); // step 1
    x ^= (x >> 8);  // step 2
    x ^= (x >> 4);  // step 3
    x ^= (x >> 2);  // step 4
    return (x ^ (x >> 1)) & 1u;     // step 5 followed by masking LSB
    //  val(LSB) = 1 implies parity of 1 bits is odd, 0 implies even
    // 11 operations used
}