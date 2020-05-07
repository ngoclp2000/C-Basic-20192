#include <stdio.h>
#include "stack-list.h"
#include<stdlib.h>
#include<string.h>
stack addingStack(stack stack1,stack stack2){
  stack sumStack = create_stack();
  int remainer = 0;
  while(!is_empty(stack1) && !is_empty(stack2)){
    
  }
}
int main() {
  printf("Enter the first number\n");
  char *num1 = (char*) malloc(sizeof(char) * 10000);
  scanf("%s",num1);
  printf("Enter the first number\n");
  char *num2 = (char*) malloc(sizeof(char) * 10000);
  scanf("%s",num2);
  stack stack1,stack2;
  stack1 = create_stack();
  stack2 = create_stack();
  for(int i = 0 ; i < strlen(num1) ; i++)
    push(stack1,num1[i]);
  for(int i = 0 ; i < strlen(num2) ; i++)
    push(stack1,num2[i]);
}
