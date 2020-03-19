// Exercise: Write a program to allow the user to enter n
// and then print out the first n fibonacci numbers

// The first 2 numbers are 0 and 1 and the each number in the sequence is
// a sum of the previous 2 numbers
// 0 1 1 2 3 5 8 13 21 34 

#include <stdio.h>


int main(void) {
    double prev = 0;
    double curr = 1;
    double newNum;   
    int n;
   
    printf("Enter a value of n : ");
    scanf("%d",&n);

    int counter = 0;
   

    //I have added these if statements in case the
    //user enters a value of n < 2    
    if(n > 0){
        printf("%.0lf ",prev);
    } 
     if(n > 1){ 
        printf("%.0lf ",curr);
    } 

    while(counter < n-2){
        newNum = prev + curr;
        printf("%.0lf ",newNum);
        prev = curr;
        curr = newNum;
        counter = counter + 1;
    }
    printf("\n");
    return 0;
}