// This program prompts the user to enter how many student details they want to enter,
// reads them in and prints them out again.
// It uses malloc to create an array on the heap
// instead of the stack. This means we can return the array
// from a function

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct student Student;
struct student {
    int zid;
    double wam;
    char name[MAX_LEN];
    char address[MAX_LEN];
};

Student *  readStudents(int size);
void printStudents(Student * students, int size);
void removeTrailingNewLine(char s[]);

int main(int argc, char * argv[]){
    Student * students;  
    int numStudents;
   
    printf("How many students are there?  ");
    scanf("%d",&numStudents);
       
    printf("Please enter your data: \n");
    students = readStudents(numStudents);

    printf("Student details are: \n");
    printStudents(students,numStudents);
   
    free(students);
    return EXIT_SUCCESS;
}

Student * readStudents ( int size ){

   Student * students = malloc(sizeof(struct student)*size);
   
   if (students == NULL) {
        fprintf(stderr,"Malloc failed...no more memory\n");
        exit(EXIT_FAILURE);
   }
   int i = 0;
   while(i < size){
      printf("Student %d:\n",i);
      scanf("%d",&(students[i].zid));
      scanf("%lf",&(students[i].wam));
      getchar(); //get rid of extra newline character
      fgets(students[i].name,MAX_LEN,stdin);
      fgets(students[i].address,MAX_LEN,stdin);
      removeTrailingNewLine(students[i].name);
      removeTrailingNewLine(students[i].address);
      i++;
   }
   
   return students;
}

void printStudents(Student * students, int size){
   int i = 0;
   while(i < size){
      printf("%d %lf %s %s\n",students[i].zid,students[i].wam, students[i].name,students[i].address);
      i++;
   }
   printf("\n");
}

void removeTrailingNewLine(char s[]){
    int len = strlen(s);
    if( len > 0 && s[len-1] =='\n'){
         s[len-1] = '\0';
    }
}
