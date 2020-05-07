#ifndef _STACK_ARRAY_H_
#define _STACK_ARRAY_H_

#define MAX_LEN 100

typedef char element_t;

struct Stack {
  element_t data[MAX_LEN];
  int top;
};

typedef struct Stack* stack;

// create new empty stack
stack create_stack();

int is_empty(stack s);

int is_full(stack s);

element_t top(stack s);

stack push(stack s, element_t x);

stack pop(stack s);

void free_stack(stack s);
#endif
