// demonstrating how to write some functions with characters and use
// some of the char functions from ctype.h

#include <stdio.h>
#include <ctype.h>

// there is an equivalent function in ctype.h called toupper
// Converts a lower case letter to an upper case letter
// leaves other characters unchanged
int myToUpper(int c);

//prints lower case alphabet on a single line
void printAlphabet(void);


int main(void){
    int letter1 = 'z';
    int letter2 = 'A'; 
    int whatever = '?';
    
    printf("%c %c\n",letter1,
                   myToUpper(letter1)); 
    printf("%c %c\n",letter2,
                   myToUpper(letter2));  
    printf("%c %c\n",whatever,
                   myToUpper(whatever)); 
    
    printf("%c %c\n",letter1,
                   toupper(letter1)); 
    printf("%c %c\n",letter2,
                   toupper(letter2));  
    printf("%c %c\n",whatever,
                   toupper(whatever)); 

    printAlphabet();
    return 0;
}

//Converts a lower case letter to an upper case letter
//leaves other characters unchanged
int myToUpper(int c){
   int result = c;
   // Could use function from ctype, islower
   // if(islower(c))
   if( c >= 'a' && c <= 'z') {
       result =  c - ('a' - 'A');
   }
   return result;
}

//prints lower case alphabet on a single line
void printAlphabet(void){
   int letter = 'a';
   while ( letter <= 'z'){
       printf("%c",letter);
       letter = letter + 1;
   }
}
