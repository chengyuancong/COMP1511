#include <stdio.h>

void message(int n);

int main(void){
    message(5);
    return 0;
}

void message(int n){
    if (n > 0) {
        printf("Good Evening.");
        printf("Good Evening. Are you happy with your phone plan?");
        message(n-1);
    }
}
