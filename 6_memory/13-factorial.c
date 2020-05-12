// Exercise: Write a program to allow the user to enter n
// and then print out n!

// n! = 1*2*3..*n

// 6! = 1*2*3*4*5*6 = 720

#include <stdio.h>


int main(void){
    int n;
    int i;
    double fac;
    printf("Enter n: ");
    scanf("%d",&n);
    fac = 1;
    i = 1;
    while( i <= n){
        fac = fac*i;
        i = i + 1;
    } 
    
    printf("%lf\n",fac);
    return 0;
}