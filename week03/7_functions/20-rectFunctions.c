// An example of using functions to break
// down a nested loop into less complex parts

//Write a program that reads in a rows and columns from a user and prints out a rectangle of *. It repeats this until it gets non-numeric data.
//Step 1: Write a prototype for a function that prints a rectangle of given dimensions
//Step 2: Write the main function, using this function
//Step 3: Start writing the function, 
//      but to do so, create a prototype for a function that prints out a single row of * of a given size
//Step 4: Write the function that prints out a single row of *

#include <stdio.h>

void printRect(int rows, int columns);
//prints a row of size 'columns' of *
void printRow(int columns);

int main(void) {
    int rows, cols;
    printf("Enter rows and cols: ");
    while(scanf("%d %d",&rows,&cols) == 2){    
        printRect(rows,cols);
        printf("Enter rows and cols: ");
    }
    return 0;
}

void printRect(int rows, int columns){
    int i = 0;
    while(i < rows){
       printRow(columns);
       printf("\n");
       i = i + 1;
    }
}

//prints a row of size 'columns' of *
void printRow(int columns){
   int j;
   j = 0;
   while ( j < columns ){
      printf("*");
      j = j + 1;
   }
}