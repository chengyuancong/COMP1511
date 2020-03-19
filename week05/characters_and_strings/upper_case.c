// Read characters until eof, printing them with
// lower case letters convert to upper case
//
// Andrew Taylor - andrewt@unsw.edu.au
// 22/4/2019

#include <stdio.h>

int make_upper_case(int character);

int main(void) {
    // getchar returns an int which will contain either
    // the ASCII code of the character read or EOF

    int character = getchar();
    while (character != EOF) {

        int new_character = make_upper_case(character);
        putchar(new_character);

        character = getchar();
    }
    return 0;
}

// return upper case letter corresponding to lower case letter
// e.g. given 'f' return 'F'
// other characters returned unchanged
//
// library function toupper() in <ctype.h> does this task

int make_upper_case(int character) {
    if (character >= 'a' && character <= 'z') {
        int alphabetPosition = character - 'a';
        return 'A' + alphabetPosition;
    } else {
        return character;
    }
}
