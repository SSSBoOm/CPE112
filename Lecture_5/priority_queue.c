#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int priority;
    char val;
    struct node *prev;
    struct node *next;
} node;

typedef struct queue
{
    struct node *front;
    struct node *rear;
} queue;

queue *createQueue()
{
    queue *newQueue = (queue *)malloc(sizeof(queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;

    return newQueue;
}

int priority()
{
    // return priority
    return 1;
}

int insert(queue *root, char val, int *num)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->priority = priority();
    newNode->val = val;

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

node *getNodeQueue(node *ptr)
{
    // return node node best priority
    return ptr;
}

int delete(queue *root)
{
    if (root->front == NULL && root->rear == NULL)
    {
        return 0;
    }
    node *delete = getNodeQueue(root->front);

    if (delete == root->front)
    {
        if (delete->next == NULL)
        {
            root->front = NULL;
            root->rear = NULL;
        }
        else
        {
            root->front = (root->front)->next;
        }
    }
    else if (delete == root->rear)
    {
        (delete->prev)->next = NULL;
    }
    else
    {
        (delete->prev)->next = delete->next;
        (delete->next)->prev = delete->prev;
    }
    free(delete);

    return 1;
}

int main()
{
    queue *root = createQueue();
}