#include <stdio.h>
#include "stack-list.h"
#include<stdlib.h>
#include<string.h>
int doOperator(char exp,int num1,int num2){
    switch(exp){
                case '+':
                    return num1 + num2;
                break;
                case '-':
                    return num2- num1;
                break;
                case '*':
                    return num1*num2;
                break;
                case '/':
                    return num2/num1;
                break;
    }
}
int valueOfExpression(char *exp,stack stack_num){
    element_t num1,num2;
    for(int i = 0 ; i < strlen(exp) ; i++){
        if(exp[i] > '0' && exp[i] <= '9'){
            stack_num = push(stack_num,(int)exp[i] - (int)'0');
        }else{

            if(!is_empty(stack_num)) num1 = top(stack_num);
            else{
                printf("Error Expression\n");
                free_stack(&stack_num);
                return -1;
            }
            stack_num = pop(stack_num);
            if(!is_empty(stack_num)) num2 = top(stack_num);
            else{
                printf("Error Expression\n");
                free_stack(&stack_num);
                return -1;
            }

            stack_num = pop(stack_num);
            stack_num = push(stack_num,doOperator(exp[i],num1,num2));
        }
    }
    int sum;
    if(!is_empty(stack_num)) sum = top(stack_num);
    stack_num = pop(stack_num);
    if(is_empty(stack_num)){
        return sum;
    }else{
        printf("Error Expression\n");
        free_stack(&stack_num);
        return -1;
    }
}
int main() {
  stack stack_num = create_stack();
  printf("Enter the expression\n");
  char *exp = (char *) malloc(sizeof(char)*1000);
  scanf("%s",exp);
  printf("%d\n",valueOfExpression(exp,stack_num));
}
