#include <stdlib.h>
#include <stdio.h>
#include  "Queue.h"

struct queue{
    int * items;
    int maxSize;
    int size;  
};

Queue queueCreate(int maxSize){
    Queue q = malloc(sizeof(struct queue));
    if(q == NULL){
        fprintf(stderr,"Insufficient Memory\n");
        exit(EXIT_FAILURE);
    }
    q->items = malloc(sizeof(int) * maxSize);
    if(q->items == NULL){
        fprintf(stderr,"Insufficient Memory\n");
        exit(EXIT_FAILURE);
    }
    q->size = 0;
    q->maxSize = maxSize;
    return q;
}

void enqueue(Queue q, int item){
    if(q->size < q->maxSize){
        q->items[q->size] = item;
        q->size++;
    } else {
        fprintf(stderr,"Queue full\n");
        queueDestroy(q);
        exit(EXIT_FAILURE);
    }
}

int queueFront(Queue q){
    if(q->size == 0){       
        fprintf(stderr,"Queue empty\n");
        queueDestroy(q);
        exit(EXIT_FAILURE);
    }
    return q->items[0];
}

int dequeue(Queue q){
    if(q->size == 0){
        fprintf(stderr,"Queue empty\n");
        queueDestroy(q);
        exit(EXIT_FAILURE);
    }
    int item =  q->items[0];
    for(int i = 1; i < q->maxSize;i++){
        q->items[i-1] = q->items[i];
    }
    q->size--;
    return item;
}

int queueSize(Queue q){
    return q->size;
}
void queueDestroy(Queue q){
    free(q->items);
    free(q);
}