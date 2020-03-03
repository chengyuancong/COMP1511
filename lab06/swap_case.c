//z5285978
#include<stdio.h>

int swap_case(int character);

int main(void){
    int character = getchar();
    while (character != EOF) {
        putchar(swap_case(character));
        character = getchar();
    }
    return 0;
}

int swap_case(int character) {
    if (character >= 'a' && character <= 'z') {
        character = character - ('a' - 'A');
    } else if (character >= 'A' && character <= 'Z') {
        character = character + ('a' - 'A');
    }
    return character;
}
    