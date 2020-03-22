// C has a convenient shorthand for char arrays containing a sequence of
// ASCII codes with an extra '\0' value marking the end of the sequence.

//
// A number of C library functions accept zero-terminated char arrays
// For example printf with the "%s" specification (below)
//

//Try compiling and running with dcc and compare to gcc. 

#include <stdio.h>

//What will this do? Comment out any lines that stop it from compiling or running

int main(void) {
           
    char message0[5] = {'H','e','l','l','o','\0'};  
    char message1[6] = {'Z','e','l','l','o','\0'};
    char message2[] = {'J','e','l','l','o','\0'};
    char message3[] = {'H','e','l','l','o'}; 
    char message4[] = "Hello";
   
   
    printf("%s\n", message0);
    printf("%s\n", message1);
    printf("%s\n", message2);
    printf("%s\n", message3);
    printf("%s\n", message4);
    
    //We can print character by character too
    printf("%c\n",message2[2]);
    return 0;
}