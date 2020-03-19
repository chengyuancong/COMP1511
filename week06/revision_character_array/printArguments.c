// COMMAND-LINE ARGUMENTS
// 
// YOU NEED argc and argv and not just void to use command line arguments
                

//./printArguments hello 99

// argc = 3
// argv
// 0: "./printArguments"
// 1: "hello"
// 2: "99" 
#include <stdio.h>
#include <stdlib.h>

//./calculate 3 4 5 1
        
//For now just think of argv as an array of strings
int main(int argc, char * argv[]) {
    int sum = 0;
    int i;
    printf("argc is %d\n",argc);
    i = 1;
    while ( i < argc ){
        sum = sum + atoi(argv[i]);
        i = i + 1;   
    }
    printf("sum %d\n",sum);
    return 0;
}