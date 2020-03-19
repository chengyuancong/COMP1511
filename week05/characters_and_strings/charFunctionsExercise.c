// Write function myToUpper and check you get the same results as the library toupper function from ctype.h .
// Write the printAlphabet function.

#include <stdio.h>
#include <ctype.h>

// there is an equivalent function in ctype.h called toupper
//Converts a lower case letter to an upper case letter
//leaves other characters unchanged
int myToUpper(int c);

//prints lower case alphabet on a single line
void printAlphabet(void);


int main(void){
    int letter1 = 'z';
    int letter2 = 'A'; 
    int whatever = '?';
    
    printf("%c %c\n",letter1,
                   toupper(letter1)); 
    printf("%c %c\n",letter2,
                   toUpper(letter2));  
    printf("%c %c\n",whatever,
                   toUpper(whatever)); 
    printAlphabet();
    return 0;
}

//Converts a lower case letter to an upper case letter
//leaves other characters unchanged
int myToUpper(int c){
   return -1;
}

//prints lower case alphabet on a single line
void printAlphabet(void){
   
}
