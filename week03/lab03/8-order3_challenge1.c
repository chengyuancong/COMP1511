//z5285978
#include<stdio.h>
int main(void){
    int num1, num2, num3;
    
    printf("Enter integer: ");
    scanf("%d", &num1);
    
    printf("Enter integer: ");
    scanf("%d", &num2);
    
    printf("Enter integer: ");
    scanf("%d", &num3);
    
    int max = (num1 >= num2 && num1 >= num3) * num1 
              + (num2 > num1 && num2 >= num3) * num2 
              + (num3 > num1 && num3 > num2) * num3;
    int min = (num1 <= num2 && num1 <= num3) * num1 
              + (num2 < num1 && num2 <= num3) * num2 
              + (num3 < num1 && num3 < num2) * num3;
    int med = num1 + num2 + num3 - max - min;
    
    printf("The integers in order are: %d %d %d\n", min, med, max);
    
    return 0;
}