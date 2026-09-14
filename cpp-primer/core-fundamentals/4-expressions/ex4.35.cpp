/* Exercise 4.35: Given the following definitions,  */
char cval;
float fval;
double dval;
int ival; unsigned int ui;
int main() {

/* identify the implicit type conversions, if any, taking place:    */
cval = 'a' + 3;         // 'a' is converted to int, expression returns int, the int is then converted to char
fval = ui - ival * 1.0; //  ival * 1.0 returns double and ui is converted to double too, fval changes everthing to float
dval = ui * fval;       // expression returns float and is converted to double
cval = ival + fval + dval;  // everything the expresion converted to double then later converted to char

}