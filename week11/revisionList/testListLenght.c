#include <err.h>
#include <stdlib.h>

#include "list.h"
#include "test1511.h"

#define SIZE 10

static Node newNode (int n);

int main (void) {
    // make an array of Nodes
    Node nodes[SIZE];
    int i = 0;
    while (i < SIZE) {
        nodes[i] = newNode ((i + 1) * 17);
        i++;
    }

    // make my list
    List l = calloc (1, sizeof (list));
    if (l == NULL) {
        err (1, "couldn't allocate list");
    }

    l->head = NULL;
    TEST (listLength (l) == 0,
          "listLength (`X`) = 0");

    l->head = nodes[0];
    TEST (listLength (l) == 1,
          "listLength (`17 -> X`) = 1");

    nodes[0]->next = nodes[1];
    TEST (listLength (l) == 2,
          "listLength (`17 -> 34 -> X`) = 2");

    nodes[1]->next = nodes[2];
    TEST (listLength (l) == 3,
          "listLength (`17 -> 34 -> 51 -> X`) = 3");

    nodes[2]->next = nodes[3];
    TEST (listLength (l) == 4,
          "listLength (`17 -> 34 -> 51 -> 68 -> X`) = 4");

    i = 3;
    while (i < SIZE - 1) {
        nodes[i]->next = nodes[i + 1];
        i++;
    }

    TEST (listLength (l) == SIZE,
          "listLength (`17 -> 34 -> 51 -> 68 -> ... -> 170 -> X`) = 10");

    // free memory
    i = 0;
    while (i < SIZE) {
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