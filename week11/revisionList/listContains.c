// week11/listContains
// does a list contain a particular value?

#include <assert.h>
#include <stdlib.h>

#include "list.h"

int listContains (List l, int val) {
    assert (l != NULL);

    int flag = FALSE;

    Node curr = l->head;
    while (curr != NULL) {
        if (curr->value == val) {
            //flag = TRUE;
            return 1;
        }
        curr = curr->next;
    }

    return 0;
}