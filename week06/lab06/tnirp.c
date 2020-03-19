//z5285978
#include<stdio.h>
#include<string.h>
#define MAX_LENGTH 20

void tnirp(char s[]);

int main(int argc, char * argv[]){
    char s[MAX_LENGTH];

    printf("Enter String:\n");
    // fgets returns NULL if it gets only a ctrl ^d
    if (fgets(s, MAX_LENGTH, stdin) != NULL) {
        tnirp(s);
    }
    //printf("%lu\n", strlen(s));
    return 0;
}

void tnirp(char s[]) {
    for (int i = strlen(s) - 1; i >= 0; i --) {
        if (s[i] != '\n' ) {
            putchar(s[i]);
        }
    }
    printf("\n");
}
        