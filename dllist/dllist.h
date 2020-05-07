#ifndef _DLLIST_H_
#define _DLLIST_H_

typedef int element_t;

struct Node {
  element_t data;
  struct Node *next;
  struct Node *prev;
};

typedef struct Node* dllist;
typedef struct Node* node_t;

// create new empty list
dllist create_list();
node_t make_node(element_t x);
// check whether a list is empty
int is_empty(dllist l);

// insert new element after a specific node 
dllist insert_after(dllist l, node_t p, element_t x);

// insert new element before a specific node 
dllist insert_before(dllist l, node_t p, element_t x);

// remove an element
dllist remove_at(dllist l, node_t p);

// search
node_t find(dllist l, element_t x);

// first node
node_t first(dllist l);

// last node
node_t last(dllist l);

// nth node
node_t nth(dllist l, int n);

// length
int length(dllist l);

// free a list
void free_list(dllist l);


#endif
