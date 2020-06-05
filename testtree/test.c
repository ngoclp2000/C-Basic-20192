#include <stdio.h>
#include "tree.h"
#include "../stack/stack-list.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int rank(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '^':
        return 3;
        break;
    default:
      return 0;
      break;
    }
}
char order(char c)
{
    switch (c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        return 'l';
        break;
    default:
        return 'r';
        break;
    }
}
int isOpe(char c){
  return c == '*' || c == '/' || c == '+' || c == '-';
}
tree createTreeExpression(char *exp,stack stack_ope,stack stack_num)
{
    tree t = NULL;

    for(int i = 0 ; i < strlen(exp) ; i++){

      if(exp[i] >= '0' && exp[i] <='9')
        stack_num = push(stack_num,exp[i]);
      else if (isOpe(exp[i])){
          if(isEmpty(stack_ope) || rank(exp[i] > rank(top(stack_ope))))
            stack_ope = push(stack_ope,exp[i]);
          else{

          }
      }

    }
}
int main() { 
  tree t = NULL;
  stack stack_ope = create_stack();
  stack stack_num = create_stack();
  
}