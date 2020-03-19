// Prints "My lecturer is awesome!\n"
//
// using character constants to get the ASCII codes for the characters,
// and initialize the array to the vales array using , and print the array.
//
// C has a convenient shorthand for char arrays containing a sequence of
// ASCII codes with an extra '\0' value marking the end of the sequence.
// 
//
// A number of C library functions accept null-terminated char arrays
// For example printf with the "%s" specification (below)
//
// Compare the 8 what?.c programs which are all equivalent
// to get a better understanding of how & why C encodes character sequences

#include <stdio.h>

int main(void) {
    char asciiCodes[] = "My lecturer is awesome!\n";
    printf("%s", asciiCodes);
    return 0;
}