#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char val[32];
    struct Node *next;
};

void push(struct Node **top, char value[])
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
        push(top, str);

        str = strtok(NULL, " ");
    } while (str != NULL);
}

void Display(struct Node **start, int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("%s ", peek(*start));
        if (pop(start) == -1)
        {
            if (num - i > 1)
            {
                printf("None");
            }
            break;
        }
    }
    printf("\n");
}

int main()
{
    struct Node *top = NULL;

    inputData(&top);

    int num;
    scanf("%d", &num);

    Display(&top, num);
}