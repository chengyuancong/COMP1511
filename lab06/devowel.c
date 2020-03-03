//z5285978
#include<stdio.h>

int is_vowel(int character);

int main(void){
    int character = getchar();
    
    while (character != EOF) {
        if (is_vowel(character) == 0) {
            putchar(character);
        }
        character = getchar();
    }
    return 0;
}

int is_vowel(int character) {
    if (character == 'a' || character == 'e' || character == 'i' 
         || character == 'o' || character == 'u' ) {
        return 1;
    } else {
        return 0;
    }
}
    