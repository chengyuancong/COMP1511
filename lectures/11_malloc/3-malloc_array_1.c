// simple example of using malloc to create an array
// Read n numbers and print them in reverse order
// Andrew Taylor - andrewt@unsw.edu.au
// 27/3/2019

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int n;
    printf("Read how many numbers? ");
    scanf("%d", &n);

    int *numbers = malloc(n * sizeof (int));
    if (numbers == NULL) {
        fprintf(stderr, "%s: malloc failed\n", argv[0]);
        return 1;
    }

    for (int i = 0; i < n; i = i + 1) {
        scanf("%d", &numbers[i]);
    }

    printf("Numbers reversed are:\n");
    for (int i = n - 1; i >= 0; i = i - 1) {
        printf("%d\n", numbers[i]);
    }

    // free the allocated storage
    // this would happen on program exit anyway
    free(numbers);
    return 0;
}