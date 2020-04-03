#include <stdio.h>
#include <string.h>
#define MAX_LINE 4096

char *my_fgets(char array[], int arraySize);

int main(int argc, char*argv[]) {
    
    char line[MAX_LINE];
    printf("Enter line:");
    
    if (my_fgets(line, MAX_LINE) != NULL) {
        printf("line: %s", line);
    }
         

    return 0;
}

char *my_fgets(char array[], int arraySize) {

    int i = 0;
    while (i < arraySize -1) {
        int ch = getchar();
        
        if (ch == EOF) {
            // signals end of input
            if (i == 0) {
                // means no characters have been read.
                return NULL;
            } else {
                array[i] = '\0';
                return array;
            }
        }
            
        array[i] = ch;
        if (ch == '\n') {
            array[i + 1] = '\0';
            return array;
        }
    }
    array[i] = '\0';
    return array;        
            
}