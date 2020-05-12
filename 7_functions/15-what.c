// Exercise: What does this print?
// Try to trace it through


#include <stdio.h>
#include <stdlib.h>

int f1(int x);
int f2(int x, int y);

int main(int argc, char * argv[]){
    int num1 = 10;
              
    int num2 = f1(num1);  
    printf("Answer is %d\n",num2);
   
    return 0;
}


int f1(int x){
    int result = f2(x,x*2);
    result = result + 1;
    return result;
}

 
int f2(int x, int y){
    return x+y;  
}