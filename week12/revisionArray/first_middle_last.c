// Print the first, middle, and last elements of an array.

#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 100

void print_first_middle_last(int size, int array[size]);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    // Create an array.
    int array[MAX_ARRAY_SIZE];

    // Get the size of the array.
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);
    if (size > MAX_ARRAY_SIZE) {
        printf("Error: array is too big!\n");
        return 1;
    }

    // Scan values into the array.
    printf("Enter array values: ");
    int i = 0;
    while (i < size) {
        scanf("%d", &array[i]);
        i = i + 1;
    }

    print_first_middle_last(size, array);

    return 0;
}


// Print the first, middle, and last values of the array, on
// separate lines.
void print_first_middle_last(int size, int array[size]) {
    printf("%d\n", array[0]);
    int middle = size/2;
    printf("%d\n", array[middle]);
    printf("%d\n", array[size - 1]);
}