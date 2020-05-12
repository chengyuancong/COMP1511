// A simple program demonstrating the use of printf for ints
// And demonstrating that C can understand decimal and hex formats
// and display the same number in different ways with different 
// conversion specifiers (ie %d for decimal and %x for hexadecimal in this example)

#include <stdio.h>

int main(void) {

    //print out a decimal number as a decimal then in hexadecimal
    printf("%d \n",36769);
    printf("%x \n",36769);
    
    //print out a hexadecimal number as a decimal then in hexadecimal
    printf("%d \n",0x8fa1 );
    printf("%x \n",0x8fa1);
        
    return 0;
}