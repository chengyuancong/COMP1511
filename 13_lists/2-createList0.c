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
    b->data = 17;
    struct node * c = malloc(sizeof(struct node));
    c->data = 42;
    struct node * d = malloc(sizeof(struct node));
    d->data = 5;

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = NULL;

    printf("%p %d\n",a,a->data);
    printf("%p %d %p %d\n",b, b->data,a->next,a->next->data);
    printf("%p %d %p %d\n",c, c->data,a->next->next,a->next->next->data);
    printf("%p %d %p %d\n",d, d->data,a->next->next->next,a->next->next->next->data);
    return EXIT_SUCCESS;
}

