// Our first example using arrays


#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main(void){
    int numbers[SIZE];
    int counter;

    printf("Enter %d integers\n",SIZE);

    //Read in array values from user
    counter = 0;
    while (counter < SIZE){
        scanf("%d",&numbers[counter]);
        counter = counter + 1;
    }

    //print out values of the array
    printf("You entered\n");
    counter = 0;
    while (counter < SIZE){
        printf("%d\n",numbers[counter]);
        counter = counter + 1;
    }
    
    return EXIT_SUCCESS; //return 0;
}