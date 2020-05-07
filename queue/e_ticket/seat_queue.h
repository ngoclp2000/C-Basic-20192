#ifndef _Queue_
#define _Queue_
#include "request.h"


typedef struct Node* queue;
// create new empty stack
queue createQueue();

int isEmpty(queue s);

int isFull(queue s);

queue dequeue(queue s);

queue enqueue(queue s, element_t x);

queue peek(queue s);

queue freeQueue(queue *s);
int length_q(queue s);
#endif