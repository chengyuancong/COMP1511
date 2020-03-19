#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int sum(struct node *head);
struct node *strings_to_list(int len, char *strings[]);

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    int result = sum(head);
    printf("%d\n", result);

    return 0;
}

// Return sum of a linked list.
int sum(struct node *head) {
    int total = 0;
    struct node *n = head;
    while (n != NULL) {
        total = total + n->data;
        n = n->next;
    }
    return total;
}


// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}