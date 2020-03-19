//z5285978
#include<stdio.h>

int encrypt(int character, int shift);

int main(void) {
    int shift;
    scanf("%d", &shift);
    if (shift < 0) {
        shift = shift % 26 + 26;
    } else {
        shift = shift % 26;
    } 
    getchar();
    int character = getchar();
    while (character != EOF) {
        putchar(encrypt(character, shift));
        character = getchar();
    }
    return 0;
} 

int encrypt(int character, int shift) {
    if (character >= 'a' && character <= 'z') {
        character = (character - 'a' + shift) % 26 + 'a';
    } else if (character >= 'A' && character <= 'Z') {
        character = (character - 'A' + shift) % 26 + 'A';
    }
    return character;
}
