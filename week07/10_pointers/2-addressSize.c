// Addresses of variables are stored in 4 bytes on a 32 bit system and 8 bytes on a 64 bit system.
// Since the cse machines are being upgraded from a 32 bit system to a 64 bit system at 1pm on 14/02/2019
// ,we would expect sizeof(&x) and sizeof(&c) to change from 4 to 8 bytes.

#include <stdio.h>

//4 bytes allows addresses in the range of
//0..2^32-1

//8 bytes allows addresses in the range of 
//0..2^64-1

int main(void) {
    int x = 10;
    char c = 'a';
                                //On 14/02/2019 at 11:50 this was 4
                                //Now it is 8
    printf("%lu %lu\n",sizeof x, sizeof &x);
                                //On 14/02/2019 at 11:50 this was 4
                                //Now it is 8
    printf("%lu %lu\n",sizeof c, sizeof &c);
    
    //Size of long has also changed from 4 to 8!
    printf("%lu %lu\n",sizeof(long), sizeof(long long));
    
    return 0;
}