#include <stdio.h>
#include <string.h>

int remove_duplicates(int length, int source[],int destination[]);

int main(void) {
    
    int source[10] = {2,4,6,8,8,4,10,2,20,6}; 
    int dest[10] =   {0};
    int numElements = remove_duplicates(10,source,dest);
    printf("num of non-dup elements:%d\n",numElements);
    for (int i=0; i<numElements; i++) {
        printf("%d ",dest[i]);
    }
    return 0;
}


int remove_duplicates(int length, int source[],int destination[]) {
    int sourceIndex = 0;
    int duplicate = 0;
    int destIndex = 0;
    while (sourceIndex < length) {
        int j = 0;
        //printf("i:%d, source[i]:%d \n",i,source[i]);
        duplicate = 0;
        while ((j < destIndex) && (!duplicate)) {
            // keep checking for duplicates
            //printf("j:%d, dest[j]:%d\n",j,destination[j]);

            if (source[sourceIndex] == destination[j]) {
                duplicate = 1;
            }
            j = j + 1;
        }
        if (!duplicate) {
            destination[destIndex] = source[sourceIndex];
            destIndex = destIndex + 1; 
        }
        sourceIndex = sourceIndex+1;
    }
    return destIndex;
}        
