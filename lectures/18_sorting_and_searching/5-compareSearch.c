// Instrument linear search and binary search with an operation counter
// and compare their performance on a sorted arrays of random numbers.
//
// Array size is specified as a  command line argument

/*
//Note results will vary due to random data used
./compareSearch 1000000
Array size is 1000000, elements are:  3 10 14 6 26 49 61 69 72 73 105 130 36 137 141 58 150 184 197 159 209 ... 300000

Search for? 49
Linear search: 49 is in the numbers - search took 6 operations
Binary search: 49 is in the numbers - search took 20 operations

Search for? 42
Linear search: 42 is not in the numbers - search took 1000000 operations
Binary search: 42 is not in the numbers - search took 20 operations
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PRINT 20

int linearSearch(int array[], int length, int x);
int binarySearch(int array[], int length, int x);
void sortedInts(int array[], int length);
void printData(int array[], int length);
void doSearches(int array[], int length);

long long operationCounter;

int main(int argc, char *argv[]) {
    int * numbers;
    int i, length;
    srand(time(NULL));
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <array-size>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    length = atoi(argv[1]);
    
    numbers = malloc(length * sizeof (int));
    if (numbers == NULL) {
        fprintf(stderr, "Insufficient Memory\n");
        exit(EXIT_FAILURE);
    }

    sortedInts(numbers, length);
    printData(numbers,length);
    doSearches(numbers,length);
    
    free(numbers);
    return EXIT_SUCCESS;
}

void doSearches(int numbers[], int length){
    int searchKey;
    
    printf("Search for? ");
    while (scanf("%d",&searchKey) == 1) {
        operationCounter = 0;
        printf("\nLinear search: ");
        if (linearSearch(numbers, length, searchKey) == 1) {
            printf("%d is in the numbers", searchKey);
        } else {
            printf("%d is not in the numbers", searchKey);
        }
        printf(" - search took %lld operations\n", operationCounter);

        operationCounter = 0;
        printf("Binary search: ");
        if (binarySearch(numbers, length, searchKey) == 1) {
            printf("%d is in the numbers", searchKey);
        } else {
            printf("%d is not in the numbers", searchKey);
        }
        printf(" - search took %lld operations\n\n", operationCounter);
        printf("Search for? ");
    }
    printf("\n");
}


int linearSearch(int array[], int length, int x) {
    int i;
    for (i = 0; i < length; i = i + 1) {
        operationCounter++;
        if (array[i] == x) {
            return 1;
        }
    }
    return 0;
}

void sortedInts(int array[], int length) {
    int num = 0;
    for (int i = 0; i < length; i = i + 1) {
         num = num + rand() % (4);
         array[i] = num;
    }
}

void printData(int array[], int length){
    printf("Array size is %d, elements are: ", length);

    for (int i = 0; i < length; i = i + 1) {
        
        if (i == MAX_PRINT) {
            printf(" ... ");
            i = length;
        } else {
            printf(" %d", array[i]);
        }        
    }
    if(length > MAX_PRINT){
        printf(" %d", array[length-1]);
    }
    printf("\n");

}


int binarySearch(int array[], int length, int x) {
    int lower = 0;
    int upper = length - 1;
    while (lower <= upper) {
        int mid = (lower + upper)/ 2;
        operationCounter++;
        if (array[mid] == x) {
            return 1;
        } else if (array[mid] > x) {
            upper = mid - 1;
        } else {
            lower = mid + 1;
        }
    }
    return 0;
}

