#include <err.h>
#include <stdlib.h>

#include "list.h"
#include "test1511.h"

#define SIZE 11

static Node newNode (int n);

int main (void) {
    int nums[SIZE] = {17, 42, 3, 1, 4, 1, -5, 9, 2, 6, 5};
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
    TEST (listContains (l, 17) == FALSE,
          "listContains ([], 17) = FALSE");

    l->head = nodes[0];

    TEST (listContains (l, 17) == TRUE,
          "listContains ([17], 17) = TRUE");
    TEST (listContains (l, 42) == FALSE,
          "listContains ([17], 42) = FALSE");

    nodes[0]->next = nodes[1];
    TEST (listContains (l, 17) == TRUE,
          "listContains ([17, 42], 17) = TRUE");
    TEST (listContains (l, 42) == TRUE,
          "listContains ([17, 42], 42) = TRUE");
    TEST (listContains (l, 3) == FALSE,
          "listContains ([17, 42], 3) = FALSE");

    nodes[1]->next = nodes[2];
    TEST (listContains (l, 17) == TRUE,
          "listContains ([17, 42, 3], 17) = TRUE");
    TEST (listContains (l, 42) == TRUE,
          "listContains ([17, 42, 3], 42) = TRUE");
    TEST (listContains (l, 3) == TRUE,
          "listContains ([17, 42, 3], 3) = TRUE");
    TEST (listContains (l, 1) == FALSE,
          "listContains ([17, 42, 3], 1) = FALSE");

    i = 2;
    while (i < SIZE - 1) {
        nodes[i]->next = nodes[i + 1];
        i++;
    }

    TEST (listContains (l, 17) == TRUE,
          "listContains ([17, 42, 3, 1, 4, 1, -5, 9, 2, 6, 5], 17) = TRUE");
    TEST (listContains (l, 42) == TRUE,
          "listContains ([17, 42, 3, 1, 4, 1, -5, 9, 2, 6, 5], 42) = TRUE");
    TEST (listContains (l, 3) == TRUE,
          "listContains ([17, 42, 3, 1, 4, 1, -5, 9, 2, 6, 5], 3) = TRUE");
    TEST (listContains (l, 1) == TRUE,
          "listContains ([17, 42, 3, 1, 4, 1, -5, 9, 2, 6, 5], 1) = TRUE");
    TEST (listContains (l, -5) == TRUE,
          "listContains ([17, 42, 3, 1, 4, 1, -5, 9, 2, 6, 5], -5) = TRUE");
    TEST (listContains (l, -1) == FALSE,
          "listContains ([17, 42, 3, 1, 4, 1, -5, 9, 2, 6, 5], -1) = FALSE");

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