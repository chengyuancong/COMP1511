#include <err.h>
#include <stdlib.h>

#include "list.h"
#include "test1511.h"

int main (void) {
    // make my list
    List l = calloc (1, sizeof (list));
    if (l == NULL) {
        err (1, "couldn't allocate list");
    }

    l->head = NULL;

    listInsertTail (l, 17);

    TEST (l->head != NULL,
          "listInsertTail (`X`, 17), checking head pointer");

    TEST (l->head->value == 17,
          "listInsertTail (`X`, 17) = `17 -> X`");

    TEST (l->head->next == NULL,
          "listInsertTail (`X`, 17), checking next pointer");

    listInsertTail (l, 42);

    TEST (l->head->next != NULL,
          "listInsertTail (`17 -> X`, 42), checking pointers");

    TEST (l->head->next->value == 42,
          "listInsertTail (`17 -> X`, 42) = `17 -> 42 -> X`");

    TEST (l->head->value == 17,
          "listInsertTail (`17 -> X`, 42) = `17 -> 42 -> X`");

    TEST (l->head->next->next == NULL,
          "listInsertTail ([`17 -> X`, 42), "
          "checking NULL pointer at end of list");

    free (l->head->next);
    free (l->head);
    free (l);
}