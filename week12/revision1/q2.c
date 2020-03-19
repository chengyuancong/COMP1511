
#include <stdio.h>


//Many people wrote 4 for the sizeof s??
int main(void) {
    char s[] = "potato";
    printf("%c%d\n",s[2],sizeof(s));

    return 0;
}