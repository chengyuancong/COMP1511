//z5285978
#include<stdio.h>

int main(void) {
    double frequency[26];
    
    int i = 0;    
    while (i < 26) {
        frequency[i] = 0;
        i++;
    }
    
    int counter = 0;
    int character = getchar();
    while (character != EOF) {
        if (character >= 'A' && character <= 'Z') {
            character = character + ('a' - 'A');
            frequency[character - 'a']++;
            counter++;
        } else if (character >= 'a' && character <= 'z') {
            frequency[character - 'a']++;
            counter++;
        }
        character = getchar();
    }
    
    i = 0;
    while (i < 26) {
        printf("'%c' %.6lf %.0lf\n", i + 'a', frequency[i] / counter, frequency[i]);
        i++;
    }
    return 0;
}