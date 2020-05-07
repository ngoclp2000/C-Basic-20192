#ifndef _Queue_
#define _Queue_
#include "request_list.h"

struct Node {
  struct Request data;
  struct Node *next;
};

typedef struct Node* queue;
typedef struct Request element_t;
// create new empty stack
queue createStack();

int isEmpty(queue s);

int isFull(queue s);

queue dequeue(queue s);

queue enqueue(queue s, element_t x);

queue peek(queue s);

queue freeQueue(queue *s);
int count(queue s);
#endif