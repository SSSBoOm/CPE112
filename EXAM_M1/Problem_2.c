#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    char val;
    struct stack *next;
}stack;

void push(stack **top, char value)
{
    stack *newNode = (stack *)malloc(sizeof(stack));
    newNode->val = value;
    newNode->next = NULL;

    if (*top == NULL)
    {
        *top = newNode;
    }
    else
    {
        newNode->next = *top;
        *top = newNode;
    }
}

char pop(stack **top)
{
    if (*top == NULL)
    {
        return 0;
    }
    stack *freeNode = *top;
    char temp = freeNode->val;
    *top = (*top)->next;
    free(freeNode);

    return temp;
}

void makePalindrome(stack **s1, stack **s2) {
    while (*s2 != NULL)
    {
        char temp = pop(s2);
        push(s1, temp);
    }
}

int main()
{
    stack *s1 = NULL;
    stack *s2 = NULL;

    char str[256];
    scanf("%s", str);

    for(int i = 0; i < strlen(str); i++) {
        push(&s1, str[i]);
        push(&s2, str[i]);
    }
    if(strlen(str) % 2 == 0)
        pop(&s2);

    makePalindrome(&s1, &s2);

    while(s1 != NULL) {
        printf("%c",pop(&s1));
    }
}