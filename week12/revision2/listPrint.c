// COMP1511 17s2 // week11/listPrint
// print out a linked list

#include <assert.h>
#include <stdlib.h>

#include "list.h"

void listPrint (List l) {
    assert (l != NULL);

    Node curr = l->head;
    while (curr != NULL) {
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    printf("X\n");
}