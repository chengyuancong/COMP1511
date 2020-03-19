//An example of explicity casting from one type to another
 

#include <stdio.h>

int main(void) {
    int x = 42;
    int y = 11;
    double f;

    f = x / y;
    printf("42/11=%f\n", f); // prints 3.000000
    
    f = x/((double)y);       // convert/cast y to a double
    printf("42/11=%f\n", f); // prints 3.818182
    return 0;
}