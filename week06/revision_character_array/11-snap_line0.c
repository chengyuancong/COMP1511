// Reads lines of input until end-of-input
// Print snap! if two consecutive lines are identical
//
// See snap_line1.c for how to use functions
// to produce simpler code
//
// Andrew Taylor - andrewt@unsw.edu.au
// 28/3/19

#include <stdio.h>

#define MAX_LINE 4096

int main(int argc, char *argv[]) {
    char line[MAX_LINE];
    char lastLine[MAX_LINE];

    // read first line into string lastLine
    printf("Enter line: ");
    fgets(lastLine, MAX_LINE, stdin);

    printf("Enter line: ");
    while (fgets(line, MAX_LINE, stdin) != NULL) {
        int i = 0;

        // count how many characters differ
        // between line & lastLine

        int differences = 0;
        while (line[i] != '\0' && lastLine[i] != '\0') {
            if (lastLine[i] != line[i]) {
                differences = differences + 1;
            }
            i = i + 1;
        }

        if (differences == 0) {
            // lines are identical
            printf("Snap!\n");
        }

        // strings can't be assigned so copy elements
        // of lastLine to line using a loop
        int j = 0;
        while (line[j] != '\0') {
            lastLine[j] = line[j];
            j = j + 1;
        }
        lastLine[j] = '\0';

        printf("Enter line: ");
    }

    return 0;
}