// Not finished: We will continue this in the next lecture....
// Read  SIZE x SIZE numbers and test if
// they form a magic square http://en.wikipedia.org/wiki/Magic_square
// We still need to check columns and diagonals 
// This will be done as a tutorial exercise (along with breaking it down into
// more functions).
//
// Andrew Taylor - andrewt@cse.unsw.edu.au
// 10/4/13

/*
//  Lo Shu Square
// 4  9  2   //0
// 3  5  7
// 8  1  6
//
// Magic square of primes
//  17  89  71
// 113  59   5
//  47  29 101
*/

#include <stdio.h>

#define SIZE 3

void readSquare(int square[SIZE][SIZE]);
void printSquare(int square[SIZE][SIZE]);
int checkMagic(int square[SIZE][SIZE]);

int main(void) {
    int square[SIZE][SIZE];
    int row,col;
    int sumRow0;
    int sumRow;
    int isMagic = 1;
    
    // read potential magic square
    printf("Enter %d numbers please:\n", SIZE*SIZE);
    readSquare(square);
   
    
    // print potential magic square
    printf("Numbers are:\n");
    printSquare(square);

    isMagic = checkMagic(square);    

    if(isMagic == 1){
        printf("It is magic\n");
    } else {
        printf("It is NOT magic\n");
    }
    return 0;
}

void readSquare(int square[SIZE][SIZE] ){
    int row,col;    
    row = 0;
    while(row < SIZE ){       
        col = 0;
        while( col < SIZE ){
            scanf("%d",&square[row][col]);
            col = col + 1;
        }             
        row = row + 1;
    }
}

void printSquare(int square[SIZE][SIZE]){
    int row,col;    
    row = 0;
    while(row < SIZE ){       
        col = 0;
        while( col < SIZE ){
            printf("%d ",square[row][col]);
            col = col + 1;
        }
        printf("\n");
        
        row = row + 1;
    }
}

//returns 1 if it is a magic square
//returns 0 otherwise
int checkMagic(int square[SIZE][SIZE]){
    int firstRowSum = 0;

    //Find the sum of the first row
    int col = 0;
    while ( col < SIZE){
        firstRowSum = firstRowSum + square[0][col];
        col = col + 1;
    }

    //Check all the rows add up to firstRowSum
    
   
    int row = 1;
    int rowSum = 0;
    while (row < SIZE){
        //Find the sum of the row
        col = 0;
        rowSum = 0;
        while( col < SIZE){
            rowSum = rowSum + square[row][col];
            col = col + 1;
	    }       
        if( rowSum != firstRowSum){
            return 0;
	    }
        row = row + 1;
    }
    // We still need to check columns and diagonals
    // This will be done as a tutorial exercise.
    return 1;
}