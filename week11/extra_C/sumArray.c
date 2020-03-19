// Sum array written using a for loop instead of a while
// and also the += and ++ operators to do exactly the same thing
 

#include <stdio.h>

#define MAX 5

int main(int argc, char * argv[]){
                             
    int nums[MAX] = {4,3,1,5,7};
    int sum = 0;
    int i;
    
    //This while loop can be re-written as a for loop
    /*
    i = 0;
    while ( i < MAX ){
        sum = sum + nums[i]; 
        i = i + 1; 
    }
    */
    
    
    for (i=0; i < MAX; i++ ){
        sum += nums[i]; 
    }
    
    printf("The sum is %d\n",sum);
       
    return 0;
}