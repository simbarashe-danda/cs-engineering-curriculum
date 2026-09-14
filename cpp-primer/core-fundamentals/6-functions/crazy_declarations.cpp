/* HARD TO READ  */

/* fcn returns pointer to an array of 10 ints */
int (*fcn(int)) [10];

/* fcn1 returns pointer to an array of 10 pointers to int */
int* (*fcn1(int)) [10];

/* fnPtr is a pointer to function(int),
that returns a pointer to an array of 10 ints */
int (*(*fcnPtr)(int))[10];

/* fnPtr1 is a pointer to function(int),
that returns a pointer to an array of 10 pointer to int */
int* (*(*fcnPtr1)(int))[10];

/* typedef, Easy to read */
typedef int arrTen[10]; // arrT is a type alias for an array of 10 ints, its not a variable
typedef int* arrTenptr[10]; // arrT is a type alias for an array of 10 pointers to int, its not a variable

arrTen* fn(int);  // same as fcn
arrTenptr* fn1(int); // same as fcn1
arrTen* (*fnPtr)(int); // same as fcnPtr
arrTenptr* (*fnPtr1)(int); // same as fcnPtr1t

auto ff(int) -> int (*)(int*, int); 
/* ff returns pointer to a function that returns int */


