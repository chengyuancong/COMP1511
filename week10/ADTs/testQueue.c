#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Queue.h"

void simpleTests(void);
void stressTests(void);

int main(int argc, char * argv[]){

    //Turn output buffering off, to make sure our printfs
    //are output incase the program terminates abnormally.
    //Only use this in testing.
    setbuf(stdout,NULL);
    simpleTests();
    stressTests();
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
    item = dequeue(q);
    assert(queueSize(q) == 0);
    assert(item == 11);    
    printf("passed\n");
    
    printf("Interleaving enqueues and dequeues: ");
    // q: 99
    enqueue(q, 99);
    assert(queueSize(q) == 1);
    assert(queueFront(q) == 99);
    // q: 99,98
    enqueue(q, 98);
    assert(queueSize(q) == 2);
    assert(queueFront(q) == 99);
    // q: 98
    item = dequeue(q);
    assert(queueSize(q) == 1);
    assert(queueFront(q) == 98);
    assert(item == 99);
    // q: 98 97
    enqueue(q, 97);
    assert(queueSize(q) == 2);
    assert(queueFront(q) == 98);
    // q: 97
    item = dequeue(q);
    assert(queueSize(q) == 1);
    assert(item == 98);
    assert(queueFront(q) == 97);
    // q: 
    item = dequeue(q);
    assert(queueSize(q) == 0);
    assert(item == 97);  
    //Check it still works to enqueue and deqeue after emptying the queue
    // q: -9
    enqueue(q, -9);
    assert(queueSize(q) == 1);
    assert(queueFront(q) == -9);
    // q: 
    item = dequeue(q);
    assert(queueSize(q) == 0);
    assert(item == -9); 
    printf("passed\n");
 
    //There is no assert based test you can use to check queueDestroy
    //You simply need to make sure you call the function and then compile and run using dcc --leak-check
    //to make sure the memory was freed and there were no run-time errors. 
    queueDestroy(q);
}

void stressTests(void){
   int maxSize = 100;
   printf("Enqueue %d items: ",maxSize);
   Queue q = queueCreate(maxSize);

   for(int i = 0; i < maxSize; i++){
        enqueue(q,i);
        assert(queueSize(q) == i+1);
        assert(queueFront(q) == 0);
   } 
   printf("passed\n");
   printf("Dequeue %d items: ",maxSize);
   for(int i = 0; i < maxSize; i++){
        int item = dequeue(q);
        assert(item == i);
        assert(queueSize(q) == maxSize - i - 1);
        if( i != maxSize -1){
            assert(queueFront(q) == i+1);
        }
   } 
   printf("passed\n");
   queueDestroy(q);
}