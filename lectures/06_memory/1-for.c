// A program to demonstrate the use of for loops
// By Aarthi N
// 27/05/2019


#include <stdio.h>

int  main(void){
   
     // simple for loop - printing even nos
     int i,j;
     for (i=0; i<=10; i=i+2) {
          printf("%d \n", i);
     }
   
     // count up to 24

     for (int i = 0, j = 50; i < j; i++, j--) {
          printf("%d ", i);
     }
    
   
     // nested for loop
     long sum; 
     i = 1;  // Outer loop control variable     
     j = 1;  // Inner loop control variable     
     int count = 10; // No of sums to be calculated 

     // Run the outerloop for 10 times.
     for ( i = 1 ; i <= count ; i++ ) {
          // Calculate the sum of integers from 1 to i
          sum = 0;
          for (j = 1; j <=i; j++) {
          sum = sum + j;
          }
          printf("\n%d %ld", i, sum);
     }
   
     // is using a "for loop" the best idea?
   
     char ch;

     ch = 'a'; // initial value 
     for (int i = 0; ch != 'q'; i++) {
          scanf("%c", &ch);
     }
   
     // A while loop is a better choice for the above example
    
     return 0;
}