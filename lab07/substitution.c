//z5285978
#include<stdio.h>
#define LENGTH 28

int encrypt(int character, char sub[LENGTH]);

int main(void) {
    char sub[LENGTH];
    fgets(sub, LENGTH, stdin);
    
    int character = getchar();
    while (character != EOF) {
        putchar(encrypt(character, sub));
        character = getchar();
    }
    return 0;
}


int encrypt(int character, char sub[LENGTH]) {
    if (character >= 'a' && character <= 'z') {
        character = sub[character - 'a'];
    } else if (character >= 'A' && character <= 'Z') {
        character = sub[character - 'A'] - ('a' - 'A');
    }
    return character;
}
    