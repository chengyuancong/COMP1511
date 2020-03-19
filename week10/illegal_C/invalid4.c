/*

Run at CSE like this

gcc invalid4.c -o invalid4
./invalid4
authenticated is at address 0xff94bf44
password is at address 0xff94bf3c
Enter your password: 123456789
Welcome. You are authorized.

*/
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int i, ch;
    int authenticated = 0;
    char password[8];

    printf("authenticated is at address %p\n",&authenticated);
    printf("password[8] would be at address %p\n",&password[8]);

    printf("Enter your password: ");
    i = 0;
    ch = getchar();
    while (ch != '\n' && ch != EOF) {
        password[i] = ch;
        ch = getchar();
        i = i + 1;
    }
    password[i] = '\0';

    if (strcmp(password, "secret") == 0) {
        authenticated = 1;
    }

    // a password longer than 8 characters will overflow the array password
    // the variable authenticated is at the address where
    // where password[8] would be and gets overwritten
    //
    // This allows access without knowing the correct password

    if (authenticated) {
        printf("Welcome. You are authorized.\n");
    } else {
        printf("Welcome. You are unauthorized.  Your death will now be implemented.\n");
        printf("Welcome. You will experience a tingling sensation and then death. \n");
        printf("Remain calm while your life is extracted.\n");
    }

    return 0;
}