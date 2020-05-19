#ifndef _STACK_LIST_H_
#define _STACK_LIST_H_
#include "main.h"

struct Node {
  element_t data;
  struct Node *next;
};

typedef struct Node* stack;

// create new empty stack
stack create_stack();

int is_empty(stack s);

int is_full(stack s);

element_t top(stack s);

stack push(stack s, element_t x);

stack pop(stack s);

void free_stack(stack *s);
#endif
