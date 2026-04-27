/* Write code to implement the following function: 
 Return 1 when any odd bit of x equals 1; O otherwise. 
Assume w=32 */ 
#include <stdio.h>
int any_odd_one(unsigned); 

int main(void)
{
    /* testing */
    printf("%d\n", any_odd_one(0xFu)); // should be 1
    printf("%d\n", any_odd_one(0u)); // should be 0
    printf("%d\n", any_odd_one(0x55555555u)); // should be 0
}

int any_odd_one(unsigned x) {
    // 0xAA.. is bit mask, 1 on all odd positions, 0 all even. assumes w=32
    return !(!(x & 0xAAAAAAAAu)); // 1 if x has odd bit with val 1
}
