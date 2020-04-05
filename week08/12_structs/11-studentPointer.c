//Take your code from the studentExercise and:

// Create a pointer variable that points to the first student
// print the first student and print the first student again by dereferencing your pointer.
// Modify the first student's wam to be 100, by dereferencing your pointer.
// print the first student and print the first student again by dereferencing your pointer again.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct student Student;

void printStudentDetails(Student s);

struct student {
    int zid;
    double wam;
    char name [MAX_LEN];
    char address[MAX_LEN];
};

int main(void){   
    Student s;
    s.zid = 1323234;
    s.wam = 89.5;
    strcpy(s.name ,"Ronald Mc Donald");
    strcpy(s.address,"5 Fake Street");
   
    Student * sp;
    sp = &s;
    
    printStudentDetails(s);
    printStudentDetails(*sp);
    
    sp->wam = 100;
    
    printStudentDetails(s);
    printStudentDetails(*sp);
    
    return EXIT_SUCCESS;
}

//Move the print to a function
void printStudentDetails(Student s) {
    printf("z%d %s %lf %s\n",s.zid,s.name, s.wam,s.address);
}
