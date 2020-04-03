//z5285978
#include<stdio.h>
#include<string.h>
#define MAX_LENGTH 4096
int simplify(char string1[MAX_LENGTH], char string2[MAX_LENGTH], int length);

int main(void){
    char string1[MAX_LENGTH];
    char string2[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(string1, MAX_LENGTH, stdin);
    int letters = simplify(string1, string2, strlen(string1)) + 1;
    int i = 0;
    int counter = 0;
    while (i < (letters - 1) / 2) {
        if (string2[i] == string2[letters - 2 - i]) {
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
              
int simplify(char string1[MAX_LENGTH], char string2[MAX_LENGTH], int length) {
    int i = 0;
    int j = 0;
    while (i < length) {
        if (string1[i] >= 'a' && string1[i] <= 'z') {
            string2[j] = string1[i];
            i++;
            j++;
        } else if (string1[i] >= 'A' && string1[i] <= 'Z') {
            string2[j] = string1[i] + ('a' - 'A');
            i++;
            j++;
        } else {
            i++;
        }
    }
    string2[j] = '\0';
    return j;
}
            