/* Rewrite the temperature conversion program of section 1.2 to use a function for conversion*/

#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 20

float to_cels(int);   // declare the function takes int args and returns a float

int main(void)
{
    for (int fahr = LOWER; fahr <= UPPER; fahr+=STEP)
        printf("\t%d\t%.1f\n", fahr, to_cels(fahr));
    return 0;   // normal termination
}
/* function for converting Fahreneit-Celsius*/
float to_cels(int fahr) { // fahreneit is the parameter, returned type is float
    float cels = (5.0/9.0) * (fahr-32);
    return cels;    // return computed float value
}
