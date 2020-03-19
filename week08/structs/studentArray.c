// An example with an array of students
// We demonstrate that passing an array of structs is passing by reference.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

#define MAX_STUDENTS 400

typedef struct student Student;

struct student {
    int zid;
    double wam;
    char name [MAX_LEN];
    char address[MAX_LEN];
};


void printAllDetails(Student students[], int n);
void printStudentDetails(Student s);

int main(void){
  
    Student students[MAX_STUDENTS];
       
    students[0].zid = 1323234;
    students[0].wam =89.5;
    strcpy(students[0].name,"Ronald Mc Donald");
    strcpy(students[0].address,"5 Fake Street");
    
   
    students[1].zid = 321323;
    students[1].wam = 10;
    strcpy(students[1].name,"Jack Russell");
    strcpy(students[1].address,"7 Fake Street");
       
    //printAllDetails(students,400); //No we would be trying to print garbage
    printAllDetails(students,2);
     
    return EXIT_SUCCESS;
}

void printStudentDetails(Student s){
   printf("z%d %.2lf %s %s\n",s.zid,s.wam,s.name,s.address);
}

void printAllDetails2(Student s[], int size){
    printf("\nPrinting all students\n");
    int i =0;
    while (i < size){
        printf("z%d %s %lf %s\n", 
               s[i].zid, s[i].name, s[i].wam,s[i].address);
        i = i + 1;
    }
}

//This function is better than printAllDetails2 as we are using our
//existing printStudentDetails function rather than duplicating code
void printAllDetails(Student students[], int n){
    printf("\nPrinting all students\n");
    int i = 0;
    while ( i < n ){
        printStudentDetails(students[i]);
        i = i + 1;
    }
}

