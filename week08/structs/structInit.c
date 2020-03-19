// This is an optional example. You do not need to know this,
// but you can use it if you wish.
// An example of using initialisers for structs

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
void printStudents(Student students[], int n);
int main(void){

    Student s = {1231412,89.5,{16,5,2018},"Ronald McDonald"};
    printStudent(s); 
    int nums[100] = {99};
    Student students[100] = {{1231412,89.5,{16,5,2018},"Ronald McDonald"}};
    printStudents(students,100);
    
    return EXIT_SUCCESS;
}

void printStudents(Student students[], int n){
    int i = 0;
    while ( i < n ){
        printStudent(students[i]);
        i = i + 1;
    }
}

void printDate(Date d){
    printf("%d/%d/%d",d.day,d.month,d.year);
}

void printStudent(Student s){
    printf("z%d %s ",s.zid,s.name);
    printDate(s.dob);
    printf(" %lf\n",s.wam);
}
