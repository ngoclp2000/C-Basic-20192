#ifndef _Tree_
#define _Tree_

typedef int element_t;

struct Node {
  element_t data;
  struct Node *left;
  struct Node *right;
};
typedef struct Node* tree;

tree createTree();
int isTreeEmpty(tree t);
void makeNULLTree(tree *t);
tree createNewNode(element_t x);
tree leftNode(tree t);
tree rightNode(tree t);
tree addLeftMost(tree t,element_t x);
tree addRightMost(tree t,element_t x);
int countNode(tree t);
int heightTree(tree t);
int isLeaf(tree t);
int countNode(tree t);
tree mergeTwoSubNode(tree node1,tree node2,element_t x);
tree search(tree t , element_t x);
void insert(tree *t,element_t x);
void delete(tree *t,element_t x);
void freeTree(tree *t);
tree findMin(tree t);
tree findMax(tree t);
void prettyPrint(tree t,char *prefix);
//tree Insert(tree t,element_t x);

#endif