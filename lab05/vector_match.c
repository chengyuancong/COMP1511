//z5285978
#include<stdio.h>
#define SIZE 10

int match(int array1[SIZE], int array2[SIZE]);

int main(void){
    
    int i, array1[SIZE], array2[SIZE];
    
    printf("Enter vector 1 of 10 positive numbers: ");
    for(i = 0; i < SIZE; i++) {
        scanf("%d", &array1[i]);
    }
    
    printf("Enter vector 2 of 10 positive numbers: ");
    for(i = 0; i < SIZE; i++) {
        scanf("%d", &array2[i]);
    }
    
    int num = match(array1, array2);
    printf("Vectors match in %d positions.\n", num);
    return 0;
}

int match(int array1[SIZE], int array2[SIZE]) {
    int num = 0;
    for (int i = 0; i < SIZE; i ++) {
        if (array1[i] == array2[i]) {
            num ++;
        }
    }
    return num;
}