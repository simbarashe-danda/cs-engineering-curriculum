/* Write code for a function with the following prototype: */
/* Addition that saturates to TMin or TMax */ 
#include <limits.h>
int saturating_add(int x, int y); 

/* Instead of overflowing the way normal two’s-complement addition does,
saturating addition returns TMax when there would be positive overflow,
and TMin when there would be negative overflow.
Saturating arithmetic is commonly used in programs that perform digital signal processing. 
*/

/* We overflow only happens if x and y have the same sign, but sum has a different one.*/
int saturating_add(int x, int y) {
    int w = sizeof(x) << 3; // word size
    int sum = x + y;    // possibly overflowed or not

    /* Detecting Overflow */
    // for both x and y, x ^ sum will have sign bit 1 if signs are different. after & if sign bit is 1, overflow ocurred
    int mask = ((x ^ sum) & (y ^ sum)) >> (w-1);    // all 1 if overflow, 0 otherwise

    /* saturation */
    int min_or_max = (y >> (w-1)) ^ INT_MAX;    // if sign bit of y is 1, result is Tmin, if 0 its Tmax
    return (mask & min_or_max) | (~mask & sum); // if there was overflow, mask is TMIN or TMAX, else its sum
}
