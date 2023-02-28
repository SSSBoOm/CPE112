#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char val[32];
    struct node *prev;
    struct node *next;
} node;

typedef struct queue
{
    int Queue;
    int MaxQueue;
    struct node *front;
    struct node *rear;
} queue;

queue *createQueue()
{
    queue *newQueue = (queue *)malloc(sizeof(queue));
    newQueue->Queue = 0;
    newQueue->MaxQueue = 0;
    newQueue->front = NULL;
    newQueue->rear = NULL;

    return newQueue;
}

int insert(queue *root, char *val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->prev = NULL;
    newNode->next = NULL;
    strcpy(newNode->val, val);

    root->Queue += 1;

    if (root->front == NULL && root->rear == NULL)
    {
        root->front = newNode;
        root->rear = newNode;
    }
    else
    {
        newNode->prev = root->rear;

        (root->rear)->next = newNode;
        root->rear = newNode;
    }
    return 1;
}

int deleteFront(queue *root)
{
    if (root->front == NULL && root->rear == NULL)
    {
        return 0;
    }
    node *delete = root->front;

    printf("%s ", delete->val);

    root->Queue -= 1;

    if (delete->next == NULL)
    {
        root->front = NULL;
        root->rear = NULL;
    }
    else
    {
        root->front = (root->front)->next;
    }

    free(delete);

    return 1;
}

int createInsertQueue(queue *root)
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
        if (root->Queue == root->MaxQueue)
        {
            printf("FULLqueue\n");
            break;
        }
        insert(root, token);
        token = strtok(NULL, " ");
    }

    return 1;
}

int main()
{
    queue *root = createQueue();

    int max;
    char buffer[512];
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &max);

    root->MaxQueue = max;

    createInsertQueue(root);

    int num;
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &num);

    for (int i = 0; i < num; i++)
    {
        if (!deleteFront(root))
        {
            printf("None ");
        }
    }
    printf("\n");

    createInsertQueue(root);

    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &num);

    for (int i = 0; i < num; i++)
    {
        if (!deleteFront(root))
        {
            printf("None ");
        }
    }
    printf("\n");

    return 0;
}