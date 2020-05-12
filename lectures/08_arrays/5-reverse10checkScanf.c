// Read 10 numbers and print them in reverse order
// This version checks that the scanf was able to read the number
 

#include <stdio.h>

#define N_NUMBERS 10

int main(void) {
    int x[N_NUMBERS], i, j;

    printf("Enter %d numbers: ", N_NUMBERS);
    i = 0;
    while (i < N_NUMBERS && scanf("%d", &x[i]) == 1) {
          
        i = i + 1;
    }
    if (i < N_NUMBERS) {
        printf("Insufficient numbers read\n");
    } else {
        printf("Numbers reversed are:\n");
        j = N_NUMBERS - 1;
        while (j >= 0) {
            printf("%d\n", x[j]);
            j = j - 1;
        }
    }
    return 0;
}