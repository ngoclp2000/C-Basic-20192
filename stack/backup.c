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
    int flag = 0;
    for (int i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(')
        {
            stack_ope = push(stack_ope, exp[i]);
            flag += 1;
        }
        else if (exp[i] == ')')
        {
            while (!is_empty(stack_ope) && top(stack_ope) != '(')
            {
                putchar(top(stack_ope));
                stack_ope = pop(stack_ope);
            }
            stack_ope = pop(stack_ope);
            flag--;
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
                if (flag > 0)
                {
                    while (!is_empty(stack_ope) && rank(top(stack_ope)) > rank(exp[i]) && top(stack_ope) != '(')
                    {
                        putchar(top(stack_ope));
                        stack_ope = pop(stack_ope);
                    }
                    stack_ope = push(stack_ope, exp[i]);
                }
                else
                {
                    while (!is_empty(stack_ope) && rank(exp[i]) <= rank(top(stack_ope)))
                    {
                        if (rank(exp[i]) == rank(top(stack_ope)))
                        {
                            if (order(top(stack_ope)) == 'l')
                            {
                                putchar(top(stack_ope));
                                stack_ope = pop(stack_ope);
                            }
                            else
                                break;
                        }
                        else
                        {
                            putchar(top(stack_ope));
                            stack_ope = pop(stack_ope);
                        }
                    }
                    stack_ope = push(stack_ope, exp[i]);
                }
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
