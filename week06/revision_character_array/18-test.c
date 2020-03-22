#include <stdio.h>


int main(void) {

	int i = 2;
	i++;
	
	int j = i + 1;
	int k = i++;
	
	printf("%d %d %d\n", i, j,k);
	return 0;
}