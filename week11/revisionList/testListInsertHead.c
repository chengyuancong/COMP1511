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

    listInsertHead (l, 17);

    TEST (l->head != NULL,
          "listInsertHead (`X`, 17), checking head pointer");

    TEST (l->head->value == 17,
          "listInsertHead (`X`, 17) = `17 -> X`");

    TEST (l->head->next == NULL,
          "listInsertHead (`X`, 17), checking next pointer");

    listInsertHead (l, 42);

    TEST (l->head->next != NULL,
          "listInsertHead (`17 -> X`, 42), checking pointers");

    TEST (l->head->value == 42,
          "listInsertHead (`17 -> X`, 42) = `42 -> 17 -> X`");
    TEST (l->head->next->value == 17,
          "listInsertHead (`17 -> X`, 42) = `42 -> 17 -> X`");

    TEST (l->head->next->next == NULL,
          "listInsertHead ([`17 -> X`, 42), "
          "checking NULL pointer at end of list");

    free (l->head->next);
    free (l->head);
    free (l);
}