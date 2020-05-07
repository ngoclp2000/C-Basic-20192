#include<stdio.h>
#include<stdlib.h>
#include "tree.h"
#include<string.h>
int main(){
    tree t = createTree();
    insert(&t,100);
    insert(&t,2);
    insert(&t,3);
    insert(&t,78);
    insert(&t,34);
    printf("%d\n",search(t,100)->data);
    // char * prefix;
    // strcpy(prefix,"    ");
    // prettyPrint(t,prefix);
}