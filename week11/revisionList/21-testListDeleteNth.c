#include <err.h>
#include <stdlib.h>

#include "list.h"
#include "test1511.h"

static Node newNode (int n);
static void testSingleList (void);
static void testDoubleList (void);
static void testTripleList (void);

int main (void) {
    testSingleList();
    testDoubleList();
    testTripleList();
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

static void testSingleList (void) {
    List l = calloc (1, sizeof (list));
    if (l == NULL) {
        err (1, "couldn't allocate list");
    }
    
    Node n1 = newNode(17);
    
    l->head = n1;
    // head delete
    listDeleteNth (l, 0);
    
    /*
    Node n2 = newNode(42);
    Node n3 = newNode(3);

    n1->next = n2;
    n2->next = n3;

    listPrint(l);  
    listDeleteNth (l, 1);
    listPrint(l);
    Node n4 = newNode(5);
    n3->next = n4;
    listPrint(l);
    listDeleteNth (l, 2);
    listPrint(l);
    */
    free (l);
}


static void testDoubleList (void) {
    List l = calloc (1, sizeof (list));
    if (l == NULL) {
        err (1, "couldn't allocate list");
    }
    
    Node n1 = newNode(17);
    Node n2 = newNode(42);
    
    l->head = n1;
    n1->next = n2;
    
    // head delete
    listDeleteNth (l, 0);
    

    n1 = newNode(17);
    l->head = n1;
    n1->next = n2;
    
    // tail delete
    listDeleteNth (l, 1);
    
    TEST (l->head == n1,
        "2 element list @ tail: head pointer");
        
    TEST (l->head->value == 17,
        "2 element list @ tail: head value");
    
    TEST (l->head->next == NULL,
        "2 element list @ tail: head next pointer");
        
    TEST (mem_address_is_poisoned (n2),
          "checking node was freed");

    free (n1);
    free (l);
}

static void testTripleList (void) {
    List l = calloc (1, sizeof (list));
    if (l == NULL) {
        err (1, "couldn't allocate list");
    }
    
    Node n1 = newNode(17);
    Node n2 = newNode(42);
    Node n3 = newNode(3);
    
    l->head = n1;
    n1->next = n2;
    n2->next = n3;
    
    // head delete
    listDeleteNth (l, 0);
    
    TEST (l->head == n2,
        "3 element list @ head: head pointer");
        
    TEST (l->head->value == 42,
        "3 element list @ head: head value");
    
    TEST (l->head->next == n3,
        "3 element list @ head: head next pointer");
        
    TEST (l->head->next->value == 3,
        "3 element list @ head: next value");
    
    TEST (l->head->next->next == NULL,
        "3 element list @ head: NULL at end of list");
        
    TEST (mem_address_is_poisoned (n1),
          "checking node was freed");
    
    n1 = newNode (17);
    l->head = n1;
    n1->next = n2;
    
    // tail delete
    listDeleteNth (l, 2);
    
    TEST (l->head == n1,
        "3 element list @ tail: head pointer");
        
    TEST (l->head->value == 17,
        "3 element list @ tail: head value");
    
    TEST (l->head->next == n2,
        "3 element list @ tail: head next pointer");
        
    TEST (l->head->next->value == 42,
        "3 element list @ tail: next value");
    
    TEST (l->head->next->next == NULL,
        "3 element list @ tail: NULL at end of list");
        
    TEST (mem_address_is_poisoned (n3),
          "checking node was freed");
    
    n3 = newNode (3);
    n2->next = n3;
    
    // middle delete
    listDeleteNth (l, 1);
    
    TEST (l->head == n1,
        "3 element list @ middle: head pointer");
        
    TEST (l->head->value == 17,
        "3 element list @ middle: head value");
    
    TEST (l->head->next == n3,
        "3 element list @ middle: head next pointer");
        
    TEST (l->head->next->value == 3,
        "3 element list @ middle: next value");
    
    TEST (l->head->next->next == NULL,
        "3 element list @ middle: NULL at end of list");
        
    TEST (mem_address_is_poisoned (n2),
          "checking node was freed");

    free (n1);
    free (n3);
    
    free (l);
}
