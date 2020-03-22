// COMP1511 17s2 // week11/listInsertTail
// insert a value at the end of a linked list

#include <assert.h>
#include <err.h>
#include <stdlib.h>

#include "list.h"

static Node newNode (int n);

void listInsertTail (List l, int val) {
    Node n = newNode (val);

    if (l->head == NULL) {
        l->head = n;
    } else {
        Node curr = l->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = n;
    }
}

static Node newNode (int val) {
    Node n = calloc (1, sizeof (node));
    if (n == NULL) {
        err (1, "couldn't allocate for node");
    }
    n->value = val;

    return n;
}