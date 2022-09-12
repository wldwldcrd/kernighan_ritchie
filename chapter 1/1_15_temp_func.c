#include <stdio.h>

// convert fahr to celsius

#define LOWER   0
#define UPPER   300
#define STEP    20

float fahr_from_celsius(float celsius);

int main() {
    float celsius;

    printf("Celsius\tFarh\n");

    for (celsius = UPPER; celsius >= LOWER; celsius-= STEP)
    {
        printf("%7.0f\t%5.1f\n", celsius, fahr_from_celsius(celsius));
    }
    
    return 0;
}

float fahr_from_celsius(float celsius) {
    return (9.0/5 * celsius + 32);
}