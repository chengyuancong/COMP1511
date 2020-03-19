// Using malloc to create our own array on the heap instead of the stack. 
// This means we can return the array from a function compare to malloc_array_0.c where we did not use malloc
// compare to malloc_array_1.c where we did use malloc but from the main function.
#include <stdio.h>
#include <stdlib.h>

double *  readMarks( int size);
void printMarks(double  marks[], int size);

int main(int argc, char * argv[]){
   double * marks;  
   int numMarks;
   
   printf("How many marks are you entering: ");
   scanf("%d",&numMarks);  
   
   printf("Please enter your marks: ");
   marks = readMarks(numMarks);

   printf("Your marks are: ");
   printMarks(marks,numMarks);
   
   free (marks);
   return EXIT_SUCCESS;
}

double * readMarks ( int size ){
   // We can return a pointer to malloced memory
   double * marks = malloc(sizeof(double)*size);
   
   if (marks == NULL) {
        fprintf(stderr,"Malloc failed...no more memory\n");
        exit(1);
   }
   
   int i = 0;
   while(i < size){
      scanf("%lf",&marks[i]);
      i++;
   }
   return marks;
}

void printMarks(double marks[], int size){
   int i = 0;
   while(i < size){
      printf("%lf ",marks[i]);
      i++;
   }
   printf("\n");
}
