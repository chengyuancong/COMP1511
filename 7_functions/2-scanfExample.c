// Simple example of using scanf return value
// Try these inputs
// 1 2 3
// chicken 
// 1 2 chicken
// 1 2 3chicken
// Try just typing Ctrl+D on a line on its own.
// Try typing
// 2 3
// And then Ctrl+D on a line of its own.

#include <stdio.h>
int main(void) {
    int itemsRead;
    int x,y,z;
      
    itemsRead = scanf("%d %d %d",&x,&y,&z);
    
    printf("I read in %d items: %d %d %d\n",itemsRead,x,y,z);
   
    return 0;
}