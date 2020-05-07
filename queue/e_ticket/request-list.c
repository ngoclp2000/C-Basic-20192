#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "request.h"
#include "request_list.h"
node_t make_node(element_t x) {
  node_t n = (node_t)malloc(sizeof(struct Node));
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
list insert_before(list l, struct Node *p, element_t x) {
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
node_t find(list l, char *name) {
  node_t p = l;

  while ((p != NULL) && (strcmp(name,p->data->name) != 0))
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
  printf("%-20s%-18s%-9s%s\n","Name","Type(1.W,2.C,3.N)","Quantity","Ticket");
    while(l != NULL){
        printf("%-20s%-18d%-9d",l->data->name,l->data->seat_type,l->data->quantity);
        for(int i = 0 ; i < l->data->quantity ; i++){
          printf("%c%d ",(l->data->reserved_seats +i)->col,(l->data->reserved_seats + i)->row);
        }
        printf("\n");
        l = l->next;
    }
}