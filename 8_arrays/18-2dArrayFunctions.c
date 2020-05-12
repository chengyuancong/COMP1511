// An example of writing functions to initialise and print a 2d array.

#include <stdio.h>

/*
   0   1   2  
  ___________
0 |-1  -1  -1
1 |-1  -1  -1
2 |-1  -1  -1
3 |-1  -1  -1
4 |-1  -1  -1

*/

#define ROWS 5
#define COLS 3

// Initialise the first 'size' rows of the 2d numbers array 
// to the given value
void initialiseArray(int numbers[][COLS],int size, int value);

// print 'size' rows of the 2d array numbers.
void printArray(int numbers[][COLS],int size);

int main(void){
    
    int numbers[ROWS][COLS];
    int numbers2[10][COLS];
    int numbers3[10][10] = {{1,2,3,4,5,6,7,8,9,10}};
    int row,col;
     
    
    initialiseArray(numbers,ROWS,-1);
    printArray(numbers,ROWS);

    initialiseArray(numbers,ROWS,-1);
    printArray(numbers,2);
        
    initialiseArray(numbers2,ROWS,-1);
    printArray(numbers2,ROWS);
    
    //Don't do this.
    printArray(numbers3,ROWS);
    return 0;
}



// Initialise the first 'size' rows of the 2d numbers array 
// to the given value
void initialiseArray(int numbers[][COLS],int size, int value){
    int row,col;
    row = 0;
    while ( row < size){
        col = 0;
        while ( col < COLS){
            numbers[row][col] = value;
            col = col + 1;
        }
        row = row + 1;
    }
}

// print 'size' rows of the 2d array numbers.
void printArray(int numbers[][COLS],int size){
    printf("Printing array\n");
    int row,col;
    row = 0;
    while(row < size){
        col = 0;
        while(col < COLS){
             printf("%d ",numbers[row][col]);
             col = col + 1;
        }
        printf("\n");    
        row = row + 1;
    }
}