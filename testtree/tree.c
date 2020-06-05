#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"



tree createNullTree() {
  return (tree)NULL;
}

tree createTree(element_t x, tree l, tree r) {
  tree t = (tree)malloc(sizeof(struct TreeNode));
  t->data = x;
  t->left = l;
  t->right = r;

}

int isLeaf(tree t) {
  return ((t != NULL) &&
	  (t->left == NULL) &&
	  (t->right == NULL)); 
}
int isNullTree(tree t) {return t== NULL;}
int sizeOfTree(tree t) {
  if (isNullTree(t))
    return 0;
  else
    return (1 + sizeOfTree(t->left) + sizeOfTree(t->right));
}
tree createLeaf(element_t x) {
  return createTree(x, createNullTree(), createNullTree());
}
int sumOfTree(tree t) {
  if (isNullTree(t))
    return 0;
  else
    return (t->data + sumOfTree(t->left) + sumOfTree(t->right));
}

char* treeToString(tree t) {
  char *result;
  char *left;
  char *right;
  
  if (isNullTree(t)) {
    result = (char*)malloc(4);
    strcpy(result, "Nil");
    return result;
  } else {
    left = treeToString(t->left);
    right = treeToString(t->right);
    
    result = (char*)malloc(40 + strlen(left) + strlen(right));
    sprintf(result, "node(%d,%s,%s)", t->data, left, right);
    free(left);
    free(right);
    return result;
  }
}
int calcualte(int n1,int n2, char ope){
  if(ope == '+') return n1+n2;
  else if(ope == '-') return n1-n2;
  else if(ope == '*') return n1*n2;
  else{
    if (n2 != 0 ) return n1/n2;
  }
 }
int evaluate(tree t){
  if ( t == NULL) return 0;
  if(t->left == NULL && t->right == NULL) return t->data;
  int n1,n2,ope;
  if (t->left != NULL) n1 = evaluate(t->left);
  ope = (char) t->data;
  if(t->right != NULL) n2 = evaluate(t->right);
  return calcualte(n1,n2,ope);
}
// Homework: Infix to Prefix using Tree