/* 
 A program to show integer representation on a 32 bit machine and 
 demonstrate integer overflow
 Author: Aarthi Natarajan
*/
#include <stdio.h>
int main(void) {
	int big, bp1, bp2, bp3;
    // a number of assignment statements executed in the order they are written
    big = 2147483646;
	bp1 = big + 1;
	bp2 = big + 2;
	bp3 = big * 2;
	// Each of the "%d" fields in the printf statement is replaced by the next corresponding value in 
    // the list of variables that follow.
	printf(" big=%d\n bp1=%d\n bp2=%d\n bp3=%d\n", big, bp1, bp2, bp3); 
	return 0;
}