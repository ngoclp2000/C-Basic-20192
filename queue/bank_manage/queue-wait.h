#ifndef _Queue_
#define _Queue_
#include "main.h"


struct TableQ{
    element_t data;
    struct TableQ *next;
};

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