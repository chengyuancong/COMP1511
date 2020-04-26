//Example of storing arrays of strings


#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 20
#define  SIZE 10
#define  NUM_WORDS 10
#define LEN 6

//  0  1 2  3  4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
//0 d  o g  \0
//1 c  a t  \0
//2 e  l e  p  h a n t \0

void printAllStrings(char data[][MAX_LENGTH], int size);
int readData(char data[NUM_WORDS][LEN]);

int main(void){
       
    // dog rat tiger
    char names1 [][MAX_LENGTH] = {"dog",
                                  "cat",
                                  "elephant"};
    char names2 [][MAX_LENGTH] = {"dog",
               					  "cat",
               					  "bird",
               					  "fish"};   

    printAllStrings(names1,3);
    printAllStrings(names2,4);
    
    //Modify cat and change it to rat?
    names1[1][0] = 'r';
    printAllStrings(names1,3);

    //Modify elephant and change it to tiger
    // can we do this?
    
    // this is invalid - 
    //names1[2] = "tiger";
    
    strcpy(names1[2] ,"tiger");
    printAllStrings(names1,3);
    
    int num_animals = readData(names1);

    printf("enter an animal to search");
    char search[10];
    fgets(search, 10, stdin);
    
    int j = 0;
    while (j < num_animals) {
    	if (strcmp(search, names1[j] == 0)) {
    		printf("Animal found");
    	}
    }
    
    return 0;
}


int readData(char data[NUM_WORDS][LEN]) {
	int i = 0;
	while ( i < NUM_WORDS && (fgets(data[i], LEN, stdin) != NULL)) {
		i++;
	}
	return i;
}


void printAllStrings(char data[][MAX_LENGTH], int size){
    int i = 0;
    while (i < size){
        printf("%s\n",data[i]);
        i = i + 1;
    }

