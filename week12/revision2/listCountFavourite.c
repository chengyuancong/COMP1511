// COMP1511 17s2 // week11/listCountFavourite
// count the number of nodes whose values are multiples of 17

#include <assert.h>
#include <stdlib.h>

#include "list.h"

int listCountFavourite (List l) {
    assert (l != NULL);

    int count = 0;

    Node curr = l->head;

    while (curr != NULL) {
        if (curr->value % 17 == 0) {
            count++;
        }

        curr = curr->next;
    }

    return count;
}