//An example of initialising and accessing values in a 2d array

#include <stdio.h>
#define MAX 3

/*
  col           
   0   1   2   3   4   5  
  ______________________
0 |1   2   3   4   5   6
1 |7   8   9  10  11  12
2 |99  -1  0  13  15   3

*/
int main(void){
    int matrix[MAX][MAX*2] = { {1,2,3,4,5,6},
                               {7,8,9,10,11,12},
                               {99,-1,0,13,15,3} };
    
    //This would initialise all values to 0
    //int matrix[MAX][MAX*2] = {{0}};

    //This would initialise all values to have garbage values
    //int matrix[MAX][MAX*2];
    
    //What does this code do?
    printf("%d\n",matrix[0][0]);  
    printf("%d\n",matrix[1][0]);   
    printf("%d\n",matrix[0][5]);  
    printf("%d\n",matrix[2][5]);  
    printf("%d ",matrix[3][0]);   
    printf("%d ",matrix[2][6]);   
    printf("%d ",matrix[1][6]);   
       
    return 0;
}

