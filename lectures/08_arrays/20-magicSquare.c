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
    int isMagic = 1;
    int row, col, i;

    //Find the sum of the first row
    col = 0;
    while ( col < SIZE){
        firstRowSum = firstRowSum + square[0][col];
        col = col + 1;
    }

    //Check all the rows add up to firstRowSum
    row = 1;
    int sum = 0;
    while (row < SIZE){
        col = 0;
        sum = 0;
        while( col < SIZE){
            sum = sum + square[row][col];
            col = col + 1;
	    }       
        if( sum != firstRowSum){
            isMagic = 0;
	    }
        row = row + 1;
    }
    
    //Check columns
    col = 0;
    while (col < SIZE) {
        sum = 0;
        row = 0;
        while (row < SIZE) {
            sum = sum + square[row][col];
            row = row + 1;
        }
        if (sum != firstRowSum) {
            isMagic = 0;
        }
        col = col + 1;
    }
    
    //Check diagonals
    sum = 0;
    i = 0;  
    while ( i < SIZE ) {
        sum = sum + square[i][i];    
        i = i + 1;
    }
    if (sum != firstRowSum) {
        isMagic = 0;
    }
    
    sum = 0;
    i = 0;
    while ( i < SIZE ) {
        sum = sum + square[SIZE-i-1][i];      
        i = i + 1;
    }
    if (sum != firstRowSum) {
        isMagic = 0;
    }

    return isMagic;
}