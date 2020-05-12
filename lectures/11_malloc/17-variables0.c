// Used to demonstrate and remind about the function call stack

#include <stdio.h>
#include <stdlib.h>

#define MAXITEMS 4

void fun1(int x);
void fun2(double x, double y);
int fun3(int z);

int main(int argc, char * argv[]) {   
    int var = 5;
    char s[] = "Hello";
    int array[MAXITEMS] = {1,9,1,7};
   
    printf("%d %s %d\n",var,s,array[0]);
    fun1(var);    
    fun2(42,2);
    printf("%d",fun3(10));
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

