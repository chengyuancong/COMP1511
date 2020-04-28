//We will use some of these functions
//in the next programs to compare out searching and sorting algorithms


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sortedInts(int array[], int length);
void randomInts(int array[], int length);
void printArray(int array[], int length);

int main(void) {
    int numbers[10];
    //Current time.
    srand((unsigned)time(NULL));
   
    sortedInts(numbers, 10);
    printArray(numbers,10);
      
       
    return EXIT_SUCCESS;    
}


void randomInts(int array[], int length) {
     for (int i = 0; i < length; i = i + 1) {
        array[i] = rand() % (10 * length);
    }
}

//generate sorted numbers in random increments
void sortedInts(int array[], int length) {
    int num = 0;
    for (int i = 0; i < length; i = i + 1) {
         num = num + rand() % (4);
         array[i] = num;
    }
}

void printArray(int array[], int length){
    for (int i = 0; i < length; i = i + 1) {
         printf("%d ",array[i]);
    }
    printf("\n");
}