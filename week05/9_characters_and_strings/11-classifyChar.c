// Revision Exercise:
// Read in characters until we get to the EOF 
// (press Ctrl ^d on a line of its own) and print out how many
// characters we read in overall, along with how many uppercase, lowercase,
// digits and other characters we read. 

#include <stdio.h>
//#include <ctype.h> //if you want to use isupper,islower,isdigit

int main(void) {
   int c; 
   int upper, lower, digits, other, total;
   
   total = 0;   
   upper = 0;
   lower = 0;
   digits = 0;
   other = 0;

   c = getchar();
   while ( c != EOF ){
      total = total + 1;
      if ( c >= 'A' && c <= 'Z'){ //could use isupper(c)
          upper = upper + 1;
      } else if( c >= 'a' && c <= 'z'){ //could use islower(c)
          lower = lower + 1;
      } else if ( c >= '0' && c <= '9'){ //could use isdigit(c)
           digits = digits + 1;
      } else {
           other = other + 1;
      }
      c = getchar();
   }
   
   // print tally
   printf("Characters seen %d :\n ",total);
   printf("uppercase:\t%d\n lowercase:\t%d\n digits:\t%d\n other:\t\t%d\n",
         upper, lower, digits, other); 

   return 0;
}
