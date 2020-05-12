// example of using malloc to progressively allocate larger array as needed
// Read n numbers and print them in reverse order
// Andrew Taylor - andrewt@unsw.edu.au
// 27/4/2019

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n = 0;
    int arraySize = 4;
    int *array = malloc(arraySize * sizeof (int));
    if (array == NULL) {
        fprintf(stderr, "%s: malloc failed\n", argv[0]);
        return 1;
    }

    while (scanf("%d", &array[n]) == 1) {
        n = n + 1;
        if (n == arraySize) {

            // allocate larger array
            int newArraySize = 2 * arraySize;
            int *newArray = malloc(newArraySize * sizeof (int));
            if (newArray == NULL) {
                fprintf(stderr, "%s: malloc failed\n", argv[0]);
                return 1;
            }

            // copy contents of old array to new array
            for (int i = 0; i < arraySize; i = i + 1) {
                newArray[i] = array[i];
            }

            // deallocate old array
            free(array);

            // change pointer to new array
            array = newArray;
            arraySize = newArraySize;
            printf("Array size increased to %d\n", arraySize);
        }
    }


    printf("Numbers reversed are:\n");
    for (int i = n - 1; i >= 0; i = i - 1) {
        printf("%d\n", array[i]);
    }

    // free the allocated storage
    // this would happen on program exit anyway
    free(array);
    return 0;
}