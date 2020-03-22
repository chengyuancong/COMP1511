#include <err.h>
#include <stdlib.h>

#include "list.h"

static Node newNode (int n);

int main (void) {
    Node nodes[4];
    int i = 0;
    while (i < 4) {
        nodes[i] = newNode ((i + 1) * 17);
        i++;
    }

    // make my list
    List l = calloc (1, sizeof (list));
    if (l == NULL) {
        err (1, "couldn't allocate list");
    }

    l->head = NULL;
    listPrint (l);

    l->head = nodes[0];
    listPrint (l);

    nodes[0]->next = nodes[1];
    listPrint (l);

    nodes[1]->next = nodes[2];
    listPrint (l);

    nodes[2]->next = nodes[3];
    listPrint (l);

    i = 0;
    while (i < 4) {
        free (nodes[i]);
        i++;
    }

    free (l);
}

static Node newNode (int n) {
    Node new = calloc (1, sizeof (node));
    if (new == NULL) {
        err (1, "couldn't allocate node");
    }

    new->value = n;
    new->next = NULL;

    return new;
}