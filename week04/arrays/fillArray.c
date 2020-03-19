// Writing and use a function that takes
// in 2 arrays of ints and their maximum size.
// The function should fill the second array with any odd numbers found in
// the first array
// The function should return the number of odd integers it found
 

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int findOdd(int src[],int dest[],int maxSize);

int main(void){
    int nums1[MAX] = {2,9,-4,6,1};
    int nums2[MAX];

    int numOdd = findOdd(nums1,nums2,MAX);
    
    //Print out the odd numbers we found
    int i  = 0;
    while (i < numOdd){
        printf("%d\n",nums2[i]);
        i = i + 1;
    }
    return EXIT_SUCCESS;
}
//src 0 1 2  3 4
//    2 9 -4 6 1
//              i

//dest 0 1 2 3 4
//     9 1 ? ? ?
//         destIndex

//Takes in an array called src of size maxSize
//and fills the dest array with any odd integers from the src array
//and returns the number of odd integers it found
int findOdd(int src[],int dest[],int maxSize){
    int destIndex = 0;
    int i = 0;
    while( i < maxSize ){
        if(src[i] % 2 != 0){
            dest[destIndex] = src[i];
            destIndex = destIndex + 1;
        }
        i = i + 1;
    }
    return destIndex;
}

  