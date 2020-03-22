#include <stdio.h>
#include <stdlib.h>

void printArgs(char *argv[], int size);
int myatoi(char s[]);

//./args -351 500 60
int main(int argc, char *argv[]) {

	printf("no of args: %d\n", argc);
	int sum = 0;
	for (int i = 1; i < argc; i++) {
		printf("arg %d: %s \n", i, argv[i]);
		sum = sum + atoi(argv[i]);
    }
    printf("sum:%d", sum);
    
    //printArgs(argv, argc);
    
    return 0;
}

int myatoi(char s[]) {
	int num = 0;
	int sign = 1;
	
	int i =0;
	if (s[0] == '-') {
		sign = -1;
	}
	
	i = 1;
	while (s[i] != '\0') {
		int n = s[i] - '0';  // convert letter '3' to 3
		num = num * 10 + n;  // num = 3
		i = i + 1;
    }
    
    return num * sign;
}

		

void printArgs(char *args[],int size) {
    int i, j;
    i = 0;
    while (i < size) {
        j = 0;
        while (args[i][j] != '\0') {
            printf("args[%d][%d] = %c \n", i,j, args[i][j]);
            j = j+1;
        }
        printf("\n");
        i = i + 1;
    }
}