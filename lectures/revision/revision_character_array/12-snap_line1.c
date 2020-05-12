#include <stdio.h>

#define MAX_LINE 4096

int compareStrings(char string1[], char string2[]);
void copyString(char destinationString[], char sourceString[]);


int main(int argc, char *argv[]) {
    char line[MAX_LINE];
    char lastLine[MAX_LINE];

    // read first line into string lastLine
    printf("Enter line: ");
    fgets(lastLine, MAX_LINE, stdin);

    printf("Enter line: ");
    while (fgets(line, MAX_LINE, stdin) != NULL) {
        if (compareStrings(line, lastLine) == 0) {
            printf("Snap!");
        }
        copyString(lastLine,line);
        
        printf("Enter line: ");
    }

    return 0;
}

// return 1 if string1 & string2 differ in any element, 0 otherwise
// strcmp from  <string.h> performs similar function

int compareStrings(char string1[], char string2[]) {
    int i = 0;
    
    while (string1[i] != '\0') {
        if (string1[i] != string2[i]) {
            return 1;
        }
        i = i + 1;
    }
    // line 1: hello
    // line 2: hello there
    
    if (string2[i] != '\0') {
        return 1;
    } else {
        return 0;
    }
    
}



// copy elements in sourceString to destinationString
// destinationString must be large enough to hold string
// strcpy from  <string.h> performs the same function

void copyString(char destinationString[], char sourceString[]) {
    int i = 0;
    while (sourceString[i] != '\0') {
        destinationString[i] = sourceString[i];
        i = i + 1;
    }
    destinationString[i] = '\0';   
}