// An example to show you the dangers of defining expressions
// with #define. In this subject just stick to constant values


 
#include <stdio.h>

#define NUM1 30
#define NUM2 40

#define SUM NUM1+NUM2
#define AVERAGE  SUM/2


int main(void){    
    printf("Average is %d\n",AVERAGE);
    return 0;
}