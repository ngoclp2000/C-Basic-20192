#include <stdio.h>
#include "stack-list.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
char *convertInfixToPostfix(char *exp)
{
    stack stack_ope = create_stack();
    for (int i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(')
        {
            stack_ope = push(stack_ope, exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (!is_empty(stack_ope) && top(stack_ope) != '(')
            {
                putchar(top(stack_ope));
                stack_ope = pop(stack_ope);
            }
            stack_ope = pop(stack_ope);
        }
        else if (isdigit(exp[i]))
        {
            putchar(exp[i]);
        }
        else
        {
            if (is_empty(stack_ope) || rank(exp[i]) > rank(top(stack_ope)))
            {
                stack_ope = push(stack_ope, exp[i]);
            }
            else
            {
                if (rank(exp[i]) < rank(top(stack_ope)))
                {
                    while (!is_empty(stack_ope)  && top(stack_ope) != '(')
                    {
                        putchar(top(stack_ope));
                        stack_ope = pop(stack_ope);
                    }
                }else{
                    if(order(top(stack_ope)) == 'r'){

                    }
                    else{
                        while(!is_empty(stack_ope) && top(stack_ope) != '('){
                            putchar(top(stack_ope));
                            stack_ope = pop(stack_ope);
                        }
                    }
                }
                
                stack_ope = push(stack_ope, exp[i]);
            }
        }
    }

    while (!is_empty(stack_ope))
    {
        putchar(top(stack_ope));
        stack_ope = pop(stack_ope);
    }
}
int main(int argc, char *argv[])
{
    printf("Enter the expression\n");
    char *exp = (char *)calloc(sizeof(char), 1000);
    scanf("%s", exp);
    convertInfixToPostfix(exp);
}
