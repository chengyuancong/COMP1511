// An example of the properties of structs
// We can use = to get a copy of a struct
// When we pass a struct into a function we pass a copy
// We can't compare whole structs using == we need to compare the fields
// inside ourselves

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

//1 equal
//0 not
int compareStudents(Student s1, Student s2);

void printStudentDetails(Student s);

int main(void){
    Student s;
    Student s2;
    Student s3;
    s.zid = 1231412;
    s.wam = 89.5;
    strcpy(s.name, "Ronald McDonald");
    strcpy(s.address,"5 Fake Street");

    printStudentDetails(s);  

    // We can use = and get a copy of a struct
    s3 = s;
    
    printStudentDetails(s);
    printStudentDetails(s3);
    
    // We can't use == for structs
    // if ( s == s2){ 
    if ( compareStudents(s,s2) == 1 ){
        printf("s equals s2\n");
    } else {
        printf("NOT THE SAME\n");
    }
 
    if ( compareStudents(s,s3) == 1 ){
        printf("s equals s3\n");
    } else {
        printf("NOT THE SAME\n");
    }
    
    //s3 is a copy of s, so changes to s3 won't affect s
    s3.zid = 6666666;
    s3.wam = 100;
    
    printStudentDetails(s);
    printStudentDetails(s3);
    
    if ( compareStudents(s,s3) == 1 ){
        printf("s equals s2\n");
    } else {
        printf("s does not equal s2\n");
    }
    
    return EXIT_SUCCESS;
}

// structs are passed by copy
void printStudentDetails(Student s){
    printf("z%d %.2lf %s %s\n",s.zid,s.wam,s.name,s.address); 
}

// This function returns 1 if contents of the structs
// are equal and 0 otherwise.
int compareStudents(Student s1, Student s2){
   if(s1.zid == s2.zid && s1.wam == s2.wam && 
      strcmp(s1.name,s2.name) == 0 && 
      strcmp(s1.address,s2.address) == 0){
          return 1;
       } else {
          return 0;  
    }
}
