//Example of storing arrays of strings


#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 20
#define  SIZE 10


//  0 1 2  3  4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
//0 d o g  \0
//1 c a t  \0
//2 e l e  p  h a n t \0
//3
//4

//  printf("%s",names1[1]);
//    printf("%c",names1[2][3]);
void printAllStrings(char data[][MAX_LENGTH], int size);
int main(void){
    char names1 [][MAX_LENGTH] = {"dog","cat","elephant", "bird","fish"};
    char searchKey [MAX_LENGTH];

    printf("Please type in an animal to search for:");
    if(fgets(searchKey,MAX_LENGTH,stdin) == NULL){
        printf("You did not enter a search key\n");
        return 0;
    }
    //get rid of new line character
    int newLineIndex = strlen(searchKey) - 1;
    if(searchKey[newLineIndex] == '\n'){
        searchKey[newLineIndex]  = '\0';
    }
    
    int i = 0;
    while( i < 5){
        //compare searchKey to names1[i]
        if(strcmp(searchKey,names1[i]) == 0){
             printf("We found %s\n",searchKey);
        }
        i = i + 1;
    }
    
    return 0;
}

void printAllStrings(char data[][MAX_LENGTH], int size){
    int i = 0;
    while ( i < size ){
    	printf("%s\n",data[i]);
    	i = i + 1;
    }
}
