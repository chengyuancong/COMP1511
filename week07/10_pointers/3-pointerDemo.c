// Very first pointer example
 
#include <stdio.h>

 
int main(void) {
    int x = 10;
    //The variable p is of type int * 
    //which we also call int pointer or pointer to an int
    int *p = &x;
    int *p2 = NULL;      //NO ADDRESS
    //int *p3 = 99;      //This is illegal. 99 is not an address of an int 
    printf("Value   of p is %p\n",p);  //p and &x should be the same address
    printf("Address of x is %p\n",&x);
    printf("Address of p is %p\n",&p);  
    
    printf("x is %d\n",x);   //10
    
    printf("*p is %d\n",*p); //10
    *p = *p + 1;             //x = x+1     
    
    printf("x is %d\n",x);   //11
    printf("*p is %d\n",*p); //11
       
    //printf("*p2 is %d\n",*p2);  // NULL POINTER PROBLEM Don't dereference 
    
                                  // a NULL pointer.   
    
    
    char name[] = "Samuel";
    name[0] = "C";  // this is valid
    // name = "Jack";  // not valid - compiler error
    
    char *cp = "Samuel";
    // cp[0] = 'C';  // this will result in a run-time error. Because string literals in read-only memory are immutable
    cp = "Jack"; // this is valid
    
    
    
    return 0;
}