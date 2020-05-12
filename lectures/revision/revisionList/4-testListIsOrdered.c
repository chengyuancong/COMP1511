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
        nodes[i] = newNode (i);
        i++;
    }

    // make my list
    List l = calloc (1, sizeof (list));
    if (l == NULL) {
        err (1, "couldn't allocate list");
    }

    l->head = NULL;
    TEST (listIsOrdered (l) == TRUE,
          "empty list");

    l->head = nodes[0];
    TEST (listIsOrdered (l) == TRUE,
          "list with single element");

    i = 0;
    while (i < SIZE - 1) {
        nodes[i]->next = nodes[i + 1];
        i++;
    }

    l->head = nodes[0];
    TEST (listIsOrdered (l) == TRUE,
          "strictly increasing list");

    i = 0;
    while (i < SIZE) {
        nodes[i]->value = i - SIZE / 2;
        i++;
    }

    TEST (listIsOrdered (l) == TRUE,
          "strictly increasing list with negative numbers");

    i = 0;
    while (i < SIZE) {
        nodes[i]->value = i / 2;
        i++;
    }

    TEST (listIsOrdered (l) == TRUE,
          "non decreasing list with repeated numbers");

    i = 0;
    while (i < SIZE) {
        nodes[i]->value = SIZE - i;
        i++;
    }

    TEST (listIsOrdered (l) == FALSE,
          "strictly decreasing list");

    i = 0;
    while (i < SIZE) {
        nodes[i]->value = (SIZE - i) / 2;
        i++;
    }

    TEST (listIsOrdered (l) == FALSE,
          "decreasing list with repeating numbers");

    int nums[SIZE] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    i = 0;
    while (i < SIZE) {
        nodes[i]->value = nums[i];
        i++;
    }

    TEST (listIsOrdered (l) == FALSE,
          "random numbers");

    int nums2[SIZE] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 7};
    i = 0;
    while (i < SIZE) {
        nodes[i]->value = nums2[i];
        i++;
    }

    TEST (listIsOrdered (l) == FALSE,
          "random numbers 2");

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