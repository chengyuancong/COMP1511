// A simple example of a defining nested struct
// Each student has a field called dob, which is also a struct of type Date
// In this version we have created some functions to read in data and have
// broken down our printStudent function to use a printDate function.


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


void printDate(Date d);
void printStudent(Student s);
int readDate(Date * d);
int readStudent(Student *s);

int main(void){

    Student s;
    if(readStudent(&s)){        
        printStudent(s);
    }
    return EXIT_SUCCESS;
}


//Returns 1 if it successfully read in a date and 0 otherwise
int readDate(Date * d){
    if( scanf("%d %d %d",&d->day,&d->month,&d->year) == 3){
        return 1; 
    } else {
        return 0; 
    }    
}

//Returns 1 if it successfully read in a student and 0 otherwise
int readStudent(Student *s){    
    if((scanf("%d %lf",&s->zid,&s->wam) == 2) && (readDate(&s->dob) != 0) &&
       fgets(s->name,MAX_LEN,stdin) != NULL){
         //Remove trailing new line character
         int lenName = strlen(s->name);
         s->name[lenName -1] = '\0';
         return 1;
    }  
    return 0;
}


void printDate(Date d){
    printf("%d/%d/%d",d.day,d.month,d.year);
}

void printStudent(Student s){
    printf("z%d %s ",s.zid,s.name);
    printDate(s.dob);
    printf(" %lf\n",s.wam);
}

