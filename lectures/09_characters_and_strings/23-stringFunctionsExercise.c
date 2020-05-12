// Demonstrates how to use some of the functions
// from string.h 

//Write functions myStrlen and myStrCopy that behave in the same way strcpy and strlen behave.


#include <string.h>
#include <stdio.h>



int myStrlen(char s[]);
void myStrCopy(char dest[], char src[]);

int main(void) {
    char str1[] = "hello";
    char str2[] = "goodbye";
  
    char str3[100];//has garbage at this stage
   
    //We can't assign arrays to each other
    //str3 = str1
    strcpy(str3,str1);
        
    printf("%s %s\n",str3,str1);

    printf("%d %d %d\n",strlen(str1),strlen(str2), strlen(str3));
    
    //Comparing two strings using == will not work as we would expect. We should use strcmp instead
    /* if(str3 == str1) {
        printf("They are equal\n");
    } else {
        printf("They are not equal\n");
    } */

    if (strcmp(str3,str1) == 0){ 
        printf("They are equal\n");
    } else {
        printf("They are not equal\n");
    }
    
    strcat(str3,str2);
    printf("%s\n",str3);

    //be careful that your destination is long enough
    //strcat(str1,str2); //This is not a good idea!
    return 0;
}
