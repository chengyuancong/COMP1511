// print lines form file after replacing specified pattern
// after replacing specified pattern
// Andrew Taylor - andrewt@cse.unsw.edu.au
// 27/03/19

#include <stdio.h>
#include <string.h>

#define MAX_LINE 1024
#define MAX_REPLACEMENT_LINE 32768

void replace(char string[], char target[], char replacement[], char new_string[], int new_string_len);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <target> <replacement> <files>\n", argv[0]);
        return 1;
    }
    char *target_string = argv[1];
    char *replacement_string = argv[2];

    int argument = 3;
    while (argument < argc) {
        FILE *stream = fopen(argv[argument], "r");
        if (stream == NULL) {
            perror(argv[argument]);
            return 1;
        }

        char line[MAX_LINE];
        while (fgets(line, MAX_LINE, stream) != NULL) {
            char changed_line[MAX_REPLACEMENT_LINE];
            replace(line, target_string, replacement_string, changed_line, MAX_REPLACEMENT_LINE);
            printf("%s", changed_line);
        }

        argument = argument + 1;
    }
    return 0;
}

// copy string to new_string replacing all instances of target with replacement

void replace(char string[], char target[], char replacement[], char new_string[], int new_string_len) {
    int target_length = strlen(target);
    int replacement_length = strlen(replacement);

    int i = 0;
    int j = 0;
    while (string[i] != '\0' && j < new_string_len - 1) {

        // if we have found the target string

        if (strncmp(target, &string[i], target_length) == 0) {

            // instead copy the replacement string to the new array

            strncpy(&new_string[j], replacement, replacement_length);
            i = i + target_length;
            j = j + replacement_length;
        } else {
            new_string[j] = string[i];
            i = i + 1;
            j = j + 1;
        }
    }

    new_string[j] = '\0';
}