/* A simple program to add two numbers
 By: Aarthi Natarajan
 Created: 16/05/2019
*/
#include <stdio.h>
int main(void) {
	int sum;
	int firstNum, secondNum;

	printf("Enter the first no:");
	scanf("%d",&firstNum);
	printf("Enter the second no:");
	scanf("%d",&secondNum);
	
	sum = firstNum + secondNum;
	printf("Sum of the numbers is %d \n", sum);
    return 0;
}
