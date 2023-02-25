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

int priority(char val)
{
    if (val == 'a' || val == 'A' || val == 'e' || val == 'E' || val == 'i' || val == 'I' || val == 'o' || val == 'O' || val == 'u' || val == 'U' || val == '.' || val == '!')
    {
        return 1;
    }
    return 0;
}

int insert(queue *root, char val, int *num)
{
    int pri = priority(val);
    if (pri == 0)
    {
        (*num)++;
    }
    node *newNode = (node *)malloc(sizeof(node));
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->priority = pri;
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
    node *temp = ptr;
    while (temp != NULL)
    {
        if (temp->priority == 1)
        {
            return temp;
        }

        temp = temp->next;
    }
    return ptr;
}

int delete(queue *root)
{
    if (root->front == NULL && root->rear == NULL)
    {
        return 0;
    }
    node *delete = getNodeQueue(root->front);

    printf("%c", delete->val);

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
    char str[256];

    fgets(str, sizeof(str), stdin);
    if (str[strlen(str) - 1] == '\n')
    {
        str[strlen(str) - 1] = '\0';
    }

    int num = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != ' ')
        {
            insert(root, str[i], &num);
        }
    }

    for (int i = 0; i < num; i++)
    {
        delete(root);
    }
}