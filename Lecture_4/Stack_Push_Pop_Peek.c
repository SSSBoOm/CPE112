#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int val;
    struct Node *next;
};

int isEmpty(struct Node **top);
void push(struct Node **top, int value);
int pop(struct Node **top);
int top(struct Node *root);
void inputData(struct Node **top);
void Display(struct Node **root);

int isEmpty(struct Node **top)
{
    if (*top == NULL)
    {
        return 1;
    }

    return 0;
}

void push(struct Node **top, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val = value;
    newNode->next = NULL;

    if (isEmpty(top))
    {
        *top = newNode;
    }
    else
    {
        newNode->next = *top;
        *top = newNode;
    }
}

int pop(struct Node **top)
{
    if (isEmpty(top))
    {
        return -1;
    }
    struct Node *freeNode = *top;
    *top = (*top)->next;
    free(freeNode);

    return 1;
}

int top(struct Node *root)
{
    return root->val;
}

void inputData(struct Node **top)
{
    char num[128];
    fgets(num, 128, stdin);
    if (num[strlen(num) - 1] == '\n')
    {
        num[strlen(num) - 1] = '\0';
    }

    char *str = strtok(num, " ");
    do
    {
        int convertedNum = atoi(str);
        push(top, convertedNum);

        str = strtok(NULL, " ");
    } while (str != NULL);
}

void Display(struct Node **root)
{
    while (!isEmpty(root))
    {
        printf("%d ", top(*root));
        pop(root);
    }
    printf("\n");
}

int main()
{
    struct Node *top = NULL;

    inputData(&top);

    Display(&top);
}