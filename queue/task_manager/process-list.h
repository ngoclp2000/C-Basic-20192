#ifndef _PROGRAM_
#define _PROGRAM_
#include<stdlib.h>
#include<string.h>
#include "program.h"

typedef struct Node* list;
typedef struct Node* node_t;

// create new empty list
list create_list();

// check whether a list is empty
int is_empty(list l);

// insert new element after a specific node 
list insert_after(list l, node_t p, element_t x);

// insert new element before a specific node 
list insert_before(list l, node_t p, element_t x);

// remove an element
list remove_at(list l, node_t p);

// search
node_t find(list l, int id);

// first node - TODO
node_t first(list l);

// last node - TODO
node_t last(list l);

// nth node - TODO
node_t nth(list l, int n);

// length - TODO
int length(list l);

// nth node - TODO
list reverse(list l);


// free a list
node_t free_list(list *l);

void printlist(list l);

#endif