#include <stdlib.h>
#include "dllist.h"

// create new empty list
dllist create_list() {
  //  TODO
  return NULL;
}
node_t make_node(element_t x) {
  node_t n = (node_t)malloc(sizeof(struct Node));
  n->data = x;
  n->next = NULL;
  n->prev = NULL;
  return n;
}
// check whether a list is empty
int is_empty(dllist l) {
  //  TODO
  return (l == NULL);
}


// insert new element after a specific node 
dllist insert_after(dllist l, node_t p, element_t x) {
  //  TODO
  node_t  n = make_node(x);
  if(l==NULL){
    return n;
  }else{
    n->next = p->next;
    n->prev = p;
    if(p->next != NULL) p->next->prev = n;
    p->next = n;
    return l;
  }
}


// insert new element before a specific node 
dllist insert_before(dllist l, node_t p, element_t x) {
  //  TODO
  node_t n = make_node(x);
  if(l == NULL){
    return n;
  }else if(l == p){
    l->prev = n;
    n->next = l;
    return n;
  }else{
    p->prev->next = n;
    n->prev = p->prev;
    p->prev = n;
    n->next = p;
  }
  return l;
}


// remove an element
dllist remove_at(dllist l, node_t p) {
  //  TODO
  if(l == NULL) return NULL;
  if(l == p){
    l = p->next;
    free(p);
    return l;
  }
  else{
    p->prev = p->next;
    free(p);
    return l;
  }
}


// search
node_t find(dllist l, element_t x) {
  //  TODO
  node_t p = l;
  while((p!= NULL) && (p->data != x))
    p = p->next;
  return p;
}


// first node
node_t first(dllist l) {
  //  TODO
  return l;
}


// last node
node_t last(dllist l) {
  //  TODO
   while( l->next != NULL)
      l = l->next;
  return l;
}


// nth node
node_t nth(dllist l, int n) {
  //  TODO
  while(l->next != NULL && n > 0){
    l = l->next;
    n--;
  }
  return l;
}


// length
int length(dllist l) {
  //  TODO
    int length = 0;
  while(l != NULL){
    l = l->next;
    length++;
  }
  return length;
}

// free a list
node_t free_list(dllist l) {
  //  TODO
  node_t p = l;

  while (p != NULL) {
    l = p->next;
    free(p);
    p = l;
  }
  free(l);
  return NULL;
}

