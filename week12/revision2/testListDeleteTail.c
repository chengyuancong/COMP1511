#include <err.h>
#include <stdlib.h>

#include "list.h"
#include "test1511.h"

static Node newNode (int);

int
main (
	void)
{
	list l_ = { NULL };
	List l = &l_;

	Node nodes[4];

	////////////////////////////////////////////////////////////////////
	// Empty list
	listDeleteTail (l);
	TEST (l->head == NULL, "lDT [] -> []");


	////////////////////////////////////////////////////////////////////
	// One-element list [0]

	l_.head = nodes[0] = newNode (0);

	listDeleteTail (l);
	TEST (l->head == NULL, "lDT [0] -> []");
	TEST (mem_address_is_poisoned (nodes[0]), "node 0 was freed");

	
	////////////////////////////////////////////////////////////////////
	// Two-element list [0,1]

	l_.head = nodes[0] = newNode (0);
	nodes[0]->next = nodes[1] = newNode (1);

	listDeleteTail (l);
	TEST (l->head == nodes[0], "lDT [0,1] -> [0]");
	TEST (nodes[0]->next == NULL, "[0]->next == NULL");
	TEST (mem_address_is_poisoned (nodes[1]), "node 1 was freed");

	free (nodes[0]);


	////////////////////////////////////////////////////////////////////
	// Three-element list [0,1,2]

	l_.head = nodes[0] = newNode (0);
	nodes[0]->next = nodes[1] = newNode (1);
	nodes[1]->next = nodes[2] = newNode (2);

	listDeleteTail (l);
	TEST (l->head == nodes[0], "lDT [0,1,2] -> [0,1]");
	TEST (nodes[0]->next == nodes[1], "[0]->next == [1]");
	TEST (nodes[1]->next == NULL, "[1]->next == NULL");
	TEST (mem_address_is_poisoned (nodes[2]), "node 2 was freed");

	free (nodes[0]);
	free (nodes[1]);


	////////////////////////////////////////////////////////////////////
	// Four-element list [0,1,2,3]

	l_.head = nodes[0] = newNode (0);
	nodes[0]->next = nodes[1] = newNode (1);
	nodes[1]->next = nodes[2] = newNode (2);
	nodes[2]->next = nodes[3] = newNode (3);

	listDeleteTail (l);
	TEST (l->head == nodes[0], "lDT [0,1,2,3] -> [0,1,2]");
	TEST (nodes[0]->next == nodes[1], "[0]->next == [1]");
	TEST (nodes[1]->next == nodes[2], "[1]->next == [2]");
	TEST (nodes[2]->next == NULL, "[2]->next == NULL");
	TEST (mem_address_is_poisoned (nodes[3]), "node 3 was freed");

	free (nodes[0]);
	free (nodes[1]);
	free (nodes[2]);
}

static Node
newNode (
	int n)
{
    Node new = calloc (1, sizeof (node));
    if (new == NULL)
        err (1, "couldn't allocate node");
    new->value = n;
    return new;
}