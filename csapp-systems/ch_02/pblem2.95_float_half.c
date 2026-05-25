/* Access bit-level representation floating-point number */ 
typedef unsigned float_bits;

/* Following the bit-level floating-point coding rules, implement the function with the following prototype: */
/* Compute 0.5*f. If f is NaN, then return f. */ 
float_bits float_half(float_bits f); 

/* For floating-point number f, this function computes 0.5 * f.
If f is NaN, your function should simply return f. */

float_bits float_half(float_bits f) {
    unsigned sign = f >> 31;    // sign bit
    unsigned exp = (f >> 23) & 0xFF;    // exponent region
    unsigned frac = f & 0x7FFFFF;   // fraction field

    unsigned r_bits = f & 0x3;  // the 2 right most bits of f. [b1, b0]
    unsigned implicit_one = 0x800000; // the implicit leading 1 of frac if f is normalized

    if (exp == 0xFF) return f; // f is special val : +/- infin, Nan

    if (exp == 0) { // f is denormalized. rounding to even
        if (r_bits == 0x3) return (sign << 31) | ((frac >> 1) + 1);    // round up
        return (sign << 31) | (frac >> 1); }  // round down

    if (exp == 1) { // normalized.if exp=1 then 0.5 * f : (exp - 1) will convert result to denormalized
        frac = implicit_one | frac; // frac field with implict 1 made explicit
        if (r_bits == 0x3) return (sign << 31) | ((frac >> 1) + 1);    // round up new frac field
        return (sign << 31) | (frac >> 1); }  // round down new frac

    return (sign << 31) | ((exp - 1) << 23) | frac; // f is normalized, 0.5 * f wont change form of f
}
/*
   2^k * f is same as frac << k for denormalized f, for normalized f its same as exp + k .
   for negative k, we therefore have : frac >> k and exp - 1 respectively.  */