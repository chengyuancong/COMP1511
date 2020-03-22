typedef struct queue * Queue;


Queue queueCreate(int maxSize);
void enqueue(Queue q, int item);
int queueFront(Queue q);
int dequeue(Queue q);
int queueSize(Queue q);
void queueDestroy(Queue q);