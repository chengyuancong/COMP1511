// A simple program demonstrating integer division
// What will this program do?

#include <stdio.h>

int main(void){
     int answer1; 
     int answer2;
     answer1 = 1/2;  
     
     printf("1/2  is %d\n",answer1);
     answer2 = answer1/answer1;
     printf("1/2 divided by 1/2 is %d\n",answer2);
     
     return 0;
}