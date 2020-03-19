// COMP1511 17s2 // week11/listGetMiddle
// get the "middle" node from a linked list

#include <assert.h>
#include <stdlib.h>

#include "list.h"

int listGetMiddle (List l) {
    assert (l != NULL);
    return listGetNth (l, listLength (l) / 2);
}

int listLength (List l) {
    assert (l != NULL);

    int len = 0;
    Node curr = l->head;
    while (curr != NULL) {
        len++;
        curr = curr->next;
    }
    return len;
}

int listGetNth (List l, int n) {
    assert (l != NULL);

    int i = 0;
    Node curr = l->head;
    while (curr != NULL && i < n) {
        i++;
        curr = curr->next;
    }
    return curr->value;
}