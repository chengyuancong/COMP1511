// Using the code from the previous student exercises, write a program prompts the user 
// to enter how many student details they want to enter,
// reads them in and prints them out again.

// Write and call a function readStudents which should read 'numStudents' students 
// into a malloced array and should return the array

// Assume data for each student is entered in the following format, with one field on each line
// 1231412 
// 89.5 
// Ronald McDonald 
// 5 Fake Street 

// Write and call a function to print the array of students

// Make sure you free any memory used.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

 
int main(int argc, char * argv[]){
     
    int numStudents;
   
    printf("How many students are there?  ");
    scanf("%d",&numStudents);
       
    printf("Please enter your data: \n");
    

    printf("Student details are: \n");
    
    return EXIT_SUCCESS;
}