// Write a C program odd_even_eof.c which reads integers from standard input until it reaches end-of-input. It should then print the odd numbers on one line then print the even numbers on one line.
// You may assume that the program?s input will contain only integers.
// Match the the example below EXACTLY.
/* $ ./odd_even_eof
 1
 2
 4
 16
 32
 64
 128
 256
 512
 1024
 2048
 4096
 Ctrl-D
Odd numbers were: 1
Even numbers were: 2 4 16 32 64 128 256 512 1024 2048 4096
*/
//You can assume at most 1000 integers will be read before end-of-input is reached.

#include <stdio.h>
#include <stdlib.h>


int main(void) {
    int oddArray[1000] = {0};
    int evenArray[1000] = {0};
    int oIndex = 0; 
    int eIndex = 0;
    int num=-1;
    while(scanf("%d",&num) ==1) {
        if (num % 2 == 0) {
            evenArray[eIndex++] = num;
        } else {
            oddArray[oIndex++] = num;
        }
    }
    printf("Odd numbers were:");
    if (num!=-1) { for (int i=0; i<=oIndex-1; i++) {
        printf("%d ",oddArray[i]);
    }
    printf("\nEven numbers were:");
    for (int i=0; i<=eIndex-1; i++) {
        printf("%d ",evenArray[i]);
    }
    }
    return 0;
}

