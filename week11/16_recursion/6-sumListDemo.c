// Use the testDemo program to generate lots of input and test with 
// a very long list. What happens?
// Try
// ./testDemo 10000 | ./sumListDemo
// ./testDemo 100000 | ./sumListDemo
// etc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    struct node *next;
    int       data;
};

 
struct node *insertFront(struct node *head,int number) ;
long long sum(struct node *head);

int main(int argc, char *argv[]) {
    struct node *head = NULL;
    
    //Infinitely loop until we reach the break statement
    while (1) {
        int number;
        if (scanf("%d", &number) != 1) {
            break;
        }
        head = insertFront(head, number);
    }

    long long sumList = sum(head);
    
    printf("Sum %lld\n",sumList);    
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


// create a new list node containing value
// and append it to end of list

struct node *insertFront(struct node *head, int value) {
    // new node will be last in list, so next field is NULL
    head =  createNode(value,head);
    return head;
}


//recursive sum
long long sum(struct node *head) {
    if (head == NULL) {
        return 0;
    }
    return head->data + sum(head->next);
}



