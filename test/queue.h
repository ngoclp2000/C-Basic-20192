#ifndef _Queue_
#define _Queue_
#include "main.h"

struct Queue{
    element_t data;
    struct Queue *next;
};

typedef struct Queue *queue;

// create new empty stack
queue createQueue();

int isEmpty(queue s);

int isFull(queue s);

queue dequeue(queue s);

queue enqueue(queue s, element_t x);

queue peek(queue s);
queue last_q(queue s);
queue freeQueue(queue *s);

int length_q(queue s);
void printQueue(queue s);
#endif