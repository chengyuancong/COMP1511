// An example of a local static variable
// These are local variables whose values
// are maintained between function calls.
// Again, not recommended in CP1511
 

#include <stdio.h>

int count(void) ;

int main(void) {
    printf("%d\n", count()); 
    printf("%d\n", count()); 
    printf("%d\n", count()); 
    return 0;
}

int count(void){
    //This initialisation only occurs once
    //not every time the function is called.
    static int callCount = 0; 
    callCount = callCount + 1;
    return callCount;
}
