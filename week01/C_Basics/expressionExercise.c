// A simple program demonstrating expressions
// Try to work out what will be printed without running the program


#include <stdio.h>

int main(void){
    int answer1 =  6 * 7 - 8 * 9 /10;  
    int answer2 = 2*3*4+5*6;           
    int answer3 = 5*6/4;               
    int answer4 = 3/2;                 
    int answer5 = 1/2.0;               
    double answer6 = 1/2.0;            

    printf("%d\n",answer1);
    printf("%d\n",answer2);
    printf("%d\n",answer3);
    printf("%d\n",answer4);
    printf("%d\n",answer5);
    printf("%lf\n",answer6);

    return 0;
}