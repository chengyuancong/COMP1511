
// Read in characters until we get to the EOF 
// (press Ctrl ^d on a line of its own) and print out how many
// characters we read in overall, along with how many uppercase, lowercase,
// digits and other characters we read. 
 

#include <stdio.h>
//#include <ctype.h> //if you want to use isupper,islower,isdigit

int main(void) {
   int c; 
   int upper, lower, digits, other, total;
   
   
   
   // print tally
   printf("Characters seen %d :\n ",total);

   // \t is a tab character
   printf("uppercase:\t%d\n lowercase:\t%d\n digits:\t%d\n other:\t\t%d\n",
         upper, lower, digits, other); 

   return 0;
}
