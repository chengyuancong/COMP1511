#include <stdio.h>

#define NUM_WORDS 10
//We have made it big enough to store the \n character as well
#define LEN 6

//  0 1 2 3 4 5
//0 b i r d \n \0 
//1 t r e e \n \0 
//2 d u c k \n \0
//3
//4
//etc
//9

//Read in strings into the array till we reach the EOF and return
//the number of strings we read in
int  readData(char data[NUM_WORDS][LEN]);
void printData(char data[NUM_WORDS][LEN], int numWords);

int main(void){
    int numWords = 0;
    //We can only store 10 strings
    //Each string can have a max length of 6
    //That means they can only store 5 characters because we need to store \0
    //If we also store the \n we can only really in 
    //4 characters then the \n then the \0
    char data[NUM_WORDS][LEN];
    
    
    numWords = readData(data);
    printf("I read in %d words\n",numWords);
    
    printf("Printing out the words\n");
    printData(data,numWords);
   
    return 0;
}

//Read in strings into the array till we reach the EOF and return
//the number of strings we read in
int  readData(char data[NUM_WORDS][LEN]){
    int i = 0;
    
    return i;
}

void printData(char data[NUM_WORDS][LEN], int numWords){
    int i = 0;
}