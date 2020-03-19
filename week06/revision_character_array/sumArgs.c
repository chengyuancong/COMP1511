#include <stdio.h>
#include <stdlib.h>

int sumArgs(char *argv[], int size);

int main(int argc, char *argv[]) {
    int sum;
    sum = sumArgs(argv,argc);
    printf("sum is %d:\n",sum);
    return 0;
}

int sumArgs(char *args[],int size) {
    int i = 1;
    int sum = 0;
    while (i < size) {
        sum = sum + atoi(args[i]);
        i = i + 1;
    }
    return sum;
}
