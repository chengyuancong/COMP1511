// Silly example #7
// using pointers to data fields in linked list
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

    int *i_pointer = &(head->data);
    int *sum_pointer = &(head->next->data);

    *i_pointer = 0;
    *sum_pointer = 0;

    while (*i_pointer < 10) {
        *sum_pointer = *sum_pointer + *i_pointer;
        *i_pointer = *i_pointer + 1;
    }

    printf("%d\n", *sum_pointer); // prints 45

    return 0;
}