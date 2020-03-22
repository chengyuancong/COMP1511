// print command line arguments
//YOU NEED argc and argv and not just void to use command
//line arguments
                

//./print_arguments hello 99

// argc = 3
// argv
// 0: "./print_arguments"
// 1: "hello"
// 2: "99" 
#include <stdio.h>
#include <stdlib.h>


        
//For now just think of argv as an array of strings
int main(int argc, char * argv[]) {
    int i;
    printf("argc is %d\n",argc);
    i = 0;
    while ( i < argc ){
        printf("%s\n",argv[i]);
        i = i + 1;   
    }
   
    return 0;
}