// Instrument bubblesort with an operation counter
// And also print out the time it took to run bubble sort
// and compare performance on arrays of random numbers of size 10..10000
// Note: these 'random' numbers will be the same each time as we
// have not initialised the random number generator using srand.



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// use a global variable to count operations
// at key points
long long operationCounter;
void printArray(int array[], int length);
void bubblesort(int array[], int length);
void randomInts(int array[], int length);

int checkOrder(int array[], int length);


int main(void) {
    clock_t start, stop;
    for (int n = 10; n <= 100000; n = n * 10) {
        int * numbers = malloc(sizeof(int) * n);
      
        randomInts(numbers, n);
        
        operationCounter = 0;
        start = clock();
        bubblesort(numbers, n);
        stop = clock();
       
        if(!checkOrder(numbers,n)){
            fprintf(stderr,"array not in order!");
            return EXIT_FAILURE;
            
        }
        printf("Array size %5d: ", n);
        
        long long time = (long long)((stop-start)/(CLOCKS_PER_SEC/1000));
        double time2 = difftime(stop,start);
        printf(" bubblesort took %8lld operations %8lld ms\n",
               operationCounter, 
               time);
      
        free(numbers);
    }
    return EXIT_SUCCESS;
    
}

// https://en.wikipedia.org/wiki/Bubble_sort

void bubblesort(int array[], int length) {
    int swapped = 1;
    while (swapped) {
        swapped = 0;
        for (int i = 1; i < length; i = i + 1) {
            operationCounter++;
            if (array[i] < array[i - 1]) {
                int tmp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = tmp;
                swapped = 1;
            }
        }
    }
}

void randomInts(int array[], int length) {
     for (int i = 0; i < length; i ++) {
        array[i] = rand() % (10 * length);
    }
}


void printArray(int array[], int length){
    for (int i = 0; i < length; i++) {
         printf("%d ",array[i]);
    }
    printf("\n");
}


int checkOrder(int array[], int length){
    for(int i= 1; i < length; i++){
        if(array[i-1] > array[i]){
            return 0;
        }
    }
    return 1;
}
w