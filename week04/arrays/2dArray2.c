// An example of initialising a 2d array using scanf
// and printing out the values 

#include <stdio.h>
#define NUM_ROWS 3
#define NUM_COLS 5


/*
  col           
   0   1   2   3   4
  __________________
0 |1   2   3   4   5  
1 |6   7   8   9   10  
2 |?   ?   ?   ?   ?

*/
int main(void){   
    int matrix[NUM_ROWS][NUM_COLS];  
    int row,col;
    printf("Enter %d integers\n", NUM_ROWS*NUM_COLS);
    
    //Read input from user
    row = 0;
    while(row < NUM_ROWS ){       
        col = 0;
        while( col < NUM_COLS ){
            scanf("%d",&matrix[row][col]);
            col = col + 1;
        }             
        row = row + 1;
    }
    
    //Print 2d array
    row = 0;
    while(row < NUM_ROWS ){       
        col = 0;
        while( col < NUM_COLS ){
            printf("%d ",matrix[row][col]);
            col = col + 1;
        }
        printf("\n");
        
        row = row + 1;
    }
    return 0;
}

