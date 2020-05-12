// As demonstrated in earlier lectures, factorial will overflow 
// an integer fairly soon, so we have used double.

#include <stdio.h>
#include <stdlib.h>

double factorial(double n);

int main(void){
     int n;
     printf("Enter n:  ");
     scanf("%d",&n);
     printf("%.0lf\n",factorial(n));
     return EXIT_SUCCESS;  
}

double factorial(double n){  
    if ( n <= 1 ){                 //Stopping Case
        return 1;
    } else {        
        return n * factorial(n-1); //Recursive Case
    }
}
