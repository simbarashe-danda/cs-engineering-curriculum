/* 2.62 
Write a function int_shifts_are_arithmetic() that yields 1 when run on a 
machine that uses arithmetic right shifts for data type int and yields 0 otherwise. 
Your code should work on a machine with any word size. Test your code on several  machines. */

#include <limits.h>
#include <stdio.h>
int int_shifts_are_arithmetic(void) {
    int word_size = sizeof(-7) << 3; // -7 is just a chosen negative val
    return (-7 >> (word_size-1)) == -1; // if arith right shift then value must be -1
}
/* test */
int main(void){
    printf("%d\n", int_shifts_are_arithmetic()); // should be 1 if arithmetic shift
}