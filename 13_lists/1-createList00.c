// Create a list manually
// Then print it out.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    struct node *next;
    int       data;
};


int main(void) {
    struct node * a = malloc(sizeof(struct node));
    a->data = 13;
    struct node * b = malloc(sizeof(struct node));
    b->data  = 99;
    
    a->next = b;
    b->next = NULL;

    printf("%p %d\n",a,a->data);
    printf("%p %d %p %d\n",b, b->data,a->next,a->next->data);
    printf("%p %d\n",b->next,b->next->data);
    
    return EXIT_SUCCESS;
}

