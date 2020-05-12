//z5285978
#include<stdio.h>
int main(void){
    int num;
    int sum = 0;
    printf("Enter number: ");
    scanf("%d", &num);
    
    //get factors
    printf("The factors of %d are:\n", num);
    
    int counter = 1;
    while (counter <= num) {
        if (num % counter == 0) {
            printf("%d\n", counter);
            sum = sum + counter;
        }
        counter = counter + 1;
    }
    printf("Sum of factors = %d\n", sum);
    if (sum - num == num) {
        printf("%d is a perfect number\n", num);
    } else {
        printf("%d is not a perfect number\n", num);
    }
    return 0;
}
    
    