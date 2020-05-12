// Modified by Aarthi
// This program reads integers from standard input until it reaches end-of-input. It then prints the most frequently occurring integer.
// If there is a tie for the most frequent integer, the program prints the largest integer that is tied for most frequent.


#include <stdio.h>
#define MAX_NUMBERS 100000

int frequency(int x, int length, int array[]);

int main(void) {
    int numbers[MAX_NUMBERS] = {0};

    int numElements = 0;
    int mostFrequentCount = 0;
    int mostFrequentElement = 0;
    
    while (numElements < MAX_NUMBERS && scanf("%d", &numbers[numElements]) == 1) {
        numElements++;
    }
        
    int i = 0;
    while (i < numElements) {
        int count = frequency(numbers[i], numElements, numbers);
        if ( (count > mostFrequentCount)  ||
             (count == mostFrequentCount && numbers[i] > mostFrequentElement) ) {
            mostFrequentCount = count;
            mostFrequentElement = numbers[i];
        }
        i = i + 1;
    }
    //printf("%d occurs %d times\n", mostFrequentElement, mostFrequentCount);
    printf("%d\n", mostFrequentElement);
}

int frequency(int x, int length, int array[]) {
    int i = 0;
    int count = 0;
    while (i < length) {
        if (array[i] == x) {
            count = count + 1;
        }
        i = i + 1;
    }
    return count;
}