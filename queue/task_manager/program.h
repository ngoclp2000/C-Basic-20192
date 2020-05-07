#ifndef _PROGRAM_H_
#define _PROGRAM_H_

struct Program {
  int id;
  char name[100];
  int memory_capacity;
};
typedef struct Program* element_t;
struct Node {
  element_t data;
  struct Node *next;
};

#endif
