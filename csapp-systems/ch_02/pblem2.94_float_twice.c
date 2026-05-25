/* Access bit-level representation floating-point number */ 
typedef unsigned float_bits; 

/* Following the bit-level floating-point coding rules, implement the function with the following prototype: */
/* Compute 2*f. If f is NaN, then return f. */ 
float_bits float_twice(float_bits f);

/* For floating-point number f, this function computes 2.0 * f.
If f is NaN, your function should simply return f. */

float_bits float_twice(float_bits f) {
    unsigned sign = f >> 31;    // sign bit
    unsigned exp = (f >> 23) & 0xFF;    // exponent 
    unsigned frac = f & 0x7FFFFF;   // fraction

    if (exp == 0xFF) return f;   // case1 f is special value: -inf , inf, NaN
    if (exp == 0) return (sign << 31) | (frac << 1); // case2 f is denormalized
    if (exp == 0xFE) return (sign << 31) | ((exp + 1) << 23);  // case3.1  f is normalized , 2*f is overflow
    return (sign << 31) | ((exp + 1) << 23) | frac; // case3.2 f is normalized and no 2*f overflow

/*
    2^k * f is same as frac << k for denormalized f,
    for normalized f its same as exp + k .*/
}   