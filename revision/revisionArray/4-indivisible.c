 //Write a C program indivisible.c which reads positive integers that are greater than 1 from standard input until it reaches end-of-input. It should then print the integers read which are not exactly divisible by any other of the integers read.
//
// In other words it should not print an integer if another integer that has been read is a factor of that number.
// For example:
// 3, 1, 4, 1, 5, 9
//
// ./indivisible
// 42
// 7
// 6
// 12
//
// Your function should return the following result:
// Indivisible numbers: 7 6

// You can assume that the program?s input will contain only integers.
//
// You may assume that all integers are >1.
//
// You can assume at most 1000 integers will be read before end-of-input is reached.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int upto = 0; int num;
    int inArray[1000] = {0};

    while (scanf("%d",&num) == 1) {
        inArray[upto] = num;
        upto++;
    }    
    printf("Indivisible numbers:");
    for (int i=0; i< upto; i++) {
        
        int j=0; 
        int isDivisible=0;
        while (!isDivisible && j<upto) {
            if (i!=j && inArray[i] % inArray[j] == 0) {
                isDivisible = 1;
            }
            j++;
        }
        if (!isDivisible) {
            printf("%d ",inArray[i]);
        }
        
    }

    return EXIT_SUCCESS;
}



