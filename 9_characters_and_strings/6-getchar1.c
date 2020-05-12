// Reading and writing characters


#include <stdio.h>

int main(void) {
    int c;
    printf("Please enter a character: ");
    c = getchar();
    printf("%c", c);    
    putchar(c);
    putchar('\n');
    
    printf("The ASCII code of the %c is %d\n", c, c);
    
    return 0;
}