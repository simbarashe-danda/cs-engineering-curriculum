/* You just started working for a company that is implementing a set of procedures 
to operate on a data structure where 4 signed bytes are packed into a 32-bit 
unsigned. Bytes within the word are numbered from 0 (least significant) to 3 (most significant).
You have been assigned the task of implementing a function 
for a machine using two’s-complement arithmetic and arithmetic right shifts with 
the following prototype: */

/* Declaration of data type where 4 bytes are packed  into an unsigned */ 
typedef unsigned packed_t; 
/* Extract byte from word. Return as signed integer */ 
int xbyte(packed_t word, int bytenum);

/* That is, the function will extract the designated byte and sign extend it to be a 32-bit int. 
Your predecessor (who was fired for incompetence) wrote the following code: */

/* Failed attempt at xbyte */ 
int xbyte(packed_t word, int bytenum) {
    return (word >> (bytenum << 3)) & 0xFF; 
}   

/* A. What is wrong with this code? 
that & 0xFF always extract last byte


B. Give a correct implementation of the function that uses only left and right shifts, along with one subtraction. */  
int xbyte_correct(packed_t word, int bytenum) {
    int sz = (3-bytenum) << 3;  // shift size. 3 comes from sizeof(int)-1, assume int is 4 bytes
    return ((int)word << sz) >> 24; // shift bit to left most then right to right most
}