// simple example of using malloc to create our own array on the heap
// Read n (number of marks to be entered), read marks and print them.

#include <stdio.h>
#include <stdlib.h>

void readMarks(double  marks[], int size);
void printMarks(double  marks[], int size);

int main(int argc, char *argv[]) {

    double * marks;  
   int numMarks;
   
   printf("How many marks are you entering: ");
   scanf("%d",&numMarks);
   
   marks = malloc (numMarks * sizeof(double));
   
   if (marks == NULL){
       fprintf(stderr,"Malloc failed...no more memory\n");
       exit(EXIT_FAILURE);
   }
   
   printf("Please enter your marks: ");
   readMarks(marks,numMarks);

   printf("Your marks are: ");
   printMarks(marks,numMarks);
   
   free(marks);
   return EXIT_SUCCESS;
}

void readMarks(double marks[], int size){
   int i = 0;
   while(i < size){
      scanf("%lf",&marks[i]);
      i++;
   }
}

void printMarks(double marks[], int size){
   int i = 0;
   while(i < size){
      printf("%lf ",marks[i]);
      i++;
   }
   printf("\n");
}