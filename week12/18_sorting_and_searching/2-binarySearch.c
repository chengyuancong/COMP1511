//If we have data that is ordered, we can more efficiently search for data
//using a binary search. For unordered data a linear search is the best
//we can do

#include <stdio.h>
#include <stdlib.h>

int linearSearch(int array[], int length, int key);
int linearSearchOrdered(int array[], int length, int key);
int binarySearch(int array[], int length, int key);

int main(int argc, char * argv[]){
    int a1[] = {4,3,5,3,6,700,1,2,10,11};
    int a2[] = {1,2,3,3,4,5,6,10,11,700};
    int searchKey;
    printf("Enter a number to search for: ");
    scanf("%d",&searchKey);
    
    int found1 = linearSearch(a1,10,searchKey);
    
    int found2 = binarySearch(a2,10,searchKey);
    
    if(found1){
        printf("Found %d in a1\n",searchKey);
    } else {
        printf("Did NOT Find %d in a1\n",searchKey);
    }
    
    if(found2){
         printf("Found %d in a2\n",searchKey);
    } else {
         printf("Did NOT Find %d in a1\n",searchKey);
    }
    
    return EXIT_SUCCESS;
}

int linearSearch(int array[], int length, int key){
    for(int i=0; i < length; i++){
        if(array[i] == key){
            return 1;
        }
    }
    return 0;
} 

//This assumes the array we are searching in is in ascending order.
//But is not as efficient as binary search
int linearSearchOrdered(int array[], int length, int key){
    for(int i=0; i < length; i++){
        if(array[i] == key){
            return 1;
        }
        if(array[i] > key){
            return 0;
        }
    }
    return 0;
} 

//This assumes the array we are searching in is in ascending order.
int binarySearch(int array[], int length, int key) {
    int lower = 0;
    int upper = length - 1;
    while (lower <= upper) {
        int mid = (lower + upper)/ 2;
        if (array[mid] == key) {
            return 1;
        } else if (array[mid] > key) {
            upper = mid - 1;
        } else {
            lower = mid + 1;
        }
    }
    return 0;
}

w