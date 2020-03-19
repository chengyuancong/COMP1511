//Examples of explicity casting from one type to another
//to produce nonsense
 
#include <stdio.h>

int main(void) {
    int i = 1000;
    char c = (char) i;
    int *ip = (int *) i;
    int nums[] = {0};
    printf("%c\n",(char) i);
    printf("%s\n",(char *) &i);
    printf("%s\n",(char *) nums);
    return 0;
}