// An example of using malloc to store a string
// We can return the string from the function since
// we used malloc to get the memory for it on the heap

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100


char * myStrDup(char * s);
int main(int argc, char * argv[]){
        
                   
    char s1[MAX] = "hello";
    char * s2 = s1;
    char * s3 = myStrDup(s1);
    char * s4 = strdup(s1);
    
    printf("%s\n",s1);
    printf("%s\n",s2);
    printf("%s\n",s3);
    printf("%s\n",s4);
    
    s2[0] = 'z';
    printf("%s\n",s1);
    printf("%s\n",s2);
    printf("%s\n",s3);
    printf("%s\n",s4);
    
    free(s3);
    free(s4);
    
    return EXIT_SUCCESS;
}

//A function to duplicate a string
char * myStrDup(char * s){
    char * dup = malloc((strlen(s)+1) * sizeof (char));
    strcpy(dup,s);
    return dup;
}