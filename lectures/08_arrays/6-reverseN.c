// Read n numbers and print them in reverse order
  
//
// Note for simplicity we are assuming scanf succeeds in reading an integer.
// A robust program would check that scanf returns 1 to indicate an integer read.
//

#include <stdio.h>

#define MAX_NUMBERS 1000000

int main(void) {
    int x[MAX_NUMBERS], i, j, howMany;

    printf("Read how many numbers? ");
    scanf("%d", &howMany);

    if (howMany > MAX_NUMBERS) {
        printf("I'm sorry. I'm afraid I can't do that.\n");
        printf("Reading %d numbers\n", MAX_NUMBERS);
        howMany = MAX_NUMBERS;
    }

    i = 0;
    while (i < howMany) {
        scanf("%d", &x[i]);
        i = i + 1;
    }
    printf("Numbers reversed are:\n");

    j = howMany - 1;
    while (j >= 0) {
        printf("%d\n", x[j]);
        j = j - 1;
    }
    return 0;
}