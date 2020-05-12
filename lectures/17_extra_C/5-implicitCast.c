// An example of an implicit cast that is 'bad'
 

#include <stdio.h>
#include <limits.h>
#include <assert.h>

int main(void) {
    int x = INT_MAX;
    char c1 = 100;
    char c2 = INT_MAX; //This cast is bad as it overflows
                       //The compiler gives us a warning
    char c3 = x;       //This cast is bad and is actually
                       //doing the same thing as the line above
                       //but we get no warning
    printf("%d %d %d %d\n",x,c1,c2,c3);
   
    return 0;
}