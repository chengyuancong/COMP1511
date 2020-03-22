// Create a list by inserting elements at the front.
// Then print the list out.
// Note we are not freeing the memory used in the list as we have not seen how to do that yet
// Try using dcc --leak-check and running to see more details.


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
//add a node to the end of the list
struct node * addToEnd(struct node * head, int value);



int main(void) {
    //This is always inserting at the front of the list
    //So we will get the list in reversed order!
    struct node *head = NULL;
    int num;
    while(scanf("%d",&num) == 1){
       head = createNode(num, head);
    }
    printList(head);
    
    //Add some code to test your functions here
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
   
  return -1;
}

// return count of nodes in list
int length(struct node *head) {
    return -1;
}
 
//return 1 if it found the item and 0 otherwise
int find(struct node * head, int value){
    return -1;
}

struct node * last(struct node * head){
    return NULL;
}

struct node * addToEnd(struct node * head, int value){
    return NULL;
}

//print list in format like [1,2,3,6,8]
void printListFancy(struct node * head){
   //TODO
}
