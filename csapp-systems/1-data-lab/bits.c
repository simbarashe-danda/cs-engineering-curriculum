/* 
 * CS:APP Data Lab 
 * 
 * < Simbarashe Danda >
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
 /* logically, x ^ y is equivalent to (~x & y) | (x & ~y) which is equialent to 
    ~(~(~x & y) & ~(x & ~y)) */
  return ~(~(x & ~y) & ~(~x & y));  // x ^ y
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {

  return 1 << 31; // 2^31, Tmin

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  int Tmin; // decl

  Tmin = x + 1;  // Tmax if x was Tmax
  return !(~x ^ Tmin) & !(!Tmin); // check condition
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int y; // decl

  y = x;  
  /* invert all odd bits: 0 if 1, 1 if 0 */
  y =  y ^ 0xAA;  // byte 0
  y = y ^ (0xAA << 8); // byte 1
  y = y ^ (0xAA << 16);  // byte 2
  y = y ^ (0xAA << 24);  // byte 3

  /* now all  odd bit in the word are inverted, all 0 now if they were all 1 */
  return !(~x & y); // all even bits are set to 0. all odd must also be 0 now, then word must be 0 now,
  // but if an odd bit x, was 0 in the first place, its now 1 (0 ^ 1 is 1. (~0 is 1). 1 & 1 is 1)
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  /* declarations */
  int sign, cond1, cond2;

  sign = 1 << 31; // sign bit mask
  cond1 = x + (~0x30 + 1);  // condition 1, 0x30 <= x
  cond2 = 0x39 + (~x + 1); // condition 2, x <= 0x39

  /* extract sign bits. if both are 0, condition holds */
  cond1 = cond1 & sign;
  cond2 = cond2 & sign;

  return !(cond1 | cond2);  // 1 if both sign bits are 0
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  x = (!x) + ~0;  // -1 if true, 0 if false
  // same y and (1/0) OR z and ~(1/0)
  return (y & x) | (z & ~x );

}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  x = ~x + 1; // -x
  x = y + x;  // conditional check, 0 <= y-x
  x = x & (1 << 31);  // extract sign bit, 0 if condition is true
  return !x;  // 1 if condition holds
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  /* for the below process, it is guaranteed that if there exists atleast a bit set to 1 in x, lsb will also have bit set to 1. */
  /* keep "folding" the bit vector  */
  x = x | (x >> 16);
  x = x | (x >> 8);
  x = x | (x >> 4);
  x = x | (x >> 2);
  x = x | (x >> 1);
  /* lsb now 1 for all non zero */
  return (x & 0x1) ^ 0x1; // first mask lsb then invert it
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  /* declarations */
  int b16, b8, b4, b2, b1, b0, mask, x_norm;

  mask = x >> 31; // all 1 if x<0, all 0 if 0<=x 
  x_norm = x ^ mask;  //normalize x, invert 1 to 0 if x<0

  /* binary search */
  b16 = (!!(x_norm >> 16)) << 4; // check if there is any bit set to 1 in higher 16 bits. b16 is 16 or 0
  x_norm = x_norm >> b16; // if b is 16, focus on upper 16, else lower 16

  /* same logic upto lower or upper 0*/

  b8 = (!!(x_norm >> 8)) << 3;
  x_norm = x_norm >> b8; 

  b4 = (!!(x_norm >> 4)) << 2;
  x_norm = x_norm >> b4;

  b2 = (!!(x_norm >> 2)) << 1;
  x_norm = x_norm >> b2; 

  b1 = !!(x_norm >> 1);
  x_norm = x_norm >> b1;

  b0 = x_norm;  // 1 or 0
  return (b16 + b8 + b4 + b2 + b1 + b0) + 1; // sum recorded bit counts + sign bit count

}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  /* declarations */
  unsigned sign, exp, frac;

  sign = uf >> 31;    // sign bit
  exp = (uf >> 23) & 0xFF;    // exponent 
  frac = uf & 0x7FFFFF;   // fraction

  if (exp == 0xFF) return uf;   // case1 uf is special value: -inf , inf, NaN
  if (exp == 0) return (sign << 31) | (frac << 1); // case2 f is denormalized
  if (exp == 0xFE) return (sign << 31) | ((exp + 1) << 23);  // case3.1  f is normalized , 2*uf is overflow
  return (sign << 31) | ((exp + 1) << 23) | frac; // case3.2 f is normalized and no 2*uf overflow

}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  /* declarations */
  unsigned sign, exp, frac, M; int E;

  sign = uf >> 31;    // sign bit
  exp = (uf >> 23) & 0xFF;    // exponent 
  frac = uf & 0x7FFFFF;   // fraction
  E = exp - 127; // unbiasing

  /* over and underflow cases */
  if (E < 0) return 0;  // underflow
  if (E >= 31) return 0x80000000; // overflow

  /* restoring implicit leading 1 */
  M = (1 << 23) | frac;  // restore implict 1
  if (E > 23) M <<= (E - 23); // exponent too large
  else if (E < 23) M >>= (23 - E);  // exponent too large
  // else M is in correct range, no shift required

  /* sign bit */
  if (sign) return -M;
  return M;

}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {

    if (x > 127) return 0x7F800000; // too large, return +inf
    if (x < -149) return 0; // too small

    // exp = x + 127
    if (-126 <= x)  // normalized. frac = 0
      return (x + 127) << 23;   // shift exp into correct position. s=0, f=0

    // shift amount S for denorm is, S = 149 + x
    // denormalized
    return 1 << (149 + x);  // shift 1 into correct frac position
}