// Simple example reading a line of input and examining characters

//Input to try
//dog
//bird
//hello
//newline
//ctrl^d

//Try with different SIZE values to see what happens.


#include <stdio.h>
#include <string.h>

#define SIZE 1024
//#define SIZE 5


int main(void) {
   
    char input[SIZE];
   
    printf("Enter some input: ");
    if( fgets(input, SIZE, stdin) != NULL){
        printf("Input read %s\n",input);
    } else {
        printf("No input\n");
    }
    
    int len = strlen(input);
    printf("Len of string is %d\n",len);
    if( input[len-1] == '\n'){
       printf("I read in a whole line\n");
    } else {
        printf("I did not read in a whole line\n");
    }

    return 0;
}