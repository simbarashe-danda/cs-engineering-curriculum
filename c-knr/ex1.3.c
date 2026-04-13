// Modify the temperature conversion program to print a heading above the table
#include <stdio.h>

int main(void)
{
    float fahr, cels;
    int lower = 0; // lower limit
    int upper = 300; // upper limit
    int step = 20; // step size

    fahr = lower;
    // heading above table
    printf ("\tFahreneit-Celsius table\n\n");

    while (fahr <= upper) {
        cels = (5.0/9.0) * (fahr-32);
        printf ("\t%3.0f\t\t%6.2f\n",fahr,cels);
        fahr = fahr + step;
    }
    

}

