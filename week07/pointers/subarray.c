// Simple example illustrating use of pointers
// with array elements
// Andrew Taylor - andrewt@unsw.edu.au

#include <stdio.h>

void print_array(int array[], int array_length);

int main(void) {
    int nums[10] = {5,6,7,8,9,10,11,12,13,14};

    printf("Entire array: ");
    print_array(nums, 10);

    printf("Elements 3..6: ");
    print_array(&nums[3], 4);

    return 0;
}

void print_array(int array[], int array_length) {
    int i = 0;
    while (i < array_length) {
        printf("%d", array[i]);
        if (i != array_length - 1) {
            printf(",");
        }
        i = i + 1;
    }
    printf("\n");
}