// Simple example illustrating use of pointers
// with array elements
// Andrew Taylor - andrewt@unsw.edu.au

#include <stdio.h>

// all 3 prototypes are equivalent
// because arrays are converted to pointers
void print_array(int length, int array[length]);
void print_array(int length, int array[]);
void print_array(int length, int *array);

int main(void) {
    int nums[10] = {5,6,7,8,9,10,11,12,13,14};

    printf("Entire array: ");
    print_array(10, nums);

    printf("Elements 3..6: ");
    print_array(4, &nums[3]);

    return 0;
}

void print_array(int length, int *array) {
    int i = 0;
    while (i < length) {
        printf("%d", array[i]);
        if (i != length - 1) {
            printf(",");
        }
        i = i + 1;
    }
    printf("\n");
}
