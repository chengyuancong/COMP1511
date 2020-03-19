//Revision Exercise: Letter Frequency
//Write a function to work out how many times a specified character occurs in a string.

//Your function should take two parameters: the string, and the character to search for.

//Your function should return a single integer: the number of times the specified character appears.

//Your function must have this prototype:

//int letterFrequency(char *string, char charToFind);

//For example, if the character to find was o, and the string was: "Hello, world!"

//Your function should return 2, as the letter o occurs twice in the string at the end of 'Hello', and 'o' in world).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH  20
int letterFrequency(char *string, char charToFind);
int main(int argc, char * argv[]) {
    
    char * charToFind = argv[1];
    char  str[MAX_LENGTH] = {0};
    fgets(str,MAX_LENGTH,stdin);
    int f = letterFrequency(str,*charToFind);
    printf("%c occurs %d times",*charToFind,f);
    return 0;
}

int letterFrequency(char *string, char charToFind) {

    int frequency = 0;
    int length = strlen(string);
    int i = 0;
    while (i < length) {
        if (string[i] == charToFind) {
           frequency++;
        }
        i++;
    }
    return frequency;
}
