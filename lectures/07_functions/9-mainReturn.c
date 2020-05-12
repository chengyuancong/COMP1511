// Read 5 numbers using scanf and print them
// This version shows using return in main
// to end program execution early after an error.
// Try entering in non-numeric data to see it end


#include <stdio.h>
#include <stdlib.h>  //Needed for EXIT_SUCCESS and EXIT_FAILURE

#define N_NUMBERS 5

int main(void) {
    int x, i;

    printf("Enter %d numbers: ", N_NUMBERS);
    i = 0;
    while (i < N_NUMBERS) {
        if(scanf("%d", &x) != 1){
            printf("Invalid\n");
            //This is the same as
            //return -1;
            return EXIT_FAILURE;
        }
        printf("%d\n",x);
        i = i + 1;
    }
    
    printf("Goodbye\n");

    //This is the same as
    //return 0;   
    return EXIT_SUCCESS;
}