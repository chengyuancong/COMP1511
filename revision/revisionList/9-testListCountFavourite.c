#include <stdlib.h>
#include <err.h>

#include "list.h"
#include "test1511.h"

#define SIZE 10

Node newNode (int n);

int main (int argc, char *argv[]) {
    //make an array of Nodes
    Node nodes[SIZE];
    int i = 0;
    while (i < SIZE) {
        nodes[i] = newNode(i+1);
        i++;
    }

    // make my list
    List l = calloc(1, sizeof(list));
    if (!l) err(1, "couldn't allocate list");
    
    l->head = NULL;
    TEST (listCountFavourite (l) == 0,
        "empty list");
        
    l->head = nodes[0];
    TEST (listCountFavourite (l) == 0,
        "1 -> X");
        
    nodes[0]->value = 17;
    TEST (listCountFavourite (l) == 1,
        "17 -> X");
        
    nodes[0]->value = 34;
    TEST (listCountFavourite (l) == 1,
        "34 -> X");
        
    i = 0;
    while (i < SIZE-1) {
        nodes[i]->next = nodes[i+1];
        i++;
    }
    
    nodes[0]->value = 1;
    TEST (listCountFavourite (l) == 0,
        "1 -> 2 -> ... -> 9 -> 10 -> X");
        
    nodes[3]->value = 17;
    nodes[5]->value = 51;
    nodes[9]->value = 170;
    
    TEST (listCountFavourite (l) == 3,
        "mixed list");
    
    //free memory
    i = 0;
    while (i < SIZE) {
        free(nodes[i]);
        i++;
    }
    
    free(l);
}

Node newNode (int n) {
    Node new = calloc(1, sizeof(node));
    if (!new) err(1, "couldn't allocate node");
    
    new->value = n;
    new->next = NULL;

    return new;
}