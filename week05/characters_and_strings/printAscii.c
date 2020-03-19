// Print the 128 ASCII character encodings

#include <stdio.h>

#define ASCII_ENCODINGS 128


int main(void) {
    int i = 0;
    
    while(i < ASCII_ENCODINGS){
        printf("%d is %c\n",i,i);
        i = i + 1;
    }
    return 0;
}