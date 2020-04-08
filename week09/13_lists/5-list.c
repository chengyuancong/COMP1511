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

//Functions we have written
struct node *createNode(int data, struct node *next);
void printList(struct node *head);

//Functions we are going to write

//Return the sum of all the values in the list
int sum(struct node * head);
//return the number of nodes in the list
int length(struct node *head);
//return 1 if it found the item and 0 otherwise
int find(struct node * head, int value);
//print list in format like [1,2,3,6,8]
void printListFancy(struct node * head);

//return the last node in the list
struct node * last(struct node * head);

int main(void) {
    //This is always inserting at the front of the list
    //So we will get the list in reversed order!
    struct node *head = NULL;
    int num;
    while(scanf("%d",&num) == 1){
       head = createNode(num, head);
    }
    printList(head);
    int s = sum(head);
    printf("%d\n",s);
    
    struct node *lastNode = last(head); //NULL
    if( lastNode != NULL){
        printf("%d\n",lastNode->data); //CRASH
    } else {
        printf("The list was empty\n");
    }
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
    struct node *curr = head;
    while ( curr != NULL ) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int sum(struct node * head){
    int sumOfElements = 0;
    struct node * curr = head;
    while ( curr != NULL){
        sumOfElements = sumOfElements + curr->data;
        curr = curr->next;
    }
    return sumOfElements;
}

// return count of nodes in list
int length(struct node *head) {
    int counter = 0;
    struct node * curr = head;
    while ( curr != NULL){
        counter++;
        curr = curr->next;
    }   
    return counter;
}
 
//return 1 if it found the item and 0 otherwise
int find(struct node * head, int value){
    struct node * curr = head;
    while ( curr != NULL){
        if(curr->data == value){
            return 1;
        } 
        curr = curr->next;
    }
    return 0;
}

struct node * last(struct node * head){
    struct node * curr = head;
    if( curr == NULL) {
        return NULL;
    }
    while ( curr->next != NULL){
        curr = curr->next;
    }
    return curr;
}

struct node * addToEnd(struct node * head, int value){
    //Create the node
    struct node * newNode = malloc(sizeof(struct node));
    newNode->data = value;  
    newNode->next = NULL;
   
    struct node * lastNode = last(head);
    if(lastNode == NULL){
        head = newNode;
    } else {
        lastNode->next = newNode;
        return head;
    }
}

//print list in format like [1,2,3,6,8]
void printListFancy(struct node * head){
    printf("["); 
    struct node *curr = head; 
    while (curr != NULL ) {
        printf("%d", curr->data);
        if (curr->next != NULL) {
            printf(", ");
        }
        curr = curr->next; 
    } 
    printf("]");
}
