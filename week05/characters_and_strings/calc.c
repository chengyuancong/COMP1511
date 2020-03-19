// sum integers supplied as command line arguments

#include <stdio.h>
#include <stdlib.h>

//  0      1  2   3  .....
// ./calc 99 100 -10


// argc: 4
// argv
// 0: "./calc"
// 1: "99"
// 2: "100"
// 3: "-10"

int main(int argc, char * argv[]) {
    int total  = 0;
   
    int i = 1;
    while ( i < argc ){
        total = total + atoi(argv[i]);
        i = i + 1;
    }
   
    printf("Total is %d\n",total);
    return 0;
}