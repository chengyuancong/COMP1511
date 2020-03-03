//z5285978
#include<stdio.h>
#include<string.h>
#define MAX_LENGTH 4096
int simplify(char string[MAX_LENGTH], int length);

int main(void){
    char string[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(string, MAX_LENGTH, stdin);
    int length = strlen(string);
    int letters = simplify(string, length) + 1;
    int i = 0;
    int counter = 0;
    while (i < (letters - 1) / 2) {
        if (string[i] == string[letters - 2 - i]) {
            counter ++;
        }
        i ++;
    }
    if (counter == i) {
        printf("String is a palindrome\n");
    } else {
        printf("String is not a palindrome\n");
    }
    return 0;
}
              
int simplify(char string[MAX_LENGTH], int length) {
    int i = 0;
    int j = 0;
    while (i < length) {
        if (string[i] >= 'a' && string[i] <= 'z') {
            string[j] = string[i];
            i ++;
            j ++;
        } else if (string[i] >= 'A' && string[i] <= 'Z') {
            string[j] = string[i] + 'a' - 'A';
            i ++;
            j ++;
        } else {
            i ++;
        }
    }
    return j;
}
            