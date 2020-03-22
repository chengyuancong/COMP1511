// Revision
// Demonstrates how to use some of the functions from string.h 
// Write functions myStrlen, myStrcat and myStrCopy that behave in the same way strcpy, strcat and strlen behave.


#include <string.h>
#include <stdio.h>

long myStrlen(char s[]);
void myStrcat(char str1[], char str2[], int n);
void myStrCopy(char dest[], char src[]);

int main(void) {
    char str0[] = "";
    char str1[] = "hello";  //size 6
    char str2[] = "goodbye"; 
  
    char str3[100] = "hi";
   
    //We can't assign arrays to each other
    //str3 = str1
    //printf("str1: %s , str3: %s\n", str1, str3);
    //myStrCopy(str3,str1);
    //printf("copy:%s \nsrc:%s\n",str3,str1);

    //printf("%ld %ld %ld %ld\n",strlen(str1),strlen(str2), strlen(str3), strlen(str0));
    //printf("\n");
    //printf("%ld %ld %ld %ld\n",myStrlen(str1),myStrlen(str2), myStrlen(str3),myStrlen(str0));
    
    //printf("\n");
    printf("str2: %s, str3: %s\n", str2, str3);
    myStrcat(str3,str2,strlen(str2));
    printf("str3: %s\n",str3);

    //be careful that your destination is long enough
    //strcat(str1,str2); //This is not a good idea!
    //printf("%s\n",str1);
    
    
    //Comparing two strings using == will not work as we would expect. We should use strcmp instead
    //if(str3 == str1){
    //    printf("They are equal\n");
    //} else {
    //    printf("They are not equal\n");
    //}

    if (strcmp(str3,str1) == 0){ 
       printf("They are equal\n");
    } else {
        printf("They are not equal\n");
    }
    
    
    return 0;
}

long myStrlen(char s[]){
    long i = 0;
    
    while (s[i] != '\0') {
    	i++;
    }
    return i;
}

/* strncat appends str2 to str1, over writing the terminating null char ('\0') at the end of str1, and then adds a terminating null byte char. strncat will use at most n bytes from str2.
*/
// str1 = good str2 bye
// strcat(str1, str2)  ->  str1 = "goodbye"

void myStrcat(char str1[], char str2[], int n) {

    // find the end of the first string
    // str1 = "hello";
    int i = 0;
    while (str1[i] != '\0') {
    	i++;
    }
    
    int j = 0;
    printf("i,j is now: %d, %d", i,j);
    
    while (i < n && str2[j] != '\0') {
    	str1[i] = str2[j];
    	i++;
    	j++;
    }
    printf("i,j is now: %d, %d", i,j);
    str1[i] = '\0';
}

// str1 = good str2 bye
// strcopy(str1, str2)  ->  str1 = "bye"

void myStrCopy(char dest[], char src[]){
    long i = 0;
    while (src[i] != '\0'){
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
}
