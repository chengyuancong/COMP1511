//z5285978
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100


char * concat(char * s1, char * s2);

int main(int argc, char * argv[]){
    
    char s1[] = "Fun";
    char s2[MAX];
    
    //Assume fgets gets some valid input
    fgets(s2, MAX, stdin);
    int len = strlen(s2);
    
    //Remove newline if it exists
    if (len > 0 && s2[len -1 ] == '\n') {
        s2[len-1] = '\0';
    }
        
    char * s3 = concat(s1, s2);
    char * s4 = concat(s2, s1);
    char * s5 = concat("", s2);
    char * s6 = concat(s2, "");
    char * s7 = concat(s3, s3);
        
    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);
    printf("s3: %s\n", s3);
    printf("s4: %s\n", s4);
    printf("s5: %s\n", s5);
    printf("s6: %s\n", s6);
    printf("s7: %s\n", s7);
     
    free(s3);
    free(s4);
    free(s5);
    free(s6);
    free(s7);
    return EXIT_SUCCESS;
}

char * concat(char * s1, char * s2) {
    char * s3;
    s3 = malloc (strlen(s2) + strlen(s1) + 1);
    int i = 0;
    while (s1[i] != '\0') {
        s3[i] = s1[i];
        i++;
    }
    int j = 0;
    while (s2[j] != '\0') {
        s3[i + j] = s2[j];
        j++;
    }
    s3[i + j] = '\0';
    return s3;
}