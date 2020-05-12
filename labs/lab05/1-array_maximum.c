//z5285978

#include <stdio.h>

int array_maximum(int array[], int size);

#define MAX_SIZE 100

int main(void) {
    int size1 = 7;
    int array1[MAX_SIZE] = {3, 14, 15, 9, 2, 6, 5};

    int result1 = array_maximum(array1, size1);
    printf("The largest value from array1 is: %d\n", result1);

    int size2 = 10;
    int array2[MAX_SIZE] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

    int result2 = array_maximum(array2, size2);
    printf("The largest value from array2 is: %d\n", result2);
    return 0;
}

int array_maximum(int array[], int size) {
    int max = array[0];
    for (int i = 0; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}