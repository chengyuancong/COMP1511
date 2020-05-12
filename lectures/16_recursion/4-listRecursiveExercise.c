// linked list processing functions from list.c - recursive versions

// Finish implementing the rest of the recursive functions.
// Add some more code to the main to test them if needed



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    struct node *next;
    int       data;
};

struct node *createNode(int data, struct node *next);

int sum(struct node *head);
struct node *findNode(struct node *head, int data);
void printList(struct node *head);
void printListItems(struct node *head);

//Implement these functions.
struct node *last(struct node *head);
struct node *append(struct node *head, int value);
struct node *delete(struct node *head, struct node *node);


int main(int argc, char *argv[]) {
    struct node *head = NULL;
    int howMany, number;
    printf("Enter numbers. Type Ctrl-D to end\n");
    while (scanf("%d",&number) == 1) {
        head = append(head, number);
    }

    if (head == NULL) {
        printf("List is empty.\n");
        return 0;
    }
    printf("\nList entered was: ");
    printList(head);

    printf("\nFirst element in list is: %d.\n", head->data);
    printf("Last element in list is: %d.\n", last(head)->data);
    printf("Sum of the list is: %d.\n", sum(head));
    //ADD CODE TO TEST DELETE
    return EXIT_SUCCESS;
}


// Create a new struct node containing the specified data,
// and next fields, return a pointer to the new struct node.

struct node *createNode(int data, struct node *next) {
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

// return sum of list data fields: using recursive call

int sum(struct node *head) {
    if (head == NULL) {
        return 0;
    }
    return head->data + sum(head->next);
}

// return pointer to first node containing
// specified value, return NULL if no such node

struct node *findNode(struct node *head, int data) {
    if (head == NULL || head->data == data) {
        return head;
    }
    return findNode(head->next, data);
}

// return pointer to last node in list
// NULL is returned if list is empty

struct node *last(struct node *head) {
    //TODO 
    return NULL;
}


// create a new list node containing value
// and append it to end of list

struct node *append(struct node *head, int value) {
    return NULL;
}


// print contents of list

void printList(struct node *head) {
    printf("[");
    
    printListItems(head);
    
    printf("]");
}

void printListItems(struct node *head) {
    if(head != NULL){
        printf("%d", head->data);       
        if (head->next != NULL) {
            printf(", ");            
        }       
        printListItems(head->next);        
    }
}

struct node *delete(struct node *head, struct node *node) {
    return NULL;
}