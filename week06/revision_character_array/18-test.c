#include <stdio.h>


int main(void) {

	int i = 2;
	i++; // i = 3
	
	int j = i + 1; // j = 4
	int k = i++; // k = i = i + 1 -> k = i then i = i + 1
	
	printf("%d %d %d\n", i, j, k);
	return 0;
}