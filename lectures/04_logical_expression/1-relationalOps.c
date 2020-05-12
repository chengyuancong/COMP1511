// A program demonstrating the use of relational operators


#include <stdio.h>


int main(void){
    int x = 5;    

    printf("x = %d\n",x);
    printf("x > 4 is %d\n",x > 4); 
    printf("x >=4 is %d\n",x >= 4);
    printf("x < 4 is %d\n",x < 4);
    printf("x != 4 is %d\n", x!= 4);
    printf("x == 4 is %d\n",x == 4);
    
    x = 4;    

    printf("\nx = %d\n",x);
    printf("x > 4 is %d\n",x > 4); 
    printf("x >=4 is %d\n",x >= 4);
    printf("x < 4 is %d\n",x < 4);
    printf("x != 4 is %d\n", x!= 4);
    printf("x == 4 is %d\n",x == 4);
    
    x = 1;    

    printf("\nx = %d\n",x);
    printf("x > 4 is %d\n",x > 4);
    printf("x >=4 is %d\n",x >= 4);
    printf("x < 4 is %d\n",x < 4);
    printf("x != 4 is %d\n", x!= 4);
    printf("x == 4 is %d\n",x == 4);
    
    return 0;
}
