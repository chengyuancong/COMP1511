//z5285978
#include<stdio.h>
#include<string.h>
#define LENGTH 28

int decrypt(int character, char sub[LENGTH]);

int main(void) {
    char sub[LENGTH];
    fgets(sub, LENGTH, stdin);
    
    char inverse[LENGTH];
    int i = 0;
    int j = sub[i] - 'a';
    while (i < 26) {
        inverse[j] = i + 'a';
        i ++;
        j = sub[i] - 'a';
    }
    
    int character = getchar();
    while (character != EOF) {
        putchar(decrypt(character, inverse));
        character = getchar();
    }
    return 0;
}

int decrypt(int character, char inverse[LENGTH]) {
    if (character >= 'a' && character <= 'z') {
        character = inverse[character - 'a'];
    } else if (character >= 'A' && character <= 'Z') {
        character = inverse[character - 'A'] - ('a' - 'A');
    }
    return character;
}
    
   
