#include<stdio.h>
#include<stdlib.h>
#include "tree.h"
#include<string.h>
int main(){
    tree t = createTree();
    insert(&t,100);
    insert(&t,50);
    insert(&t,30);
    //insert(&t,110);
    //insert(&t,105);
    //insert(&t,120);
    //insert(&t,102);
    //insert(&t,78);
    //insert(&t,34);
    //printf("%d\n",countInnerNode(t));
    t = deleteNode(t,50);
    printf("%d",t->data);
}