// Silly example
// #6 using data fields of linked list
// Andrew Taylor - andrewt@unsw.edu.au
// 27/3/2019

#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int          data;
};

int main(void) {
    struct node *head =  malloc(sizeof (struct node));
    head->next =  malloc(sizeof (struct node));

    (head->data) = 0;
    (head->next->data) = 0;

    while ((head->data) < 10) {
        (head->next->data) = (head->next->data) + (head->data);
        (head->data) = (head->data) + 1;
    }

    printf("%d\n", (head->next->data)); // prints 45

    return 0;
}