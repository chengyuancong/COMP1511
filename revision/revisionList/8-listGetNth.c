// COMP1511 17s2 // week11/listGetNth
// get the 'n'th item from a linked list

#include <assert.h>
#include <stdlib.h>

#include "list.h"

int listGetNth (List l, int n) {
    assert (l != NULL);

    Node curr = l->head;
    int i = 0;
    while (curr != NULL && i < n) {
        i++;
        curr = curr->next;
    }

    assert (curr != NULL);
    return curr->value;
}