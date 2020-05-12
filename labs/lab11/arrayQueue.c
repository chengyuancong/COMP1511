// z5285978

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Queue.h"
#define MAX_SIZE 100

struct queue{
    int maxsize;
    int *array[MAX_SIZE];
};

Queue queueCreate(int maxSize)
{
    Queue node = malloc(sizeof(struct queue));
    assert(node != NULL);
    node->maxsize = maxSize;
    return node;
}

void enqueue(Queue q, int item)
{
    int i = 0;
    while (q->array[i] != NULL)
    {
        i++;
    }
    if (i+1 >= q->maxsize)
    {
        fprintf(stderr,"Queue full\n");
        queueDestroy(q);
        exit(EXIT_FAILURE);
    }
    q->array[i] = malloc(sizeof(int));
    *q->array[i] = item;
}

int queueFront(Queue q)
{
    if (q->array[0] == NULL)
    {
        fprintf(stderr,"Queue empty\n");
        queueDestroy(q);
        exit(EXIT_FAILURE);
    }
    return *q->array[0];
}

int dequeue(Queue q)
{
    if (q->array[0] == NULL)
    {
        fprintf(stderr,"Queue empty\n");
        queueDestroy(q);
        exit(EXIT_FAILURE);
    }
    int i = 0, num = *q->array[0];
    int *pointer = q->array[0];
    while (q->array[i] != NULL)
    {
        q->array[i] = q->array[i + 1];
        i++;
    }
    free(pointer);
    return num;
}

int queueSize(Queue q)
{
    int i = 0;
    while (q->array[i] != NULL)
    {
        i++;
    }
    return i;
}

void queueDestroy(Queue q)
{
    while (q->array[0] != NULL)
    {
        dequeue(q);
    }
    free(q);
}