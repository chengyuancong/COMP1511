//z5285978
#include<stdio.h>
int main(void){
    int num1, num2;
    printf("Please enter two integers:");
    scanf("%d %d", &num1, &num2);
    int result = num1 + num2;
    printf("%d + %d = %d\n", num1, num2, result);
    return 0;
}