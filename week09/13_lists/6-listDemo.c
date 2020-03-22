// Some example list functions and main program that demonstrates how to use them
// You can run with out without the command line argument --ordered to either append new data or insert it in order
// Sample interaction with program:
/*
Enter a number: 1
Enter a number: 2
Enter a number: 3
Enter a number: 4
Enter a number: 5
Enter a number:
List entered was: [1, 2, 3, 4, 5]
First element in list is: 1.
Last element in list is: 5.
Length of list is: 5.
Sum of the list is: 15.
42 is not in the list.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    struct node *next;
    int       data;
};

struct node *createNode(int data, struct node *next);
struct node *last(struct node *head); 
struct node *append(struct node *head, int value);
int sum(struct node *head); 
void printList(struct node *head);
struct node *findNode(struct node *head, int data); 
struct node *insertOrdered(struct node *head,int number) ;
void deleteAll(struct node *head);
void deleteAllWrong(struct node * head);
struct node *insertFront(struct node *head,int number) ;

 
int main(int argc, char *argv[]) {
    struct node *head = NULL;
    int ordered = 0;
    int front = 0;
    if(argc > 1 && strcmp(argv[1],"--ordered") == 0){
         ordered = 1;
    }
    if(argc > 1 && strcmp(argv[1],"--front") == 0){
         front = 1;
    }
    //Infinitely loop until we reach the break statement
    while (1) {
        int number;
        printf("Enter a number: ");
        if (scanf("%d", &number) != 1) {
            break;
        }
        if(ordered){
            head = insertOrdered(head,number);
        } else if (front){
            head = insertFront(head,number);
        } else {
            head =  append(head, number);
        }
    }

    printf("\nList entered was: ");
    printList(head);
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        printf("\nFirst element in list is: %d.\n", head->data);
        printf("Last element in list is: %d.\n", last(head)->data);
    }
    printf("Sum of the list is: %d.\n", sum(head));
    
    if (findNode(head, 42) != NULL) {
        printf("42 is in the list.\n");
    } else {
        printf("42 is not in the list.\n");
    }
    
    //Try running with deleteAllWrong instead of deleteAll
    //deleteAllWrong(head);
    deleteAll(head);
    return EXIT_FAILURE;
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

// return pointer to last node in list
// NULL is returned if list is empty

struct node *last(struct node *head) {
    if (head == NULL) {
        return NULL;
    }

    struct node *n = head;
    while (n->next != NULL) {
        n = n->next;
    }
    return n;
}


// create a new list node containing value
// and append it to end of list

struct node *append(struct node *head, int value) {
    // new node will be last in list, so next field is NULL
    struct node *n =  createNode(value, NULL);
    if (head == NULL) {
        // new node is now  head of the list
        return n;
    } else {
        // change next field of last list node
        // from NULL to new node
        last(head)->next = n;  /* append node to list */
        return head;
    }
}

// return sum of list data fields

int sum(struct node *head) {
    int sum = 0;
    struct node *n = head;
    // execute until end of list
    while (n != NULL) {
        sum += n->data;
        // make n point to next item
        n = n->next;
    }
    return sum;
}

// return sum of list data fields: using for loop

int sum1(struct node *head) {
    int sum = 0;
    for (struct node *n = head; n != NULL; n = n->next) {
        sum += n->data;
    }
    return sum;
}


// print contents of list in the format [1, 2, 3]

void printList(struct node *head) {
    printf("[");
    for (struct node *n = head; n != NULL; n = n->next) {
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
    }
    printf("]");
}

// return pointer to first node with specified data value
// return NULL if no such node

struct node *findNode(struct node *head, int data) {
    struct node *n = head;

    // search until end of list reached
    while (n != NULL) {
        // if matching item found return it
        if (n->data == data) {
            return n;
        }

        // make node point to next item
        n = n->next;
    }

    // item not in list
    return NULL;
}

// previous function written as for loop

struct node *findNode1(struct node *head, int data) {
    for (struct node *n = head; n != NULL; n = n->next) {
        if (n->data == data) {
            return n;
        }
    }
    return NULL;
}

// previous function written as a more concise while loop

struct node *findNode2(struct node *head, int data) {
    struct node *n = head;
    while (n != NULL && n->data != data) {
       n = n->next;
    }
    return n;
}




struct node *insertOrdered(struct node *head, int number) {
   struct node *node =  createNode(number, NULL);
   struct node *previous = NULL;
   struct node *n = head;
   // find correct position
   while (n != NULL && node->data > n->data) {
       previous = n;
       n = n->next;
   }
   
   // link new node into list
   if (previous == NULL) {
       head = node;
   } else {
       previous->next = node;
   }
   node->next = n;
   return head;
}

void deleteAll(struct node * head){
    struct node * tmp;
    while ( head != NULL){
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

//DO NOT USE THIS FUNCTION EXCEPT TO SEE WHAT GOES
//WRONG WHEN YOU DO!
void deleteAllWrong(struct node * head){
    struct node *n = head;

    while (n != NULL) {
        free(n);
        n = n->next;
    }
}