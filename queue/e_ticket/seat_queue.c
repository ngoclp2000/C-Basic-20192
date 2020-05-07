#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "seat_queue.h"

queue makeNode(element_t x){
  queue n = (queue) malloc(sizeof(queue));
  struct Request *s = (struct Request *) malloc(sizeof(struct Request));
  s->reserved_seats = (struct Seat *) malloc(sizeof(struct Seat) *x->quantity);
  s->reserved_seats->col = x->reserved_seats->col;
  s->reserved_seats->row = x->reserved_seats->row;
  strcpy(s->name,x->name);
  s->quantity = x->quantity;
  for(int i = 0 ; i < x->quantity ; i++){
      (s->reserved_seats+i)->col = (x->reserved_seats +i)->col;
      (s->reserved_seats+i)->row = (x->reserved_seats +i)->row;  
  }
  s->seat_type = x->seat_type;
  n->data = s;
  n->next = NULL;
  return n;
}
queue createQueue(){
    return NULL;
}
int isEmpty(queue s){
    return s == NULL;
}
int isFull(queue s){
    queue new_node = (queue) malloc(sizeof(queue));
    return new_node == NULL;
}
queue dequeue(queue s){
    if(isEmpty(s)) return NULL;
    queue p  = s->next;
    free(s);
    return p;
}
queue enqueue(queue s,element_t x){
    if(isFull(s)) return NULL;
    queue p = makeNode(x);
    if (isEmpty(s)) {
        return p;
    }
    queue t = s;
    while(s->next != NULL) s = s->next;
    s->next = p;
    return t;
}
queue peek(queue s){
    if(isEmpty(s)) return NULL;
    return s;
}
queue freeQueue(queue *s){
    queue p;
    while ((*s) != NULL) {
        p = (*s);
        (*s) = p->next;
        free(p);
    }
    return NULL;
}
int length_q(queue s){
    int count = 0;
    while(s != NULL){
        count++;
        s = s->next;
    }
    return count;
}