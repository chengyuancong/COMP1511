// What does this do?
//
// Uses character constants to get the ASCII codes for the characters,
// initialize an array to the values , and print the array.
// Note we still have to track the array length.
//
// Compare the 8 what?.c programs which are all equivalent
// to get a better understanding of how & why C encodes character sequences


#include <stdio.h>

#define LENGTH 24

int main(void) {
    // if we don't specify the size of an array being initialized C will make
    // it big enough to hold all the initializing elements (24 in this case)
    int asciiCodes[] = {'M','y',' ','l','e','c','t','u','r','e','r',' ',
                        'i','s', ' ', 'a','w','e','s','o','m','e','!','\n'};
    int i;

    i = 0;
    while (i < LENGTH) {
        putchar(asciiCodes[i]);
        i = i + 1;
    }

    return 0;
}