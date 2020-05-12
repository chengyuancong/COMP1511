// z5285978

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Queue.h"

void simpleTests(void);

int main(int argc, char * argv[]){

    //Turn output buffering off, to make sure our printfs
    //are output incase the program terminates abnormally.
    //Only use this in testing.
    setbuf(stdout,NULL);
    simpleTests();

    //Ideas for more tests
    //Interleave enqueue and dequeue calls
    //Make a big queue and use a loop to fill the queue up
    //Make another loop to empty the queue again etc.
    printf("All passed\n");
    return EXIT_SUCCESS;
}

void simpleTests(void){
    Queue q;
    q = queueCreate(10);

    printf("Testing empty queue: ");
    assert (q != NULL);
    assert (queueSize(q) == 0);
    printf("passed\n");

    printf("Testing enqueues: ");
    enqueue(q, 10);
    assert(queueSize(q) == 1);
    assert(queueFront(q) == 10);
    enqueue(q, 11);
    assert(queueSize(q) == 2);
    assert(queueFront(q) == 10);
    printf("passed\n");

    printf("Testing dequeues: ");
    int item = dequeue(q);
    assert(queueSize(q) == 1);
    assert(item == 10);
    assert(queueFront(q) == 11);
    printf("passed\n");

    printf("Interleaving enqueues and dequeues: ");
    enqueue(q, 99);
    assert(queueSize(q) == 2);
    assert(queueFront(q) == 11);
    enqueue(q, 23);
    assert(queueSize(q) == 3);
    assert(queueFront(q) == 11);
    item = dequeue(q);
    assert(queueSize(q) == 2);
    assert(item == 11);
    assert(queueFront(q) == 99);
    item = dequeue(q);
    assert(queueSize(q) == 1);
    assert(item == 99);
    assert(queueFront(q) == 23);
    item = dequeue(q);
    assert(queueSize(q) == 0);
    assert(item == 23);
    printf("passed\n");

    //There is no assert based test you can use to check queueDestroy
    //You simply need to make sure you call the function and then compile and run using dcc --leak-check
    //to make sure the memory was freed and there were no run-time errors.
    queueDestroy(q);
}
