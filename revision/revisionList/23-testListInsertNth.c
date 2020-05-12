#include <err.h>
#include <stdlib.h>
#include <sysexits.h>

#include "list.h"
#include "test1511.h"

static Node node_new (int value);
static inline void test_zero (void);
static inline void test_zero_zero (void);

static inline void test_one (void);
static inline void test_one_zero (void);
static inline void test_one_one (void);

static inline void test_two (void);
static inline void test_two_zero (void);
static inline void test_two_one (void);
static inline void test_two_two (void);

static inline void test_three (void);
static inline void test_three_zero (void);
static inline void test_three_one (void);
static inline void test_three_two (void);
static inline void test_three_three (void);

static inline void test_four (void);
static inline void test_four_zero (void);
static inline void test_four_one (void);
static inline void test_four_two (void);
static inline void test_four_three (void);
static inline void test_four_four (void);

static inline void test_five (void);
static inline void test_five_zero (void);
static inline void test_five_one (void);
static inline void test_five_two (void);
static inline void test_five_three (void);
static inline void test_five_four (void);
static inline void test_five_five (void);

#define AAAA 0x41414141
#define BBBB 0x42424242
#define CCCC 0x43434343
#define DDDD 0x44444444
#define EEEE 0x45454545
#define FFFF 0x46464646

int
main (
	void)
{
	// void listInsertNth (List l, int n, int val);

	test_zero ();
	test_one ();
	test_two ();
	test_three ();
	test_four ();
	test_five ();

	return 0;
}

static inline void
test_zero (
	void)
{
	test_zero_zero ();
}

static inline void
test_one (
	void)
{
	test_one_zero ();
	test_one_one ();
}

static inline void
test_two (
	void)
{
	test_two_zero ();
	test_two_one ();
	test_two_two ();
}

static inline void
test_three (
	void)
{
	test_three_zero ();
	test_three_one ();
	test_three_two ();
	test_three_three ();
}

static inline void
test_four (
	void)
{
	test_four_zero ();
	test_four_one ();
	test_four_two ();
	test_four_three ();
	test_four_four ();
}

static inline void
test_five (
	void)
{
	test_five_zero ();
	test_five_one ();
	test_five_two ();
	test_five_three ();
	test_five_four ();
	test_five_five ();
}


////////////////////////////////////////////////////////////////////////
// empty list: @0
static inline void
test_zero_zero (
	void)
{
	list l_ = { NULL };
	list *l = &l_;
	node *nodes[1];

	listInsertNth (l, 0, AAAA);

	TEST (l->head != NULL,
		"lIN ([] @0, AAAA)");
	nodes[0] = l->head;

	TEST (nodes[0]->value == AAAA,
		"node[0]->value == AAAA");
	TEST (nodes[0]->next == NULL,
		"node[0]->next == NULL");

	free (nodes[0]);
}


////////////////////////////////////////////////////////////////////////
// one-element list: @0
static inline void
test_one_zero (
	void)
{
	list l_ = { NULL };
	list *l = &l_;
	node *nodes[2];

	l->head = nodes[1] = node_new (BBBB);
	listInsertNth (l, 0, AAAA);

	TEST (l->head != NULL,
		"lIN ([BBBB,x] @0, AAAA)");
	TEST (l->head != nodes[1], "l->head != [BBBB,]");
	nodes[0] = l->head;

	TEST (nodes[0]->value == AAAA,
		"node[0]->value == AAAA");
	TEST (nodes[0]->next != nodes[0],
		"node[0]->next != node[0]");
	TEST (nodes[0]->next == nodes[1],
		"node[0]->next == node[1]");

	TEST (nodes[1]->value == BBBB,
		"node[1]->value == BBBB");
	TEST (nodes[1]->next == NULL,
		"node[1]->next == NULL");

	free (nodes[0]);
	free (nodes[1]);
}


////////////////////////////////////////////////////////////////////////
// one-element list: @1
static inline void
test_one_one (
	void)
{
	list l_ = { NULL };
	list *l = &l_;
	node *nodes[2];

	l->head = nodes[0] = node_new (AAAA);
	listInsertNth (l, 1, BBBB);

	TEST (l->head != NULL,
		"lIN ([AAAA,x] @1, BBBB)");
	TEST (l->head == nodes[0], "l->head == [AAAA,]");

	TEST (l->head->value == AAAA,
		"node[0]->value == AAAA");
	TEST (l->head->next != NULL,
		"node[0]->next != NULL");
	TEST (l->head->next != nodes[0],
		"node[0]->next != node[0]");
	nodes[1] = l->head->next;

	TEST (nodes[1]->value == BBBB,
		"node[1]->value == BBBB");
	TEST (nodes[1]->next == NULL,
		"node[1]->next == NULL");

	free (nodes[0]);
	free (nodes[1]);
}


////////////////////////////////////////////////////////////////////////
// two-element list: @0
static inline void
test_two_zero (
	void)
{
	list l_ = { NULL };
	list *l = &l_;
	node *nodes[3];

	l->head = nodes[1] = node_new (BBBB);
	nodes[1]->next = nodes[2] = node_new (CCCC);
	listInsertNth (l, 0, AAAA);

	TEST (l->head != NULL,
		"lIN ([BBBB,[CCCC,x]] @0, AAAA)");
	TEST (l->head != nodes[1], "l->head != [BBBB,]");
	TEST (l->head != nodes[2], "l->head != [CCCC,]");
	nodes[0] = l->head;

	TEST (nodes[0]->value == AAAA,
		"node[0]->value == AAAA");
	TEST (nodes[0]->next == nodes[1],
		"node[0]->next == node[1] == [BBBB,]");

	TEST (nodes[1]->value == BBBB,
		"node[1]->value == BBBB");
	TEST (nodes[1]->next == nodes[2],
		"node[1]->next == node[2] == [CCCC,]");

	TEST (nodes[2]->value == CCCC,
		"node[2]->value == CCCC");
	TEST (nodes[2]->next == NULL,
		"node[2]->next == NULL");

	free (nodes[0]);
	free (nodes[1]);
	free (nodes[2]);
}


////////////////////////////////////////////////////////////////////////
// two-element list: @1
static inline void
test_two_one (
	void)
{
	list l_ = { NULL };
	list *l = &l_;
	node *nodes[3];

	l->head = nodes[0] = node_new (AAAA);
	nodes[0]->next = nodes[2] = node_new (CCCC);

	listInsertNth (l, 1, BBBB);

	TEST (l->head != NULL,
		"lIN ([AAAA,[CCCC,x]] @1, BBBB)");
	TEST (l->head == nodes[0], "l->head == [AAAA,]");
	TEST (l->head != nodes[2], "l->head != [CCCC,]");

	TEST (nodes[0]->value == AAAA,
		"node[0]->value == AAAA");
	TEST (nodes[0]->next != NULL,
		"node[0]->next != NULL");
	TEST (nodes[0]->next != nodes[0],
		"node[0]->next != node[0]");
	TEST (nodes[0]->next != nodes[2],
		"node[0]->next != node[2]");
	nodes[1] = l->head->next;

	TEST (nodes[1]->value == BBBB,
		"node[1]->value == BBBB");
	TEST (nodes[1]->next == nodes[2],
		"node[1]->next == node[2] == [CCCC,]");

	TEST (nodes[2]->value == CCCC,
		"node[2]->value == CCCC");
	TEST (nodes[2]->next == NULL,
		"node[2]->next == NULL");

	free (nodes[0]);
	free (nodes[1]);
	free (nodes[2]);
}


////////////////////////////////////////////////////////////////////////
// two-element list: @2
static inline void
test_two_two (
	void)
{
	list l_ = { NULL };
	list *l = &l_;
	node *nodes[3];

	l->head = nodes[0] = node_new (AAAA);
	nodes[0]->next = nodes[1] = node_new (BBBB);

	listInsertNth (l, 2, CCCC);

	TEST (l->head != NULL,
		"lIN ([AAAA,[BBBB,x]] @2, CCCC)");
	TEST (l->head == nodes[0], "l->head == [AAAA,]");
	TEST (l->head != nodes[1], "l->head != [BBBB,]");

	TEST (nodes[0]->value == AAAA,
		"node[0]->value == AAAA");
	TEST (nodes[0]->next != NULL,
		"node[0]->next != NULL");
	TEST (nodes[0]->next == nodes[1],
		"node[0]->next == node[1]");

	TEST (nodes[1]->value == BBBB,
		"node[1]->value == BBBB");
	TEST (nodes[1]->next != NULL,
		"node[1]->next != NULL");
	TEST (nodes[1]->next != nodes[0],
		"node[1]->next != nodes[0]");
	TEST (nodes[1]->next != nodes[1],
		"node[1]->next != nodes[1]");
	nodes[2] = nodes[1]->next;

	TEST (nodes[2]->value == CCCC,
		"node[2]->value == CCCC");
	TEST (nodes[2]->next == NULL,
		"node[2]->next == NULL");

	free (nodes[0]);
	free (nodes[1]);
	free (nodes[2]);
}


////////////////////////////////////////////////////////////////////
// three-element list: @0
static inline void
test_three_zero (
	void)
{
	list l_ = { NULL };
	list *l = &l_;
	node *nodes[4];

	l->head = nodes[1] = node_new (BBBB);
	nodes[1]->next = nodes[2] = node_new (CCCC);
	nodes[2]->next = nodes[3] = node_new (DDDD);

	listInsertNth (l, 0, AAAA);

	TEST (l->head != NULL,
		"lIN ([BBBB,[CCCC,[DDDD,x]]] @0, AAAA)");
	TEST (l->head != nodes[1], "l->head != [BBBB,]");
	TEST (l->head != nodes[2], "l->head != [CCCC,]");
	TEST (l->head != nodes[3], "l->head != [DDDD,]");
	nodes[0] = l->head;

	TEST (nodes[0]->value == AAAA,
		"node[0]->value == AAAA");
	TEST (nodes[0]->next != NULL,
		"node[0]->next != NULL");
	TEST (nodes[0]->next != nodes[0],
		"node[0]->next != node[0]");
	TEST (nodes[0]->next == nodes[1],
		"node[0]->next == node[1]");

	TEST (nodes[1]->value == BBBB,
		"node[1]->value == BBBB");
	TEST (nodes[1]->next != NULL,
		"node[1]->next != NULL");
	TEST (nodes[1]->next != nodes[1],
		"node[1]->next != nodes[1]");
	TEST (nodes[1]->next == nodes[2],
		"node[1]->next == nodes[2]");

	TEST (nodes[2]->value == CCCC,
		"node[2]->value == CCCC");
	TEST (nodes[2]->next != NULL,
		"node[2]->next != NULL");
	TEST (nodes[2]->next != nodes[2],
		"node[2]->next != nodes[1]");
	TEST (nodes[2]->next == nodes[3],
		"node[2]->next == nodes[3]");

	TEST (nodes[3]->value == DDDD,
		"node[3]->value == DDDD");
	TEST (nodes[3]->next == NULL,
		"node[3]->next == NULL");

	free (nodes[0]);
	free (nodes[1]);
	free (nodes[2]);
	free (nodes[3]);
}


////////////////////////////////////////////////////////////////////////
// three-element list: @1
static inline void
test_three_one (
	void)
{
	list l_ = { NULL };
	list *l = &l_;
	node *nodes[4];

	l->head = nodes[0] = node_new (AAAA);
	nodes[0]->next = nodes[2] = node_new (CCCC);
	nodes[2]->next = nodes[3] = node_new (DDDD);

	listInsertNth (l, 1, BBBB);

	TEST (l->head != NULL,
		"lIN ([AAAA,[CCCC,[DDDD,x]]] @1, BBBB)");
	TEST (l->head == nodes[0], "l->head == [AAAA,]");
	TEST (l->head != nodes[2], "l->head != [CCCC,]");
	TEST (l->head != nodes[3], "l->head != [DDDD,]");

	TEST (nodes[0]->value == AAAA,
		"node[0]->value == AAAA");
	TEST (nodes[0]->next != NULL,
		"node[0]->next != NULL");
	TEST (nodes[0]->next != nodes[0],
		"node[0]->next != node[0]");
	TEST (nodes[0]->next != nodes[2],
		"node[0]->next != node[2]");
	nodes[1] = nodes[0]->next;

	TEST (nodes[1]->value == BBBB,
		"node[1]->value == BBBB");
	TEST (nodes[1]->next != NULL,
		"node[1]->next != NULL");
	TEST (nodes[1]->next != nodes[1],
		"node[1]->next != nodes[1]");
	TEST (nodes[1]->next == nodes[2],
		"node[1]->next == nodes[2]");

	TEST (nodes[2]->value == CCCC,
		"node[2]->value == CCCC");
	TEST (nodes[2]->next != NULL,
		"node[2]->next != NULL");
	TEST (nodes[2]->next != nodes[2],
		"node[2]->next != nodes[1]");
	TEST (nodes[2]->next == nodes[3],
		"node[2]->next == nodes[3]");

	TEST (nodes[3]->value == DDDD,
		"node[3]->value == DDDD");
	TEST (nodes[3]->next == NULL,
		"node[3]->next == NULL");

	free (nodes[0]);
	free (nodes[1]);
	free (nodes[2]);
	free (nodes[3]);
}


////////////////////////////////////////////////////////////////////////
// three-element list: @2
static inline void
test_three_two (
	void)
{
	list l_ = { NULL };
	list *l = &l_;
	node *nodes[4];

	l->head = nodes[0] = node_new (AAAA);
	nodes[0]->next = nodes[1] = node_new (BBBB);
	nodes[1]->next = nodes[3] = node_new (DDDD);

	listInsertNth (l, 2, CCCC);

	TEST (l->head != NULL,
		"lIN ([AAAA,[BBBB,[DDDD,x]]] @2, CCCC)");
	TEST (l->head == nodes[0], "l->head == [AAAA,]");
	TEST (l->head != nodes[1], "l->head != [BBBB,]");
	TEST (l->head != nodes[3], "l->head != [DDDD,]");

	TEST (nodes[0]->value == AAAA,
		"node[0]->value == AAAA");
	TEST (nodes[0]->next != NULL,
		"node[0]->next != NULL");
	TEST (nodes[0]->next != nodes[0],
		"node[0]->next != node[0]");
	TEST (nodes[0]->next == nodes[1],
		"node[0]->next == node[1]");

	TEST (nodes[1]->value == BBBB,
		"node[1]->value == BBBB");
	TEST (nodes[1]->next != NULL,
		"node[1]->next != NULL");
	TEST (nodes[1]->next != nodes[1],
		"node[1]->next != nodes[1]");
	TEST (nodes[1]->next != nodes[3],
		"node[1]->next != nodes[3]");
	nodes[2] = nodes[1]->next;

	TEST (nodes[2]->value == CCCC,
		"node[2]->value == CCCC");
	TEST (nodes[2]->next != NULL,
		"node[2]->next != NULL");
	TEST (nodes[2]->next != nodes[2],
		"node[2]->next != nodes[1]");
	TEST (nodes[2]->next == nodes[3],
		"node[2]->next == nodes[3]");

	TEST (nodes[3]->value == DDDD,
		"node[3]->value == DDDD");
	TEST (nodes[3]->next == NULL,
		"node[3]->next == NULL");

	free (nodes[0]);
	free (nodes[1]);
	free (nodes[2]);
	free (nodes[3]);
}


////////////////////////////////////////////////////////////////////////
// three-element list: @3
static inline void
test_three_three (
	void)
{
	list l_ = { NULL };
	list *l = &l_;
	node *nodes[4];

	l->head = nodes[0] = node_new (AAAA);
	nodes[0]->next = nodes[1] = node_new (BBBB);
	nodes[1]->next = nodes[2] = node_new (CCCC);

	listInsertNth (l, 3, DDDD);

	TEST (l->head != NULL,
		"lIN ([AAAA,[BBBB,[CCCC,x]]] @3, DDDD)");
	TEST (l->head == nodes[0], "l->head == [AAAA,]");
	TEST (l->head != nodes[1], "l->head != [BBBB,]");
	TEST (l->head != nodes[2], "l->head != [CCCC,]");

	TEST (nodes[0]->value == AAAA,
		"node[0]->value == AAAA");
	TEST (nodes[0]->next != NULL,
		"node[0]->next != NULL");
	TEST (nodes[0]->next != nodes[0],
		"node[0]->next != node[0]");
	TEST (nodes[0]->next == nodes[1],
		"node[0]->next == node[1]");

	TEST (nodes[1]->value == BBBB,
		"node[1]->value == BBBB");
	TEST (nodes[1]->next != NULL,
		"node[1]->next != NULL");
	TEST (nodes[1]->next != nodes[1],
		"node[1]->next != node[1]");
	TEST (nodes[1]->next == nodes[2],
		"node[1]->next == node[2]");

	TEST (nodes[2]->value == CCCC,
		"node[2]->value == CCCC");
	TEST (nodes[2]->next != NULL,
		"node[2]->next != NULL");
	TEST (nodes[2]->next != nodes[2],
		"node[2]->next != nodes[1]");
	nodes[3] = nodes[2]->next;

	TEST (nodes[3]->value == DDDD,
		"node[3]->value == DDDD");
	TEST (nodes[3]->next == NULL,
		"node[3]->next == NULL");

	free (nodes[0]);
	free (nodes[1]);
	free (nodes[2]);
	free (nodes[3]);
}


////////////////////////////////////////////////////////////////////////
// four-element list: @0
static inline void
test_four_zero (
	void)
{
	list l_ = { NULL };
	list *l = &l_;
	node *nodes[5];

	l->head = nodes[1] = node_new (BBBB);
	nodes[1]->next = nodes[2] = node_new (CCCC);
	nodes[2]->next = nodes[3] = node_new (DDDD);
	nodes[3]->next = nodes[4] = node_new (EEEE);

	listInsertNth (l, 0, AAAA);

	TEST (l->head != NULL,
		"lIN ([BBBB,[CCCC,[DDDD,[EEEE,x]]]] @0, AAAA)");
	TEST (l->head != nodes[1], "l->head != [BBBB,]");
	TEST (l->head != nodes[2], "l->head != [CCCC,]");
	TEST (l->head != nodes[3], "l->head != [DDDD,]");
	TEST (l->head != nodes[4], "l->head != [EEEE,]");
	nodes[0] = l->head;

	TEST (nodes[0]->value == AAAA,
		"node[0]->value == AAAA");
	TEST (nodes[0]->next != NULL,
		"node[0]->next != NULL");
	TEST (nodes[0]->next != nodes[0],
		"node[0]->next != node[0]");
	TEST (nodes[0]->next == nodes[1],
		"node[0]->next == node[1]");

	TEST (nodes[1]->value == BBBB,
		"node[1]->value == BBBB");
	TEST (nodes[1]->next != NULL,
		"node[1]->next != NULL");
	TEST (nodes[1]->next != nodes[1],
		"node[1]->next != node[1]");
	TEST (nodes[1]->next == nodes[2],
		"node[1]->next == node[2]");

	TEST (nodes[2]->value == CCCC,
		"node[2]->value == CCCC");
	TEST (nodes[2]->next != NULL,
		"node[2]->next != NULL");
	TEST (nodes[2]->next != nodes[2],
		"node[2]->next != node[2]");
	TEST (nodes[2]->next == nodes[3],
		"node[2]->next == node[3]");

	TEST (nodes[3]->value == DDDD,
		"node[3]->value == DDDD");
	TEST (nodes[3]->next != NULL,
		"node[3]->next != NULL");
	TEST (nodes[3]->next != nodes[3],
		"node[3]->next != node[3]");
	TEST (nodes[3]->next == nodes[4],
		"node[3]->next == node[4]");

	TEST (nodes[4]->value == EEEE,
		"node[4]->value == EEEE");
	TEST (nodes[4]->next == NULL,
		"node[4]->next == NULL");

	free (nodes[0]);
	free (nodes[1]);
	free (nodes[2]);
	free (nodes[3]);
	free (nodes[4]);
}


////////////////////////////////////////////////////////////////////////
// four-element list: @1
static inline void
test_four_one (
	void)
{
	list l_ = { NULL };
	list *l = &l_;
	node *nodes[5];

	l->head = nodes[0] = node_new (AAAA);
	nodes[0]->next = nodes[2] = node_new (CCCC);
	nodes[2]->next = nodes[3] = node_new (DDDD);
	nodes[3]->next = nodes[4] = node_new (EEEE);

	listInsertNth (l, 1, BBBB);

	TEST (l->head != NULL,
		"lIN ([AAAA,[CCCC,[DDDD,[EEEE,x]]]] @1, BBBB)");
	TEST (l->head == nodes[0], "l->head == [AAAA,]");
	TEST (l->head != nodes[2], "l->head != [CCCC,]");
	TEST (l->head != nodes[3], "l->head != [DDDD,]");
	TEST (l->head != nodes[4], "l->head != [EEEE,]");

	TEST (nodes[0]->value == AAAA,
		"node[0]->value == AAAA");
	TEST (nodes[0]->next != NULL,
		"node[0]->next != NULL");
	TEST (nodes[0]->next != nodes[0],
		"node[0]->next != node[0]");
	nodes[1] = nodes[0]->next;

	TEST (nodes[1]->value == BBBB,
		"node[1]->value == BBBB");
	TEST (nodes[1]->next != NULL,
		"node[1]->next != NULL");
	TEST (nodes[1]->next != nodes[1],
		"node[1]->next != node[1]");
	TEST (nodes[1]->next == nodes[2],
		"node[1]->next == node[2]");

	TEST (nodes[2]->value == CCCC,
		"node[2]->value == CCCC");
	TEST (nodes[2]->next != NULL,
		"node[2]->next != NULL");
	TEST (nodes[2]->next != nodes[2],
		"node[2]->next != node[2]");
	TEST (nodes[2]->next == nodes[3],
		"node[2]->next == node[3]");

	TEST (nodes[3]->value == DDDD,
		"node[3]->value == DDDD");
	TEST (nodes[3]->next != NULL,
		"node[3]->next != NULL");
	TEST (nodes[3]->next != nodes[3],
		"node[3]->next != node[3]");
	TEST (nodes[3]->next == nodes[4],
		"node[3]->next == node[4]");

	TEST (nodes[4]->value == EEEE,
		"node[4]->value == EEEE");
	TEST (nodes[4]->next == NULL,
		"node[4]->next == NULL");

	free (nodes[0]);
	free (nodes[1]);
	free (nodes[2]);
	free (nodes[3]);
	free (nodes[4]);
}


////////////////////////////////////////////////////////////////////////
// four-element list: @2
static inline void
test_four_two (
	void)
{
	list l_ = { NULL };
	list *l = &l_;
	node *nodes[5];

	l->head = nodes[0] = node_new (AAAA);
	nodes[0]->next = nodes[1] = node_new (BBBB);
	nodes[1]->next = nodes[3] = node_new (DDDD);
	nodes[3]->next = nodes[4] = node_new (EEEE);

	listInsertNth (l, 2, CCCC);

	TEST (l->head != NULL,
		"lIN ([AAAA,[BBBB,[DDDD,[EEEE,x]]]] @2, CCCC)");
	TEST (l->head == nodes[0], "l->head == [AAAA,]");
	TEST (l->head != nodes[1], "l->head != [BBBB,]");
	TEST (l->head != nodes[3], "l->head != [DDDD,]");
	TEST (l->head != nodes[4], "l->head != [EEEE,]");

	TEST (nodes[0]->value == AAAA,
		"node[0]->value == AAAA");
	TEST (nodes[0]->next != NULL,
		"node[0]->next != NULL");
	TEST (nodes[0]->next != nodes[0],
		"node[0]->next != node[0]");
	TEST (nodes[0]->next == nodes[1],
		"node[0]->next == node[1]");

	TEST (nodes[1]->value == BBBB,
		"node[1]->value == BBBB");
	TEST (nodes[1]->next != NULL,
		"node[1]->next != NULL");
	TEST (nodes[1]->next != nodes[1],
		"node[1]->next != node[1]");
	nodes[2] = nodes[1]->next;

	TEST (nodes[2]->value == CCCC,
		"node[2]->value == CCCC");
	TEST (nodes[2]->next != NULL,
		"node[2]->next != NULL");
	TEST (nodes[2]->next != nodes[2],
		"node[2]->next != node[2]");
	TEST (nodes[2]->next == nodes[3],
		"node[2]->next == node[3]");

	TEST (nodes[3]->value == DDDD,
		"node[3]->value == DDDD");
	TEST (nodes[3]->next != NULL,
		"node[3]->next != NULL");
	TEST (nodes[3]->next != nodes[3],
		"node[3]->next != node[3]");
	TEST (nodes[3]->next == nodes[4],
		"node[3]->next == node[4]");

	TEST (nodes[4]->value == EEEE,
		"node[4]->value == EEEE");
	TEST (nodes[4]->next == NULL,
		"node[4]->next == NULL");

	free (nodes[0]);
	free (nodes[1]);
	free (nodes[2]);
	free (nodes[3]);
	free (nodes[4]);
}


////////////////////////////////////////////////////////////////////////
// four-element list: @3
static inline void
test_four_three (
	void)
{
	list l_ = { NULL };
	list *l = &l_;
	node *nodes[5];

	l->head = nodes[0] = node_new (AAAA);
	nodes[0]->next = nodes[1] = node_new (BBBB);
	nodes[1]->next = nodes[2] = node_new (CCCC);
	nodes[2]->next = nodes[4] = node_new (EEEE);

	listInsertNth (l, 3, DDDD);

	TEST (l->head != NULL,
		"lIN ([AAAA,[BBBB,[CCCC,[EEEE,x]]]] @3, DDDD)");
	TEST (l->head == nodes[0], "l->head == [AAAA,]");
	TEST (l->head != nodes[1], "l->head != [BBBB,]");
	TEST (l->head != nodes[2], "l->head != [CCCC,]");
	TEST (l->head != nodes[4], "l->head != [EEEE,]");

	TEST (nodes[0]->value == AAAA,
		"node[0]->value == AAAA");
	TEST (nodes[0]->next != NULL,
		"node[0]->next != NULL");
	TEST (nodes[0]->next != nodes[0],
		"node[0]->next != node[0]");
	TEST (nodes[0]->next == nodes[1],
		"node[0]->next == node[1]");

	TEST (nodes[1]->value == BBBB,
		"node[1]->value == BBBB");
	TEST (nodes[1]->next != NULL,
		"node[1]->next != NULL");
	TEST (nodes[1]->next != nodes[1],
		"node[1]->next != node[1]");
	TEST (nodes[1]->next == nodes[2],
		"node[1]->next == node[2]");

	TEST (nodes[2]->value == CCCC,
		"node[2]->value == CCCC");
	TEST (nodes[2]->next != NULL,
		"node[2]->next != NULL");
	TEST (nodes[2]->next != nodes[2],
		"node[2]->next != node[2]");
	nodes[3] = nodes[2]->next;

	TEST (nodes[3]->value == DDDD,
		"node[3]->value == DDDD");
	TEST (nodes[3]->next != NULL,
		"node[3]->next != NULL");
	TEST (nodes[3]->next != nodes[3],
		"node[3]->next != node[3]");
	TEST (nodes[3]->next == nodes[4],
		"node[3]->next == node[4]");

	TEST (nodes[4]->value == EEEE,
		"node[4]->value == EEEE");
	TEST (nodes[4]->next == NULL,
		"node[4]->next == NULL");

	free (nodes[0]);
	free (nodes[1]);
	free (nodes[2]);
	free (nodes[3]);
	free (nodes[4]);
}


////////////////////////////////////////////////////////////////////////
// four-element list: @4
static inline void
test_four_four (
	void)
{
	list l_ = { NULL };
	list *l = &l_;
	node *nodes[5];

	l->head = nodes[0] = node_new (AAAA);
	nodes[0]->next = nodes[1] = node_new (BBBB);
	nodes[1]->next = nodes[2] = node_new (CCCC);
	nodes[2]->next = nodes[3] = node_new (DDDD);

	listInsertNth (l, 4, EEEE);

	TEST (l->head != NULL,
		"lIN ([AAAA,[BBBB,[CCCC,[DDDD,x]]]] @4, EEEE)");
	TEST (l->head == nodes[0], "l->head == [AAAA,]");
	TEST (l->head != nodes[1], "l->head != [BBBB,]");
	TEST (l->head != nodes[2], "l->head != [CCCC,]");
	TEST (l->head != nodes[3], "l->head != [DDDD,]");

	TEST (nodes[0]->value == AAAA,
		"node[0]->value == AAAA");
	TEST (nodes[0]->next != NULL,
		"node[0]->next != NULL");
	TEST (nodes[0]->next != nodes[0],
		"node[0]->next != node[0]");
	TEST (nodes[0]->next == nodes[1],
		"node[0]->next == node[1]");

	TEST (nodes[1]->value == BBBB,
		"node[1]->value == BBBB");
	TEST (nodes[1]->next != NULL,
		"node[1]->next != NULL");
	TEST (nodes[1]->next != nodes[1],
		"node[1]->next != node[1]");
	TEST (nodes[1]->next == nodes[2],
		"node[1]->next == node[2]");

	TEST (nodes[2]->value == CCCC,
		"node[2]->value == CCCC");
	TEST (nodes[2]->next != NULL,
		"node[2]->next != NULL");
	TEST (nodes[2]->next != nodes[2],
		"node[2]->next != node[2]");
	TEST (nodes[2]->next == nodes[3],
		"node[2]->next == node[3]");

	TEST (nodes[3]->value == DDDD,
		"node[3]->value == DDDD");
	TEST (nodes[3]->next != NULL,
		"node[3]->next != NULL");
	TEST (nodes[3]->next != nodes[3],
		"node[3]->next != node[3]");
	nodes[4] = nodes[3]->next;

	TEST (nodes[4]->value == EEEE,
		"node[4]->value == EEEE");
	TEST (nodes[4]->next == NULL,
		"node[4]->next == NULL");

	free (nodes[0]);
	free (nodes[1]);
	free (nodes[2]);
	free (nodes[3]);
	free (nodes[4]);
}


////////////////////////////////////////////////////////////////////////
// five-element list: @0
static inline void
test_five_zero (
	void)
{
	list l_ = { NULL };
	list *l = &l_;
	node *nodes[6];

	l->head = nodes[1] = node_new (BBBB);
	nodes[1]->next = nodes[2] = node_new (CCCC);
	nodes[2]->next = nodes[3] = node_new (DDDD);
	nodes[3]->next = nodes[4] = node_new (EEEE);
	nodes[4]->next = nodes[5] = node_new (FFFF);

	listInsertNth (l, 0, AAAA);

	TEST (l->head != NULL,
		"lIN ([BBBB,[CCCC,[DDDD,[EEEE,[FFFF,x]]]]] @0, AAAA)");
	TEST (l->head != nodes[1], "l->head != [BBBB,]");
	TEST (l->head != nodes[2], "l->head != [CCCC,]");
	TEST (l->head != nodes[3], "l->head != [DDDD,]");
	TEST (l->head != nodes[4], "l->head != [EEEE,]");
	TEST (l->head != nodes[5], "l->head != [FFFF,]");
	nodes[0] = l->head;

	TEST (nodes[0]->value == AAAA,
		"node[0]->value == AAAA");
	TEST (nodes[0]->next != NULL,
		"node[0]->next != NULL");
	TEST (nodes[0]->next != nodes[0],
		"node[0]->next != node[0]");
	TEST (nodes[0]->next == nodes[1],
		"node[0]->next == node[1]");

	TEST (nodes[1]->value == BBBB,
		"node[1]->value == BBBB");
	TEST (nodes[1]->next != NULL,
		"node[1]->next != NULL");
	TEST (nodes[1]->next != nodes[1],
		"node[1]->next != node[1]");
	TEST (nodes[1]->next == nodes[2],
		"node[1]->next == node[2]");

	TEST (nodes[2]->value == CCCC,
		"node[2]->value == CCCC");
	TEST (nodes[2]->next != NULL,
		"node[2]->next != NULL");
	TEST (nodes[2]->next != nodes[2],
		"node[2]->next != node[2]");
	TEST (nodes[2]->next == nodes[3],
		"node[2]->next == node[3]");

	TEST (nodes[3]->value == DDDD,
		"node[3]->value == DDDD");
	TEST (nodes[3]->next != NULL,
		"node[3]->next != NULL");
	TEST (nodes[3]->next != nodes[3],
		"node[3]->next != node[3]");
	TEST (nodes[3]->next == nodes[4],
		"node[3]->next == node[4]");

	TEST (nodes[4]->value == EEEE,
		"node[4]->value == EEEE");
	TEST (nodes[4]->next != NULL,
		"node[4]->next != NULL");
	TEST (nodes[4]->next != nodes[4],
		"node[4]->next != node[4]");
	TEST (nodes[4]->next == nodes[5],
		"node[4]->next == node[5]");

	TEST (nodes[5]->value == FFFF,
		"node[5]->value == FFFF");
	TEST (nodes[5]->next == NULL,
		"node[5]->next == NULL");

	free (nodes[0]);
	free (nodes[1]);
	free (nodes[2]);
	free (nodes[3]);
	free (nodes[4]);
	free (nodes[5]);
}


////////////////////////////////////////////////////////////////////////
// five-element list: @1
static inline void
test_five_one (
	void)
{
	list l_ = { NULL };
	list *l = &l_;
	node *nodes[6];

	l->head = nodes[0] = node_new (AAAA);
	nodes[0]->next = nodes[2] = node_new (CCCC);
	nodes[2]->next = nodes[3] = node_new (DDDD);
	nodes[3]->next = nodes[4] = node_new (EEEE);
	nodes[4]->next = nodes[5] = node_new (FFFF);

	listInsertNth (l, 1, BBBB);

	TEST (l->head != NULL,
		"lIN ([AAAA,[CCCC,[DDDD,[EEEE,[FFFF,x]]]]] @1, BBBB)");
	TEST (l->head == nodes[0], "l->head == [AAAA,]");
	TEST (l->head != nodes[2], "l->head != [CCCC,]");
	TEST (l->head != nodes[3], "l->head != [DDDD,]");
	TEST (l->head != nodes[4], "l->head != [EEEE,]");
	TEST (l->head != nodes[5], "l->head != [FFFF,]");

	TEST (nodes[0]->value == AAAA,
		"node[0]->value == AAAA");
	TEST (nodes[0]->next != NULL,
		"node[0]->next != NULL");
	TEST (nodes[0]->next != nodes[0],
		"node[0]->next != node[0]");
	nodes[1] = nodes[0]->next;

	TEST (nodes[1]->value == BBBB,
		"node[1]->value == BBBB");
	TEST (nodes[1]->next != NULL,
		"node[1]->next != NULL");
	TEST (nodes[1]->next != nodes[1],
		"node[1]->next != node[1]");
	TEST (nodes[1]->next == nodes[2],
		"node[1]->next == node[2]");

	TEST (nodes[2]->value == CCCC,
		"node[2]->value == CCCC");
	TEST (nodes[2]->next != NULL,
		"node[2]->next != NULL");
	TEST (nodes[2]->next != nodes[2],
		"node[2]->next != node[2]");
	TEST (nodes[2]->next == nodes[3],
		"node[2]->next == node[3]");

	TEST (nodes[3]->value == DDDD,
		"node[3]->value == DDDD");
	TEST (nodes[3]->next != NULL,
		"node[3]->next != NULL");
	TEST (nodes[3]->next != nodes[3],
		"node[3]->next != node[3]");
	TEST (nodes[3]->next == nodes[4],
		"node[3]->next == node[4]");

	TEST (nodes[4]->value == EEEE,
		"node[4]->value == EEEE");
	TEST (nodes[4]->next != NULL,
		"node[4]->next != NULL");
	TEST (nodes[4]->next != nodes[4],
		"node[4]->next != node[4]");
	TEST (nodes[4]->next == nodes[5],
		"node[4]->next == node[5]");

	TEST (nodes[5]->value == FFFF,
		"node[5]->value == FFFF");
	TEST (nodes[5]->next == NULL,
		"node[5]->next == NULL");

	free (nodes[0]);
	free (nodes[1]);
	free (nodes[2]);
	free (nodes[3]);
	free (nodes[4]);
	free (nodes[5]);
}


////////////////////////////////////////////////////////////////////////
// five-element list: @2
static inline void
test_five_two (
	void)
{
	list l_ = { NULL };
	list *l = &l_;
	node *nodes[6];

	l->head = nodes[0] = node_new (AAAA);
	nodes[0]->next = nodes[1] = node_new (BBBB);
	nodes[1]->next = nodes[3] = node_new (DDDD);
	nodes[3]->next = nodes[4] = node_new (EEEE);
	nodes[4]->next = nodes[5] = node_new (FFFF);

	listInsertNth (l, 2, CCCC);

	TEST (l->head != NULL,
		"lIN ([AAAA,[BBBB,[DDDD,[EEEE,[FFFF,x]]]]] @2, CCCC)");
	TEST (l->head == nodes[0], "l->head == [AAAA,]");
	TEST (l->head != nodes[1], "l->head != [BBBB,]");
	TEST (l->head != nodes[3], "l->head != [DDDD,]");
	TEST (l->head != nodes[4], "l->head != [EEEE,]");
	TEST (l->head != nodes[5], "l->head != [FFFF,]");

	TEST (nodes[0]->value == AAAA,
		"node[0]->value == AAAA");
	TEST (nodes[0]->next != NULL,
		"node[0]->next != NULL");
	TEST (nodes[0]->next != nodes[0],
		"node[0]->next != node[0]");
	TEST (nodes[0]->next == nodes[1],
		"node[0]->next == node[1]");

	TEST (nodes[1]->value == BBBB,
		"node[1]->value == BBBB");
	TEST (nodes[1]->next != NULL,
		"node[1]->next != NULL");
	TEST (nodes[1]->next != nodes[1],
		"node[1]->next != node[1]");
	nodes[2] = nodes[1]->next;

	TEST (nodes[2]->value == CCCC,
		"node[2]->value == CCCC");
	TEST (nodes[2]->next != NULL,
		"node[2]->next != NULL");
	TEST (nodes[2]->next != nodes[2],
		"node[2]->next != node[2]");
	TEST (nodes[2]->next == nodes[3],
		"node[2]->next == node[3]");

	TEST (nodes[3]->value == DDDD,
		"node[3]->value == DDDD");
	TEST (nodes[3]->next != NULL,
		"node[3]->next != NULL");
	TEST (nodes[3]->next != nodes[3],
		"node[3]->next != node[3]");
	TEST (nodes[3]->next == nodes[4],
		"node[3]->next == node[4]");

	TEST (nodes[4]->value == EEEE,
		"node[4]->value == EEEE");
	TEST (nodes[4]->next != NULL,
		"node[4]->next != NULL");
	TEST (nodes[4]->next != nodes[4],
		"node[4]->next != node[4]");
	TEST (nodes[4]->next == nodes[5],
		"node[4]->next == node[5]");

	TEST (nodes[5]->value == FFFF,
		"node[5]->value == FFFF");
	TEST (nodes[5]->next == NULL,
		"node[5]->next == NULL");

	free (nodes[0]);
	free (nodes[1]);
	free (nodes[2]);
	free (nodes[3]);
	free (nodes[4]);
	free (nodes[5]);
}


////////////////////////////////////////////////////////////////////////
// five-element list: @3
static inline void
test_five_three (
	void)
{
	list l_ = { NULL };
	list *l = &l_;
	node *nodes[6];

	l->head = nodes[0] = node_new (AAAA);
	nodes[0]->next = nodes[1] = node_new (BBBB);
	nodes[1]->next = nodes[2] = node_new (CCCC);
	nodes[2]->next = nodes[4] = node_new (EEEE);
	nodes[4]->next = nodes[5] = node_new (FFFF);

	listInsertNth (l, 3, DDDD);

	TEST (l->head != NULL,
		"lIN ([AAAA,[BBBB,[CCCC,[EEEE,[FFFF,x]]]]] @3, DDDD)");
	TEST (l->head == nodes[0], "l->head == [AAAA,]");
	TEST (l->head != nodes[1], "l->head != [BBBB,]");
	TEST (l->head != nodes[2], "l->head != [CCCC,]");
	TEST (l->head != nodes[4], "l->head != [EEEE,]");
	TEST (l->head != nodes[5], "l->head != [FFFF,]");

	TEST (nodes[0]->value == AAAA,
		"node[0]->value == AAAA");
	TEST (nodes[0]->next != NULL,
		"node[0]->next != NULL");
	TEST (nodes[0]->next != nodes[0],
		"node[0]->next != node[0]");
	TEST (nodes[0]->next == nodes[1],
		"node[0]->next == node[1]");

	TEST (nodes[1]->value == BBBB,
		"node[1]->value == BBBB");
	TEST (nodes[1]->next != NULL,
		"node[1]->next != NULL");
	TEST (nodes[1]->next != nodes[1],
		"node[1]->next != node[1]");
	TEST (nodes[1]->next == nodes[2],
		"node[1]->next == node[2]");

	TEST (nodes[2]->value == CCCC,
		"node[2]->value == CCCC");
	TEST (nodes[2]->next != NULL,
		"node[2]->next != NULL");
	TEST (nodes[2]->next != nodes[2],
		"node[2]->next != node[2]");
	nodes[3] = nodes[2]->next;

	TEST (nodes[3]->value == DDDD,
		"node[3]->value == DDDD");
	TEST (nodes[3]->next != NULL,
		"node[3]->next != NULL");
	TEST (nodes[3]->next != nodes[3],
		"node[3]->next != node[3]");
	TEST (nodes[3]->next == nodes[4],
		"node[3]->next == node[4]");

	TEST (nodes[4]->value == EEEE,
		"node[4]->value == EEEE");
	TEST (nodes[4]->next != NULL,
		"node[4]->next != NULL");
	TEST (nodes[4]->next != nodes[4],
		"node[4]->next != node[4]");
	TEST (nodes[4]->next == nodes[5],
		"node[4]->next == node[5]");

	TEST (nodes[5]->value == FFFF,
		"node[5]->value == FFFF");
	TEST (nodes[5]->next == NULL,
		"node[5]->next == NULL");

	free (nodes[0]);
	free (nodes[1]);
	free (nodes[2]);
	free (nodes[3]);
	free (nodes[4]);
	free (nodes[5]);
}


////////////////////////////////////////////////////////////////////////
// five-element list: @4
static inline void
test_five_four (
	void)
{
	list l_ = { NULL };
	list *l = &l_;
	node *nodes[6];

	l->head = nodes[0] = node_new (AAAA);
	nodes[0]->next = nodes[1] = node_new (BBBB);
	nodes[1]->next = nodes[2] = node_new (CCCC);
	nodes[2]->next = nodes[3] = node_new (DDDD);
	nodes[3]->next = nodes[5] = node_new (FFFF);

	listInsertNth (l, 4, EEEE);

	TEST (l->head != NULL,
		"lIN ([AAAA,[BBBB,[CCCC,[DDDD,[FFFF,x]]]]] @4, EEEE)");
	TEST (l->head == nodes[0], "l->head == [AAAA,]");
	TEST (l->head != nodes[1], "l->head != [BBBB,]");
	TEST (l->head != nodes[2], "l->head != [CCCC,]");
	TEST (l->head != nodes[3], "l->head != [DDDD,]");
	TEST (l->head != nodes[5], "l->head != [FFFF,]");

	TEST (nodes[0]->value == AAAA,
		"node[0]->value == AAAA");
	TEST (nodes[0]->next != NULL,
		"node[0]->next != NULL");
	TEST (nodes[0]->next != nodes[0],
		"node[0]->next != node[0]");
	TEST (nodes[0]->next == nodes[1],
		"node[0]->next == node[1]");

	TEST (nodes[1]->value == BBBB,
		"node[1]->value == BBBB");
	TEST (nodes[1]->next != NULL,
		"node[1]->next != NULL");
	TEST (nodes[1]->next != nodes[1],
		"node[1]->next != node[1]");
	TEST (nodes[1]->next == nodes[2],
		"node[1]->next == node[2]");

	TEST (nodes[2]->value == CCCC,
		"node[2]->value == CCCC");
	TEST (nodes[2]->next != NULL,
		"node[2]->next != NULL");
	TEST (nodes[2]->next != nodes[2],
		"node[2]->next != node[2]");
	TEST (nodes[2]->next == nodes[3],
		"node[2]->next == node[3]");

	TEST (nodes[3]->value == DDDD,
		"node[3]->value == DDDD");
	TEST (nodes[3]->next != NULL,
		"node[3]->next != NULL");
	TEST (nodes[3]->next != nodes[3],
		"node[3]->next != node[3]");
	nodes[4] = nodes[3]->next;

	TEST (nodes[4]->value == EEEE,
		"node[4]->value == EEEE");
	TEST (nodes[4]->next != NULL,
		"node[4]->next != NULL");
	TEST (nodes[4]->next != nodes[4],
		"node[4]->next != node[4]");
	TEST (nodes[4]->next == nodes[5],
		"node[4]->next == node[5]");

	TEST (nodes[5]->value == FFFF,
		"node[5]->value == FFFF");
	TEST (nodes[5]->next == NULL,
		"node[5]->next == NULL");

	free (nodes[0]);
	free (nodes[1]);
	free (nodes[2]);
	free (nodes[3]);
	free (nodes[4]);
	free (nodes[5]);
}


////////////////////////////////////////////////////////////////////////
// five-element list: @5
static inline void
test_five_five (
	void)
{
	list l_ = { NULL };
	list *l = &l_;
	node *nodes[6];

	l->head = nodes[0] = node_new (AAAA);
	nodes[0]->next = nodes[1] = node_new (BBBB);
	nodes[1]->next = nodes[2] = node_new (CCCC);
	nodes[2]->next = nodes[3] = node_new (DDDD);
	nodes[3]->next = nodes[4] = node_new (EEEE);

	listInsertNth (l, 5, FFFF);

	TEST (l->head != NULL,
		"lIN ([AAAA,[BBBB,[CCCC,[DDDD,[EEEE,x]]]]] @5, FFFF)");
	TEST (l->head == nodes[0], "l->head == [AAAA,]");
	TEST (l->head != nodes[1], "l->head != [BBBB,]");
	TEST (l->head != nodes[2], "l->head != [CCCC,]");
	TEST (l->head != nodes[3], "l->head != [DDDD,]");
	TEST (l->head != nodes[4], "l->head != [EEEE,]");

	TEST (nodes[0]->value == AAAA,
		"node[0]->value == AAAA");
	TEST (nodes[0]->next != NULL,
		"node[0]->next != NULL");
	TEST (nodes[0]->next != nodes[0],
		"node[0]->next != node[0]");
	TEST (nodes[0]->next == nodes[1],
		"node[0]->next == node[1]");

	TEST (nodes[1]->value == BBBB,
		"node[1]->value == BBBB");
	TEST (nodes[1]->next != NULL,
		"node[1]->next != NULL");
	TEST (nodes[1]->next != nodes[1],
		"node[1]->next != node[1]");
	TEST (nodes[1]->next == nodes[2],
		"node[1]->next == node[2]");

	TEST (nodes[2]->value == CCCC,
		"node[2]->value == CCCC");
	TEST (nodes[2]->next != NULL,
		"node[2]->next != NULL");
	TEST (nodes[2]->next != nodes[2],
		"node[2]->next != node[2]");
	TEST (nodes[2]->next == nodes[3],
		"node[2]->next == node[3]");

	TEST (nodes[3]->value == DDDD,
		"node[3]->value == DDDD");
	TEST (nodes[3]->next != NULL,
		"node[3]->next != NULL");
	TEST (nodes[3]->next != nodes[3],
		"node[3]->next != node[3]");
	TEST (nodes[3]->next == nodes[4],
		"node[3]->next == node[4]");

	TEST (nodes[4]->value == EEEE,
		"node[4]->value == EEEE");
	TEST (nodes[4]->next != NULL,
		"node[4]->next != NULL");
	TEST (nodes[4]->next != nodes[4],
		"node[4]->next != node[4]");
	nodes[5] = nodes[4]->next;

	TEST (nodes[5]->value == FFFF,
		"node[5]->value == FFFF");
	TEST (nodes[5]->next == NULL,
		"node[5]->next == NULL");

	free (nodes[0]);
	free (nodes[1]);
	free (nodes[2]);
	free (nodes[3]);
	free (nodes[4]);
	free (nodes[5]);
}


////////////////////////////////////////////////////////////////////////
// create a node
static Node
node_new (
	int value)
{
	node *new = calloc (1, sizeof (node));
	if (new == NULL)
		err (EX_OSERR, "couldn't allocate memory");
	new->value = value;
	return new;
}