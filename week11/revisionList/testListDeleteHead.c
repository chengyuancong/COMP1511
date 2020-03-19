#include <err.h>
#include <stdlib.h>

#include "list.h"
#include "test1511.h"

#define SIZE 2

static Node newNode (int n);

int main (void) {
    // make nodes
    Node nodes[SIZE];
    int i = 0;
    while (i < SIZE) {
        nodes[i] = newNode ((i + 1) * 17);
        i++;
    }

    i = 0;
    while (i < SIZE - 1) {
        nodes[i]->next = nodes[i + 1];
        i++;
    }

    // make my list
    List l = calloc (1, sizeof (list));
    if (l == NULL) {
        err (1, "couldn't allocate list");
    }

    l->head = nodes[0];

    listDeleteHead (l);

    TEST (l->head != NULL,
          "checking that head isn't NULL after deleting node from long list");

    TEST (l->head->value == 34,
          "checking value of deleted head after deleting node");

    TEST (mem_address_is_poisoned (nodes[0]),
          "checking node was freed");

    listDeleteHead (l);

    TEST (l->head == NULL,
          "checking that head is NULL after deleting last value");

    TEST (mem_address_is_poisoned (nodes[1]),
          "checking node was freed");

    listDeleteHead (l);

    TEST (l->head == NULL,
          "testing deleting from empty list");

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