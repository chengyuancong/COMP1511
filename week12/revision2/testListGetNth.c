#include <err.h>
#include <stdlib.h>

#include "list.h"
#include "test1511.h"

#define SIZE 16

static Node newNode (int n);

int main (void) {
    int nums[SIZE] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3};
    // make an array of Nodes
    Node nodes[SIZE];
    int i = 0;
    while (i < SIZE) {
        nodes[i] = newNode (nums[i]);
        i++;
    }

    // make my list
    List l = calloc (1, sizeof (list));
    if (l == NULL) {
        err (1, "couldn't allocate list");
    }

    l->head = NULL;

    l->head = nodes[0];
    TEST (listGetNth (l, 0) == 3,
          "listGetNth (`3 -> X`, 0) = 3");

    nodes[0]->next = nodes[1];
    TEST (listGetNth (l, 0) == 3,
          "listGetNth (`3 -> 1 -> X`, 0) = 3");
    TEST (listGetNth (l, 1) == 1,
          "listGetNth (`3 -> 1 -> X`, 1) = 1");

    nodes[1]->next = nodes[2];
    nodes[2]->next = nodes[3];
    nodes[3]->next = nodes[4];

    TEST (listGetNth (l, 2) == 4,
          "listGetNth (`3 -> 1 -> 4 -> 1 -> 5 -> X`, 2) = 4");

    i = 4;
    while (i < SIZE - 1) {
        nodes[i]->next = nodes[i + 1];
        i++;
    }

    TEST (listGetNth (l, 2) == 4,
          "listGetNth (`3 -> 1 -> 4 -> 1 -> 5 -> ... -> X`, 2) = 4");

    TEST (listGetNth (l, 10) == 5,
          "listGetNth (3 -> 1 -> 4 -> 1 -> 5 -> ... -> X`, 10) = 5");
    TEST (listGetNth (l, 15) == 3,
          "listGetNth (3 -> 1 -> 4 -> 1 -> 5 -> ... -> X`, 15) = 3");

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