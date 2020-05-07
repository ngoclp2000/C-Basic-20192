#include<stdlib.h>
#include "tree.h"
#include<string.h>
#include<stdio.h>

// Create a new node
tree createNewNode(element_t x){
    tree n = (tree) malloc(sizeof(tree));
    if(n != NULL){
        n->data = x;
        n->left = NULL;
        n->right = NULL;
    }
    return n;
}
// Create a new tree
tree createTree(){
    return NULL;
}
// Checking whether the is empty or not
int isTreeEmpty(tree t){
    return t == NULL;
}
// Making the tree to be NULL
void makeNULLTree(tree *t){
    (*t) = NULL;
}
// Return the left node of the current node
tree leftNode(tree t){
    if(t->left != NULL) return t->left;
    else return NULL;
}
// Return the right node of the current node
tree rightNode(tree t){
    if(t->right != NULL) return t->right;
    else return NULL;
}
// Adding a new node to the left most of tree
tree addLeftMost(tree t,element_t x){
    tree n = createNewNode(x);
    if (isTreeEmpty(t)) return n;
    if(t->left == NULL){
        t->left = n;
        return t;
    }else addLeftMost(t->left,x);
}
// Adding a new node to the right most of tree
tree addRightMost(tree t,element_t x){
    tree n = createNewNode(x);
    if (isTreeEmpty(t)) return n;
    if(t->right == NULL){
        t->right = n;
        return t;
    }else addLeftMost(t->right,x);
}
int isLeaf(tree t){
    return (t->right == NULL) && (t->left == NULL);
}
int countNode(tree t){
    if (t == NULL) return 0;
    return 1 + countNode(t->left) + countNode(t->right);
}
tree mergeTwoSubNode(tree left,tree right,element_t x){
    tree n = (tree) malloc(sizeof(tree));
    if (n != NULL){
        n->data = x;
        n->left = left;
        n->right = right;
        return n;
    }
    return NULL;
}
tree search(tree t , element_t x){
    if(t == NULL) return NULL;
    else if(t->data == x) return t;
    else if(t->data > x){
        return search(t->left,x);
    }
    else{
        return search(t->right,x);
    }
}
void insert(tree *t, element_t x){
    if((*t) == NULL){
        (*t) = createNewNode(x);
        return;
    }
    else if(x < (*t)->data)
        insert(&(*t)->left,x);
    else
        insert(&(*t)->right,x);
}
// tree Insert(tree t,element_t x){
//     if(t == NULL){
//         t = createNewNode(x);
//         return t;
//     }else if(x < t->data)
//         return Insert(t->left,x);
//     else return Insert(t->right,x);
// }
void delete(tree *t,element_t x){
    if((*t) == NULL) return NULL;
    if((*t)->data == x) t = NULL;
    else if(x < (*t)->data){
        delete(&(*t)->left,x);
    }else delete(&(*t)->right,x);
}
void freeTree(tree *t){
    if((*t) != NULL){
        freeTree(&(*t)->left);
        free(&(*t)->left);
        freeTree(&(*t)->right);
        free(&(*t)->right);
        free(t);
    }
}
tree findMax(tree t){
    if(t->right == NULL) return t;
    else return findMax(t->right);
}
tree findMin(tree t){
    if(t->left == NULL) return t;
    else return findMin(t->left);
}
void prettyPrint(tree t,char *prefix){
	char *prefixend=prefix+strlen(prefix);
	if (t!=NULL){
		printf("%04d",t->data);
		if (t->left!=NULL) if (t->right==NULL){
			printf("\304");strcat(prefix,"     ");
		}
		else {
			printf("\302");strcat(prefix,"\263    ");
		}
		prettyPrint(t->left,prefix);
		*prefixend='\0';
		if (t->right!=NULL) if (t->left!=NULL){
			printf("\n%s",prefix);printf("\300");
		} else printf("\304");
		strcat(prefix,"     ");
		prettyPrint(t->right,prefix);
	}
}