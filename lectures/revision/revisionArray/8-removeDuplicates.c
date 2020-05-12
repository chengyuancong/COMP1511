// Write a C function that removes duplicate elements from an array, by
// copying the non-duplicate values to a second array, i.e. only the
// first occurance of any value should be copied.
//
// Your function should take three parameters: the length of source
// array, the source array itself, and the destination array.
//
// Your function should return a single integer: the number of elements
// copied to the `dest` array.
//
// For example, if the `source` array contained the following 6
// elements:
// 3, 1, 4, 1, 5, 9
//
// Your function should copy these 5 values
// to the `dest` array:
// 3, 1, 4, 5, 9
//
// Your function should return the integer `5`, because there were 5
// values copied -- the second occurence of the digit `1` was not
// copied.
//
// You can assume the array only contains positive integers.
//
// You can assume that the `dest` array will always be large enough to
// fit all of the copied values.
//
// You cannot assume anything about the number of duplicates, i.e. there
// may not be any duplicates, or conversely, the entire array may be
// duplicates.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SOURCE1_LEN 5
#define ANS1_LEN 4

#define SOURCE2_LEN 5
#define ANS2_LEN 1

#define SOURCE3_LEN 5
#define ANS3_LEN 5

int removeDuplicates(int size, int source[], int dest[]);
void printArray(int size, int array[]);
void checkAnswer(int destLen, int dest[], int ansLen, int ans[]);

int main(int argc, char *argv[]) {

    int source1[SOURCE1_LEN] = {1, 1, 2, 3, 5};
    int dest1[SOURCE1_LEN] = {0};
    int dest1Len = removeDuplicates(SOURCE1_LEN, source1, dest1);
    int ans1[ANS1_LEN] = {1, 2, 3, 5};
    checkAnswer(dest1Len, dest1, ANS1_LEN, ans1);

    int source2[SOURCE2_LEN] = {1, 1, 1, 1, 1};
    int dest2[SOURCE2_LEN] = {0};
    int dest2Len = removeDuplicates(SOURCE2_LEN, source2, dest2);
    int ans2[ANS2_LEN] = {1};
    checkAnswer(dest2Len, dest2, ANS2_LEN, ans2);

    int source3[SOURCE3_LEN] = {1, 2, 3, 4, 5};
    int dest3[SOURCE3_LEN] = {0};
    int dest3Len = removeDuplicates(SOURCE3_LEN, source3, dest3);
    int ans3[ANS3_LEN] = {1, 2, 3, 4, 5};
    checkAnswer(dest3Len, dest3, ANS3_LEN, ans3);

    printf("All tests passed, you are Awesome!\n");
    printf(".... but the real exam will have more tests, so make sure "
           "you do your own testing...\n");

    return EXIT_SUCCESS;
}

int removeDuplicates(int size, int source[], int dest[]) {
    
    int upto = 0;
    int a1 = 0;
    while (a1 < size) {
        int found = 0;
        int a2 = 0;
        while ((a2 < upto) && !found) {
            if (source[a1] == dest[a2]) {
                found = 1;
            } else {
                a2++;
            }
        }
        if (!found) {
           dest[upto] = source[a1];
           upto = upto + 1;
        }
        a1 = a1 + 1;
    }
    return upto;
}

// You may want to use this to help debug your code
void printArray(int size, int array[]) {

    for (int i=0; i<size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}


void checkAnswer(int destLen, int dest[], int ansLen, int ans[]) {
    printf("The correct answer: ");
    printArray(ansLen, ans);

    printf("Your array: ");
    printArray(destLen, dest);

    printf("ansLen: %d, destLen: %d\n", ansLen, destLen);
    assert(destLen == ansLen);
    int i = 0;
    while (i < ansLen) {
        assert(dest[i] == ans[i]);
        i++;
    }
}
