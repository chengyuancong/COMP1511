// z5285978

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#endif //QUEUE_QUEUE_H

typedef struct qunode * Qunode;
typedef struct queue * Queue;



Queue queueCreate(int maxSize);
void enqueue(Queue q, int item);
int queueFront(Queue q);
int dequeue(Queue q);
int queueSize(Queue q);
void queueDestroy(Queue q);