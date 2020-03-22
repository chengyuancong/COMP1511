// Read characters until EOF (Ctrl+d)


#include <stdio.h>

int main(void) {
    int ch;

    // getchar returns an int which will contain either
    // the ASCII code of the character read or EOF

    ch = getchar();
    while (ch != EOF) {
        printf("you entered the character: '%c'\n", ch);
        ch = getchar();
    }
    return 0;
}