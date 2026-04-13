// Write a program to print corresponding Celsius to Fahreneit table
// The formula is °F = °C * 9/5 + 32
#include <stdio.h>

int main(void)
{
    float celsius, fahr;
    int lower = 0;
    int upper = 300;
    int step = 20;

    // heading above table
    printf ("\tCelsius to Fahreneit table\n\n");
    
    celsius = lower;
    while (celsius <= upper) {
        fahr = (celsius * 9.0/5.0) + 32;
        printf ("\t%3.0f\t\t%6.2f\n", celsius, fahr);
        celsius = celsius + step;
    }
}