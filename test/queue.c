#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "queue.h"

queue makeNode(element_t x){
  queue n = (queue) malloc(sizeof(queue));
  n->data = x;
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
    free((void *) s);
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
void printQueue(queue s){
   
}
queue last_q(queue s){
    while(s->next != NULL) s = s->next;
    return s;
}