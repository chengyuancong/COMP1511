// COMP1511 17s2 // week11/listLength
// determine the length of a list

#include <stdlib.h>

#include "list.h"

int listLength (List l) {
    int len = 0;
    Node curr = l->head;
    while (curr != NULL) {
        len++;
        curr = curr->next;
    }
    return len;
}