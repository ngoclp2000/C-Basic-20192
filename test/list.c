#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "list.h"

node_t make_node(node_t x) {
  node_t n = (node_t) malloc(sizeof(struct Node));
  return n;
}

// create new empty list
list create_list() {
  return NULL;
}

// check whether a list is empty
int is_empty(list l) {
  return (l == NULL);
}


// insert new element after a specific node 
list insert_after(list l, struct Node *p, node_t x) {
  node_t n = make_node(x);
  if (l == NULL) {
    return n;
  } else {
    n->next = p->next;
    p->next = n;
    return l;
  }
}

// insert new element before a specific node 
list insert_before(list l, struct Node *p, node_t x) {
  node_t n = make_node(x);
  node_t prev;
  
  if (l == NULL) {
    return n;
  } else if (l == p) {
    n->next = l;
    return n;
  } else {
    for (prev = l; prev->next != p; prev = prev->next);
    n->next = p;
    prev->next = n;
    return l;
  }
}

// remove an element
list remove_at(list l, struct Node *p) {
  node_t prev;
  
  if (l == NULL)
    return NULL;
  else if (l == p) {
    l = p->next;
    free(p);
    return l;
  } else {
    for (prev = l; prev->next != p; prev = prev->next);
    prev->next = p->next;
    free(p);
    return l;
  }
}

// search
node_t find(list l, node_t x) {
  node_t p = l;

}

// free a list
void free_list(list *l) {
  node_t p = *l;

  while (p != NULL) {
    *l = p->next;
    free(p);
    p = *l;
  }
}

node_t first(list l){
  return l;
}
node_t last(list l){
  while( l->next != NULL)
      l = l->next;
  return l;
}
node_t nth(list l,int n){
  while(l->next != NULL && n > 0){
    l = l->next;
    n--;
  }
  return l;
}
int length(list l){
  int length = 0;
  while(l != NULL){
    l = l->next;
    length++;
  }
  return length;
}