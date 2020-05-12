// Write a function called myStrDup to duplicate a string
 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100


char * myStrDup(char * s);
int main(int argc, char * argv[]){
                   
    char s1[MAX] = "hello";
    char * s2 = s1;
    char * s3 = myStrDup(s1);
    
    printf("%s\n",s1);
    printf("%s\n",s2);
    printf("%s\n",s3);
    
    s2[0] = 'z';
    printf("%s\n",s1);
    printf("%s\n",s2);
    
    
    printf("%s\n",s3);
    free(s3);
    
    return EXIT_SUCCESS;
}

//A function to duplicate a string
char * myStrDup(char * s){
    
}