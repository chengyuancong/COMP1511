// An example to illustrate variable scope and lifetime
// Try to work out what will happen if we try to compile and run this program.


#include <stdio.h>

int n=5;         // global variable, do not use those!
int bar(int n);  //prototype for bar
void foo(void);  //we added this prototype for foo

int main(void){
    int j = n;  //We moved this line up before the following line
    int i = j;  
   
    foo();
    printf("In main n is %d\n",n);
    return 0;
}

void foo(void){
    int n = 10;
    int i = 1; //We added this variable
    int j = i; 
    bar(n);
    printf("In foo n is %d\n",n);
    
}

int bar(int n){
    n = n + 5;
    printf("In bar n is %d\n",n);
    return ( n );
}