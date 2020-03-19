// COMP1511 17s2 // week11/listContains
// does a list contain a particular value?

#include <assert.h>
#include <stdlib.h>

#include "list.h"

int listContains (List l, int val) {
    assert (l != NULL);

    int flag = FALSE;

    Node curr = l->head;
    while (curr != NULL && flag == FALSE) {
        if (curr->value == val) {
            flag = TRUE;
        }

        curr = curr->next;
    }

    return flag;
}