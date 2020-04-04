// This is building on the code from variables0.c
// Used to demonstrate the difference between the stack (local variables) 
// and the heap (malloced chunks of memory).
// Try compiling with
// dcc --leak-check -o variables variables.c
// and notice the difference when you comment out line 32 compared to when
// you keep line 32.

#include <stdio.h>
#include <stdlib.h>

#define MAXITEMS 4

void fun1(int x);
void fun2(double x, double y);
int fun3(int z);
int * fun4(void);
int * fun5(void);

int main(int argc, char * argv[]) {   
    int var = 5;
    char s[] = "Hello";
    int array[MAXITEMS] = {1,9,1,7};
    int * array2;
   
    printf("%d %s %d\n",var,s,array[0]);

    fun1(var);    
    fun2(45,2);
    printf("%d",fun3(10));
 
    //array2 = fun4(); //BAD 

    array2 = fun5();   //GOOD
    printf("%d %d %d\n",array2[0],array2[1],array2[2]);
    free(array2); //TRY REMOVING THIS LINE AND RUNNING WITH --leak-check
    return 0;
}


void fun1(int x){
    int y = 9;
    int z = x*y;
    fun2(z,2);         
    printf("%d\n",z);   
}

void fun2(double x, double y){
    double z = x/y;
    printf("%lf\n",z);
}

int fun3(int z){
     int arr[] = {1,2,3};
     int result = z - arr[0] + arr[1] - arr[2];
     return result;
}

/*
//You should never return the address of a local variable!
int * fun4(void){
    int result[] = {9,10,11};
    return result;
}
*/

//You can return the address of a chunk of malloced memory!
int * fun5(void){
    int * result = malloc(sizeof(int) * 3);
    result[0] = 9;
    result[1] = 10;
    result[2] = 11;
    return result;
}


