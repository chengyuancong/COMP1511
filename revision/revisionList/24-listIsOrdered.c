// COMP1511 17s2 // week11/listIsOrdered
// is a linked list in order?

#include <assert.h>
#include <err.h>
#include <stdlib.h>

#include "list.h"

int listIsOrdered (List l) {
    assert (l != NULL);

    int inOrder = TRUE;

    if (l->head != NULL) {
        Node prev = l->head;
        Node curr = prev->next;
        while (curr != NULL && inOrder) {
            if (! (prev->value <= curr->value)) {
                inOrder = FALSE;
            }

            prev = curr;
            curr = curr->next;
        }
    }

    return inOrder;
}