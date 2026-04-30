/* You are given the task of writing a procedure int_size_is_32() that yields 1 
when run on a machine for which an int is 32 bits, and yields 0 otherwise.
You are not allowed to use the sizeof operator.
Here is a first attempt: */

/* The following code does not run properly on some machines */ 
int bad_int_size_is_32(){
    /* Set most significant bit (msb) of 32-bit machine */ 
    int set_msb = 1 << 31; 
    /* Shift past msb of 32-bit word */ 
    int beyond_msb = 1 << 32; 

    /* set_msb is nonzero when word size >= 32  beyond_msb is zero when word size <= 32 */ 
    return set_msb && !beyond_msb; 
}

/* A. When compiled and run on a 32-bit SUN SPARC, however, this procedure 
returns 0.
The following compiler message gives us an indication of the problem: 
warning: left shift count >= width of type */

/* In what way does our code fail to comply with the C standard? */
// Its undefined behaviour, hardware depended

/* B. Modify the code to run properly on any machine for which data type int is at least 32 bits. */
/* C. Modify the code to run properly on any machine for which data type int is  at least 16 bits. */

int good_int_is_32() {
    /* int is atleast 16 bits. shifting by 31 or 16 is UB  */
    int set_msb = ((1 << 15) << 15) << 1; // split shifts so we dont shift by a possible max: 16

    /* shifting by 32 is UB, split shifts */ 
    int beyond_msb = ((1 << 15) << 15) << 2; // avoids shifting by 32 or 16

    /* set_msb is nonzero when word size >= 32 beyond_msb is zero when word size <= 32 */ 
    return set_msb && !beyond_msb;  // must work properly
}
