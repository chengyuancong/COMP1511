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

	Node nodes[10];

	////////////////////////////////////////////////////////////////////
	// One-element list [0]

	l_.head = nodes[0] = newNode (0);
	TEST (nodes[0]->value == listGetMiddle (l), "lGM [0] -> 0");

	
	////////////////////////////////////////////////////////////////////
	// Two-element list [0,1]

	nodes[0]->next = nodes[1] = newNode (1);
	TEST (nodes[1]->value == listGetMiddle (l), "lGM [0,1] -> 1");


	////////////////////////////////////////////////////////////////////
	// Three-element list [0,1,2]

	nodes[1]->next = nodes[2] = newNode (2);
	TEST (nodes[1]->value == listGetMiddle (l), "lGM [0,1,2] -> 1");


	////////////////////////////////////////////////////////////////////
	// Four-element list [0,1,2,3]

	nodes[2]->next = nodes[3] = newNode (3);
	TEST (nodes[2]->value == listGetMiddle (l), "lGM [0,1,2,3] -> 2");


	////////////////////////////////////////////////////////////////////
	// Five-element list [0,1,2,3,4]

	nodes[3]->next = nodes[4] = newNode (4);
	TEST (nodes[2]->value == listGetMiddle (l), "lGM [0,1,2,3,4] -> 2");


	////////////////////////////////////////////////////////////////////
	// Six-element list [0,1,2,3,4,5]

	nodes[4]->next = nodes[5] = newNode (5);
	TEST (nodes[3]->value == listGetMiddle (l),
		"lGM [0,1,2,3,4,5] -> 3");


	////////////////////////////////////////////////////////////////////
	// Seven-element list [0,1,2,3,4,5,6]

	nodes[5]->next = nodes[6] = newNode (6);
	TEST (nodes[3]->value == listGetMiddle (l),
		"lGM [0,1,2,3,4,5,6] -> 3");


	////////////////////////////////////////////////////////////////////
	// Eight-element list [0,1,2,3,4,5,6,7]

	nodes[6]->next = nodes[7] = newNode (7);
	TEST (nodes[4]->value == listGetMiddle (l),
		"lGM [0,1,2,3,4,5,6,7] -> 4");


	////////////////////////////////////////////////////////////////////
	// Nine-element list [0,1,2,3,4,5,6,7,8]

	nodes[7]->next = nodes[8] = newNode (8);
	TEST (nodes[4]->value == listGetMiddle (l),
		"lGM [0,1,2,3,4,5,6,7,8] -> 4");


	////////////////////////////////////////////////////////////////////
	// Ten-element list [0,1,2,3,4,5,6,7,8,9]

	nodes[8]->next = nodes[9] = newNode (9);
	TEST (nodes[5]->value == listGetMiddle (l),
		"lGM [0,1,2,3,4,5,6,7,8,9] -> 5");


	////////////////////////////////////////////////////////////////////
	for (size_t i = 0; i < 10; i++)
		free (nodes[i]);

	return 0;
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