//z5285978
#include<stdio.h>
#include<string.h>
#define MAX_LENGTH 4096
int simplify(char source[MAX_LENGTH], char dest[MAX_LENGTH], int length);

int main(void){
    char source[MAX_LENGTH];
    char dest[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(source, MAX_LENGTH, stdin);
    int length = simplify(source, dest, strlen(source)) + 1;
    int i = 0;
    int counter = 0;
    while (i < (length - 1) / 2) {
        if (dest[i] == dest[length - 2 - i]) {
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
              
int simplify(char source[MAX_LENGTH], char dest[MAX_LENGTH], int length) {
    int i = 0;
    int j = 0;
    while (i < length) {
        if (source[i] >= 'a' && source[i] <= 'z') {
            dest[j] = source[i];
            i++;
            j++;
        } else if (source[i] >= 'A' && source[i] <= 'Z') {
            dest[j] = source[i] + ('a' - 'A');
            i++;
            j++;
        } else {
            i++;
        }
    }
    dest[j] = '\0';
    return j;
}
            