// Demonstrates how to use some of the functions
// from string.h and how we could write them ourselves


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
    //We can use our myStrCopy(str3,str1);
    //Or the string.h funciton
    //strcpy(str3,str1);
    myStrCopy(str3,str1);
    
    printf("%s %s\n",str3,str1);

    printf("%d %d %d\n",myStrlen(str1),myStrlen(str2), myStrlen(str3));
    printf("%d %d %d\n",strlen(str1),strlen(str2), strlen(str3));
    
    //Comparing two strings using == will not work as we would expect. 
    //We should use strcmp instead
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

//"dog" 3 (array size 4)
//Our own version of the strlen function
//       i            
// 0 1 2 3   s
// d o g \0 
int myStrlen(char s[]){
    int i = 0;
    while(s[i] != '\0'){
        i = i + 1;
    }
    return i;
}

//       i            
// 0 1 2 3   src
// d o g \0  

// 0 1 2 3   dest
// d o g \0
//Our own version of the strcpy function
void myStrCopy(char dest[], char src[]){
    int i = 0;
    while(src[i] != '\0'){
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
}
