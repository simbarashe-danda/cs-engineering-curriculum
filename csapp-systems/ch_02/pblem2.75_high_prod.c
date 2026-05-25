/* Suppose we want to compute the complete 2w-bit representation of x * y, where 
both x and y are unsigned, on a machine for which data type unsigned is w bits. 
The low-order w bits of the product can be computed with the expression x*y, so 
we only require a procedure with prototype */

unsigned unsigned_high_prod(unsigned x, unsigned y);

/* that computes the high-order w bits of x - y for unsigned variables. 
We have access to a library function with prototype */
int signed_high_prod(int x, int y); 

/* that computes the high-order w bits of x * y for the case where x and y are in two’s- 
complement form. Write code calling this procedure to implement the function 
for unsigned arguments. Justify the correctness of your solution. 
 */

unsigned unsigned_high_prod(unsigned x, unsigned y) {
    unsigned w = sizeof(unsigned) << 3; // word size
    unsigned x_sign = x >> (w-1); // sign bit of x
    unsigned y_sign = y >> (w-1); // sign bit of y

    return signed_high_prod((int)x, (int)y) + (x_sign * y) + (y_sign * x);
}
