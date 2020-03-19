// A simple example of a defining a struct,
// initialising it with data and passing it into a function
// This time we have defined a typedef so we can use Student
// instead of having to type struct student everywhere
// Compare to studentDemo0.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct student Student;

struct student {
    int zid;
    double wam;
    char name [MAX_LEN];
    char address[MAX_LEN];
};

void printStudentDetails(Student s);

int main(void){
    Student s;
    Student s2;
    s.zid = 1231412;
    s.wam = 89.5;
    strcpy(s.name, "Ronald McDonald");
    strcpy(s.address,"5 Fake Street");

    s2.zid = 321323;
    s2.wam = 10;
    strcpy(s2.name,"Jack Russell");
    strcpy(s2.address,"7 Fake Street");
    
    printStudentDetails(s);  
    printStudentDetails(s2);
           
    return EXIT_SUCCESS;
}

//Move the print to a function
void printStudentDetails(Student s){
    printf("z%d %s %lf %s\n",s.zid,s.name, s.wam,s.address);
}
