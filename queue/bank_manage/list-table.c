#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "main.h"
#include "list-table.h"

node_t make_node(element_t x) {
  node_t n = (struct Table*)malloc(sizeof(struct Table));
  n->data = (struct Guest*) malloc(sizeof(struct Guest));
  n->Guests = NULL;
  n->data = x;
  n->next = NULL;
  return n;
}
list create_list(){
    return NULL;
}
int is_empty(list l){
    return l == NULL;
}
list insert_after(list l, node_t p, element_t x){
  node_t n = make_node(x);
  if (l == NULL) {
    return n;
  } else {
    n->next = p->next;
    p->next = n;
    return l;
  }
}
list insert_before(list l, struct Table *p, element_t x) {
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
list remove_at(list l, struct Table *p) {
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
node_t find(list l,int id) {
  node_t p = l;

  while ((p != NULL) && p->data->num_table != id)
    p = p->next;

  return p;
}
int length(list l){
  int length = 0;
  while(l != NULL){
    l = l->next;
    length++;
  }
  return length;
}
void printlist(list l){
    
}
node_t free_list(list *l){
    node_t q;
    while((*l) != NULL){
        q = (*l)->next;
        free((*l));
        (*l)  = q;
    }
    return NULL;
}