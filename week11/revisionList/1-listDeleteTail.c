// COMP1511 17s2 // week11/listDeleteTail
// delete the last item from a linked list

#include <assert.h>
#include <stdlib.h>

#include "list.h"

void listDeleteTail (List l) {
    assert (l != NULL);

    if (l->head != NULL) {
        Node curr = l->head;

        if (curr->next == NULL) {
            free (l->head);
            l->head = NULL;
        } else {
            while (curr->next->next != NULL) {
                curr = curr->next;
            }

            Node temp = curr->next;
            curr->next = NULL;
            free (temp);
        }
    }
}