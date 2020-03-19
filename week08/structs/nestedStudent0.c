// A simple example of a defining nested struct
// Each student has a field called dob (date of birth), which is also a struct of type Date



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct date Date;

struct date {
    int day;
    int month;
    int year;
};

typedef struct student Student;

struct student {
    int zid;
    double wam;
    Date dob;
    char name [MAX_LEN];
    
};

void printStudent(Student s);

int main(void){

    Student s;
    s.zid = 1231412;
    s.wam = 89.5;
    //the dob field is inside the student, s 
    //and the day field is inside the dob field
    s.dob.day = 8;
    s.dob.month = 5;
    s.dob.year = 2017;
    strcpy(s.name, "Ronald McDonald");   
        
    printStudent(s);
    
    return EXIT_SUCCESS;
}

void printStudent(Student s){
    printf("z%d %s %d/%d/%d %lf\n",s.zid,s.name,s.dob.day,
                                   s.dob.month,s.dob.year, s.wam);
}