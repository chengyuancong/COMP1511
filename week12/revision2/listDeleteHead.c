// COMP1511 17s2 // week11/listDeleteHead
// delete the first node from a linked list

#include <assert.h>
#include <stdlib.h>

#include "list.h"

void listDeleteHead (List l) {
    assert (l != NULL);

    if (l->head != NULL) {
        Node temp = l->head;
        l->head = l->head->next;
        free (temp);
    }
}