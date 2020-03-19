// COMP1511 17s2 // week11/listInsertHead
// insert a value at the head of a linked list

#include <assert.h>
#include <stdlib.h>

#include "list.h"

static Node newNode (int n);

void listInsertHead (List l, int val) {
    assert (l != NULL);

    Node n = newNode (val);

    n->next = l->head;
    l->head = n;
}

static Node newNode (int val) {
    Node n = calloc (1, sizeof (node));
    if (n == NULL) {
        err (1, "couldn't allocate for node");
    }
    n->value = val;

    return n;
}