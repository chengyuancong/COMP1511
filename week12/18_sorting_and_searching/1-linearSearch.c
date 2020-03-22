//Linear searching functions.
//They start at index 0 of the array and search one by one...
//The linearSearchOrdered function makes use of exising order in the array
//It ends the search early if the number
//you are searching for can't be in the array when a larger value has
//been encountered.


#include <stdio.h>
#include <stdlib.h>

int linearSearch(int array[], int length, int key);
int linearSearchOrdered(int array[], int length, int key);

int main(int argc, char * argv[]){
    int a1[] = {4,3,5,3,6,700,1,2,10,11};
    int a2[] = {1,2,3,3,4,5,6,10,11,700};
    int searchKey;
    printf("Enter a number to search for: ");
    scanf("%d",&searchKey);
    
    int found1 = linearSearch(a1,10,searchKey);
    
    int found2 = linearSearchOrdered(a2,10,searchKey);
    
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
int linearSearchOrdered(int array[], int length, int key){
    for(int i=0; i < length; i++){
        if(array[i] == key){
            return 1;
        }
        //If array[i] > key then the rest of the array elements
        //will be too, since the array is in order
        if(array[i] > key){
            return 0;
        }
    }
    return 0;
} 
