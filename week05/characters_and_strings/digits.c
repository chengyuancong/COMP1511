// Demonstrating how to convert a character digit into an integer


// Check through the code below and see if it prints out what you expect.

#include <stdio.h>

// Convert a digit represented in ascii code, to its integer value
int digitToInt(int c);


int main(void){
    int number1 = 0;
    int number2 = 9;
    int digit1 = '0';  
    int digit2 = '9';  
    int result = digit1 + digit2;

    printf("%d + %d = %d\n",digit1,digit2,result);
    printf("%c + %c = %d\n", digit1, digit2, result);

    result = number1 + number2;
    printf("%d + %d = %d\n", number1, number2, result);
    
     
    result = digitToInt(digit1) + digitToInt(digit2);
    printf("%c + %c = %d\n", digit1, digit2, result);
    return 0;
}

// Convert a digit represented in ascii code, to its integer value
// For example if c is '9' (57) we return 9
int digitToInt(int c){
   if ( c >= '0' && c <= '9') {
       return c - '0';
   }
   return c;
}

