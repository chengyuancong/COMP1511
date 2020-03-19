// Generates ascending ordered test data

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SIZE 100

int main(int argc, char * argv[]){
    int size = DEFAULT_SIZE;
    if (argc > 1 ){
        size = atoi(argv[1]);
          
    }
    int i = 0;
    while(i < size){
         printf("%d\n",i);
         i++;
    }
    return 0;
}