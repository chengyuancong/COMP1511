//Initialising a 2d array using a while loop

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

int main(void){
    int numbers[ROWS][COLS];
    int row,col;
     
    //Initialise all elements to -1       
    row = 0;
    while ( row < ROWS){
        col = 0;
        while ( col < COLS){
            numbers[row][col] = -1;
            col = col + 1;
        }
        row = row + 1;
    }
       
    //print the array
    row = 0;
    while(row < ROWS){
        col = 0;
        while(col < COLS){
             printf("%d ",numbers[row][col]);
             col = col + 1;
        }
        printf("\n");    
        row = row + 1;
    }
        
    return 0;
}

