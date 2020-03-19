// Read lines until eof
// Try with different MAX_LINE values to see what happens 

#include <stdio.h>

//#define MAX_LINE 1024
#define MAX_LINE 10



int main(void) {
    char line[MAX_LINE];

    while(fgets(line,MAX_LINE,stdin) != NULL){
        printf("I read in %s\n",line);
    }
   
    return 0;
}