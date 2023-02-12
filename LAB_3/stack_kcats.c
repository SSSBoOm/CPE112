#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char val[32];
    struct Node *next;
};

void push(struct Node **top, char *value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->val, value);
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

int pop(struct Node **start)
{
    struct Node *top = *start;

    *start = (*start)->next;
    free(top);
    if (*start == NULL)
    {
        return -1;
    }
    return 1;
}

char *peek(struct Node *start)
{
    return start->val;
}

void revstr(char *str1)
{
    int i, len, temp;
    len = strlen(str1);

    for (i = 0; i < len / 2; i++)
    {
        temp = str1[i];
        str1[i] = str1[len - i - 1];
        str1[len - i - 1] = temp;
    }
}

void inputData(struct Node **top1, struct Node **top2)
{
    char num1[128], num2[128];
    fgets(num1, 128, stdin);
    if (num1[strlen(num1) - 1] == '\n')
    {
        num1[strlen(num1) - 1] = '\0';
    }
    memset(num2, '\0', sizeof(num2));
    strcpy(num2, num1);
    revstr(num2);

    char *str1 = strtok(num1, " ");
    do
    {
        push(top1, str1);
        str1 = strtok(NULL, " ");
    } while (str1 != NULL);

    char *str2 = strtok(num2, " ");
    do
    {
        revstr(str2);
        push(top2, str2);
        str2 = strtok(NULL, " ");
    } while (str2 != NULL);
}

void Display(struct Node **start)
{
    while (1)
    {
        printf("%s ", peek(*start));
        if (pop(start) == -1)
            break;
    }
    printf("\n");
}

int main()
{
    struct Node *stack_forward = NULL;
    struct Node *stack_backward = NULL;

    inputData(&stack_forward, &stack_backward);

    Display(&stack_backward);
    Display(&stack_forward);
}