// An example of how requesting more and more memory using malloc without freeing it will result in more and more memory being used
// In this example we end up with malloc failing and returning NULL to indicate it was not successful.
// Uncomment out the line with free(p) and the program will run infinitely (type Ctrl^c) to terminate
// Uncomment out both lines with free(p) to see what happens when you free the same memory twice.

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char * argv[]){
   int *p;
   
   //Infinite Loop
   while(1){ 
       p = malloc(10000000 * sizeof(int));
       
       if(p == NULL){
           fprintf(stderr,"Error: memory could not be allocated.\n");
           exit(EXIT_FAILURE);
       }else{  
          printf("Allocated mem at address %p\n", p);
       } 
       //use the memory some how
       //free(p);    
       //free(p); 
   }

   return EXIT_SUCCESS;
}

