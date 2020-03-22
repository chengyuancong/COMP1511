// Another simple program which uses a while loop to print
// first 1000 multiples of 13
//
// Andrew Taylor - andrewt@unsw.edu.au
// 25/03/2019
//

#include <stdio.h>

int main(void) {
    int i;
    i = 1;
    while (i <= 1000) {
        printf("%d\n", i*13);
        i = i + 1;
    }
    return 0;
}