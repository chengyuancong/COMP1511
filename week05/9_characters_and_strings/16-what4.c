// What does this do?
//
//  using character constants to get the ASCII codes for the characters,
// and initialize the array to the vales array using , and print the array.
//
// This version has a extra special value in the array ('\0') to indicate the //
// end of the sequence.  This means we no longer have to keep track of how
// many characters in the array (note the while loop condition)
//
// Compare the 8 what?.c programs which are all equivalent
// to get a better understanding of how & why C encodes character sequences


#include <stdio.h>

int main(void) {
    // if we don't specify the size of an array being initialized C will make
    // it big enough to hold all the initializing elements 
    int asciiCodes[] = {'M','y',' ','l','e','c','t','u','r','e','r',' ',
                        'i','s', ' ','a','w','e','s','o','m','e','!','\n','\0'};
    int i;

    i = 0;
    while (asciiCodes[i] != '\0') {
        putchar(asciiCodes[i]);
        i = i + 1;
    }

    return 0;
}