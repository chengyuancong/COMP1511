// Create a list by inserting elements at the front.
// Then print the list out.
// Note we are not freeing the memory used in the list as we have not seen how to do that yet
// Try using dcc --leak-check and running to see more details.

// Exercise: Write the length function and test it

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    struct node *next;
    int       data;
};

struct node *createNode(int data, struct node *next);
void printList(struct node *head);
int length(struct node *head) ;

int main(void) {
    //This is always inserting at the front of the list
    //So we will get the list in reversed order!
    struct node *head = createNode(5, NULL);
    head = createNode(42, head);
    head = createNode(17, head);
    head = createNode(13, head);
    printList(head);
    return EXIT_SUCCESS;
}

struct node *createNode(int data, struct node *next){
    struct node *n;

    n = malloc(sizeof (struct node));
    if (n == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(EXIT_FAILURE);
    }
    n->data = data;
    n->next = next;
    return n;
}

void printList(struct node *head){
    struct node *n = head;
    while ( n != NULL ) {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

// return count of nodes in list

int length(struct node *head) {
   return -1; //TODO
}
