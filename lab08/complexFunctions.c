// Calculate the magnitude of a complex number
// By ... (z0000000)
// Modified on 2019-0?-??

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// DO NOT CHANGE THIS STRUCT
typedef struct _complex {
    double real;
    double imaginary;
} complex;

complex complexAdd(complex a, complex b);
complex complexMultiply(complex a, complex b);
complex complexSquare(complex c);

// DO NOT CHANGE THIS MAIN FUNCTION
int main (int argc, char *argv[]) {

    complex complex1;
    complex complex2;

    printf("Enter the real part of the first number: ");
    scanf("%lf", &complex1.real);

    printf("Enter the imaginary part of the first number: ");
    scanf("%lf", &complex1.imaginary);

    printf("Enter the real part of the second number: ");
    scanf("%lf", &complex2.real);

    printf("Enter the imaginary part of the second number: ");
    scanf("%lf", &complex2.imaginary);

    // Calculate the sum
    complex added = complexAdd(complex1, complex2);

    // Print the sum.
    printf("The sum is %.2lf + %.2lfi.\n",
        added.real, added.imaginary);

    // Calculate the product.
    complex multiplied = complexMultiply(complex1, complex2);

    // Print the product.
    printf("The product is %.2lf + %.2lfi.\n",
        multiplied.real, multiplied.imaginary);

    // Calculate the square of the first complex number.
    complex squared = complexSquare(complex1);

    // Print it out.
    printf("The square of the first number is %.2lf + %.2lfi.\n",
        squared.real, squared.imaginary);

    return EXIT_SUCCESS;
}

// Calculate the sum of two complex numbers.
complex complexAdd(complex a, complex b) {
    a.real = a.real + b.real;
    a.imaginary = a.imaginary + b.imaginary;
    return a;
}

// Calculate the product of two complex numbers.
complex complexMultiply(complex a, complex b) {
    double real = a.real;
    a.real = a.real * b.real - a.imaginary * b.imaginary;
    a.imaginary = a.imaginary * b.real + real * b.imaginary;
    return a;
}

// Calculate the square of a complex number.
complex complexSquare(complex c) {
    double real = c.real;
    c.real = c.real * c.real - c.imaginary * c.imaginary;
    c.imaginary = c.imaginary * real + real * c.imaginary;
    return c;
}
