// What does this do?
// Uses character constants to get the ASCII codes for the characters,
// store them in array, and print the array. Note we have to track the array length.

// Compare the 8 what?.c programs which are all equivalent
// to get a better understanding of how & why C encodes character sequences


#include <stdio.h>

#define LENGTH 24

int main(void) {
    int asciiCodes[LENGTH];
    int i;

    asciiCodes[0] = 'M';
    asciiCodes[1] = 'y';
    asciiCodes[2] = ' ';
    asciiCodes[3] = 'l';
    asciiCodes[4] = 'e';
    asciiCodes[5] = 'c';
    asciiCodes[6] = 't';
    asciiCodes[7] = 'u';
    asciiCodes[8] = 'r';
    asciiCodes[9] = 'e';
    asciiCodes[10] = 'r';
    asciiCodes[11] = ' ';
    asciiCodes[12] = 'i';
    asciiCodes[13] = 's';
    asciiCodes[14] = ' ';
    asciiCodes[15] = 'a';
    asciiCodes[16] = 'w';
    asciiCodes[17] = 'e';
    asciiCodes[18] = 's';
    asciiCodes[19] = 'o';
    asciiCodes[20] = 'm';
    asciiCodes[21] = 'e';
    asciiCodes[22] = '!';
    asciiCodes[23] = '\n';
    

    i = 0;
    while (i < LENGTH) {
        putchar(asciiCodes[i]);
        i = i + 1;
    }

    return 0;
}