#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item)
{
    stack[++top] = item;
}

char pop()
{
    return stack[top--];
}

int priority(char symbol)
{
    switch (symbol)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, j;
    char item;
    for (i = 0, j = 0; i < strlen(infix); i++)
    {
        item = infix[i];
        if (item == '(')
        {
            push(item);
        }
        else if (isalnum(item))
        {
            postfix[j++] = item;
        }
        else if (item == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop();
        }
        else
        {
            while (priority(stack[top]) >= priority(item))
            {
                postfix[j++] = pop();
            }
            push(item);
        }
    }
    while (top > -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

void reverse(char expression[])
{
    int length = strlen(expression);
    int i;
    char temp;
    for (i = 0; i < length / 2; i++)
    {
        temp = expression[i];
        expression[i] = expression[length - i - 1];
        expression[length - i - 1] = temp;
    }
}

void infixToPrefix(char infix[], char prefix[])
{
    int i, j, k;
    char item;
    j = 0;
    reverse(infix);

    for (i = 0; i < strlen(infix); i++)
    {
        item = infix[i];

        if (item == ')')
        {
            push(item);
        }
        else if (item == '(')
        {
            while (stack[top] != ')')
            {
                prefix[j++] = pop();
            }
            pop();
        }
        else if (isalnum(item))
        {
            prefix[j++] = item;
        }
        else
        {
            while (top >= 0 && priority(stack[top]) > priority(item))
            {
                prefix[j++] = pop();
            }
            push(item);
        }
    }
    while (top >= 0)
    {
        prefix[j++] = pop();
    }
    prefix[j] = '\0';
    reverse(prefix);
}

int main()
{
    char infix[MAX];
    char postfix[MAX];
    char prefix[MAX];
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    infixToPrefix(infix, prefix);

    printf("%s\n", prefix);
    printf("%s\n", postfix);
    return 0;
}