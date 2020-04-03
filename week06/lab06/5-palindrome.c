//z5285978
#include<stdio.h>
#include<string.h>
#define MAX_LENGTH 4096

int main(void){
    char string[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(string, MAX_LENGTH, stdin);
    int length = strlen(string);
    int i = 0;
    int counter = 0;
    while (i < (length - 1) / 2) {
        if (string[i] == string[length - 2 - i]) {
            counter++;
        }
        i++;
    }
    if (counter == i) {
        printf("String is a palindrome\n");
    } else {
        printf("String is not a palindrome\n");
    }
    return 0;
}