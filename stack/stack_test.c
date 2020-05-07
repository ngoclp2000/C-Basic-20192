#include <stdio.h>
#include "stack-list.h"
#include<stdlib.h>

int main() {
  stack s = create_stack();
  s = push(s,1);
  s = push(s,2);
  printf("%d",pop(&s)->data);
}
