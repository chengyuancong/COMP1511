// Writing and use a function that takes
// in 2 arrays of ints and their maximum size.
// The function should fill a third array with elements found in both
// the first array and the second array
// The function should return the number of common elements it found
 

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int findCommon(int array1[], int array2[], int common[], int size);
 

int main(void){
    
    // Find intersection - nums3 intersect nums4 = {3, 8}
    int nums3[] = {3, 4, 8, 3, 5, 4};
    int nums4[] = {3, 6, 7, 9, 8,10};
    
    int nums5[6];
    int result = findCommon(nums3,nums4,nums5,6);
    for (int i = 0; i < result; i++) {
        printf("%d ", nums5[i]);
    }    
    
    
    return EXIT_SUCCESS;
}

int findCommon(int array1[], int array2[], int common[], int size) {
    
    int counter=0;
    int i = 0;
    while (i < size) {  // this is for array1
        int j = 0;
        while (j < size) { // this is for array2
            if (array1[i] == array2[j]) {  // found a common element, but check if it already exists in the 
                                           // common array
                int index = 0;  int existsInCommon = 0;
                while (index < counter  && (existsInCommon == 0)) {
                    if (common[index] == array1[i]) {
                        existsInCommon = 1;
                    } 
                    index++;   
                }
                if (existsInCommon == 0) {
                    common[counter]=array1[i];
                    counter = counter + 1;
                }
            }
            j++;
        }
        i++;
    } 
    return counter;
}


