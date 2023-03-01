#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char val[64];
} node;

int dequeue(node *root, int *front, int *rear, int *size)
{
    if (*size <= 0)
    {
        return 0;
    }

    printf("%s ", root[(*front)++].val);
    (*size)--;

    return 1;
}

int enqueue(node *root, int *front, int *rear, int *size, int MaxSize, char *token)
{
    if (*size == MaxSize)
    {
        return 0;
    }
    int index = *front + *size;
    if (index == 100)
    {
        index = 0;
    }
    else
    {
        *rear = index;
        strcpy(root[index].val, token);
        *(size) += 1;
    }

    return 1;
}

int InsertQueue(node *root, int *front, int *rear, int *size, int MaxSize)
{
    char buffer[512];
    fgets(buffer, sizeof(buffer), stdin);
    if (buffer[strlen(buffer) - 1] == '\n')
    {
        buffer[strlen(buffer) - 1] = '\0';
    }
    char *token = strtok(buffer, " ");

    while (token != NULL)
    {
        if (*size == MaxSize)
        {
            printf("FULLqueue\n");
            break;
        }
        else
        {
            enqueue(root, front, rear, size, MaxSize, token);
        }
        token = strtok(NULL, " ");
    }

    return 1;
}

int main()
{
    int front = 0, rear = 0, size = 0, MaxSize = 0;
    node arr[100];

    char buffer[512];
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &MaxSize);

    InsertQueue(arr, &front, &rear, &size, MaxSize);

    int num;
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &num);

    for (int i = 0; i < num; i++)
    {
        if (!dequeue(arr, &front, &rear, &size))
        {
            printf("None ");
        }
    }
    printf("\n");

    InsertQueue(arr, &front, &rear, &size, MaxSize);

    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &num);

    for (int i = 0; i < num; i++)
    {
        if (!dequeue(arr, &front, &rear, &size))
        {
            printf("None ");
        }
    }
    printf("\n");

    return 0;
}