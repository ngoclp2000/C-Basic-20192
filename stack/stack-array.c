#include <stdio.h>
#include <stdlib.h>
#include "stack-array.h"

stack create_stack() {
  stack s = (stack)malloc(sizeof(struct Stack));
  s->top = -1;
}

int is_empty(stack s) {
  return (s->top == -1);
}

int is_full(stack s) {
  return (s->top == (MAX_LEN - 1));
}

element_t top(stack s) {
  if (s->top != -1)
    return s->data[s->top];
  else {
    printf("Stack underflow!\n");
    exit(0);
  }
}

stack push(stack s, element_t x) {
  if (s->top >= MAX_LEN) {
    printf("Stack overflow!\n");
    exit(0);
  } else {
    s->top++;
    s->data[s->top] = x;
  }
  return s;
}

stack pop(stack s) {
  if (s->top == -1) {
    printf("Stack underflow!\n");
    exit(0);
  } else {
    s->top--;
  }
  return s;
}

void free_stack(stack s) {
  free(s);
}
