#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define LENGTH 4096


int main(void) {
    // why is the return type of getchar() an int, and not char?
    // getchar() can return a positive value between 0..127 or -1,
    // hence return type is an int
    // int c = getchar();

    
    // four ways to convert a string containing digits to number

    // Version 1: String to int using getchar
    printf("enter a number:");
    int c = getchar();
    int digitValue = 0; 
    // while ( c >= '0' && c <= '9')
    while (isdigit(c)) {
        digitValue = 10 * digitValue + (c - '0');
        
        printf("read %d and value: %d\n",c-'0',digitValue);
        c = getchar();
    }
    printf("v1: You entered %d\n", digitValue);
    
    
    // Version 2: String to int using fgets
    char line[LENGTH] = {0};
    printf("enter a number:");
    fgets(line,LENGTH,stdin);
    int i = 0;
    digitValue = 0;
    while (isdigit(line[i])) {
        digitValue = 10 * digitValue + (line[i] - '0');
        i=i+1;        
    }
    printf("v2: You entered %d\n", digitValue);
    
    // Version 3: String to int using atoi in stdlib.h
    printf("enter a number:");
    fgets(line,LENGTH,stdin);
    digitValue = atoi(line);
    
    printf("v3: You entered %d", digitValue);
    //fputs(line,stdout);  // this is the same as printf
    
    
    
    // Version 4: String to int using scanf
    int no;
    printf("enter a number:");
    scanf("%d",&no);
    printf("v4: You entered %d\n",no);
    

    // An example to show, what happens the last character is not a null character.
    char str1[10] = "hello";
    str1[0] = 'h';
    str1[1] = 'i';
    // str1[2]= '\0'; //try running this last example without '\0' first
    
    // dcc and run - stack overflow
    // dcc --valgrind -o  and run : 
    printf("%s",str1);
    
    return 0;
}

