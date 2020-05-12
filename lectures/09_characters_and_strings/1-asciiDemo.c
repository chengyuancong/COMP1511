// demonstrating how to print a character
// demonstrating the underlying ascii codes and their patterns.
// DO NOT memorise ascii codes. We are only looking at them
// to understand how characters are actually stored.
// ALWAYS use single quotes not raw numbers eg use 'A' NOT 65

// Because there are patterns and orderings in the ascii 
// table we can do maths and do things like 'a' + 1  and get 'b'


#include <stdio.h>


int main(void){

    //This works but is BAD STYLE! ALWAYS USE 'A' etc 
    //Never use ascii codes directly
    printf("%d %c\n", 65, 65);      
    
    printf("%d %c\n",'A','A');
    printf("%d %c\n",'a','a');
    
    printf("%d %c\n",'B','B');
    printf("%d %c\n",'b','b');
    

    printf("%d %c\n",'C','C');
    printf("%d %c\n",'c','c');

    printf("%d %c\n",'0','0');
    printf("%d %c\n",'7','7');    

    //What would this give us?
    printf("%d %c\n",'A' + 25,'A' + 25);
    
    //What would this give us?
    printf("%d %c\n",'b' - ('a' - 'A'),'b' - ('a' - 'A'));
    
    //What would this give us?
    printf("%d %c\n",'Z' + ('a' - 'A'),'Z' + ('a' - 'A'));
    return 0;
}

