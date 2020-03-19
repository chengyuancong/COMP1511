// Read characters until EOF (Ctrl + d)

#include <stdio.h>

int main(void) {
    int ch;

    // getchar returns an int which will contain either
    // the ASCII code of the character read or EOF

    // using an assignment in a loop/if condition is
    // not recommended for noviceprogrammers
    // but is used widely by experienced C programmers

    while ((ch = getchar()) != EOF) {
        printf("you entered the character: '%c'\n", ch);
    }
    return 0;
}