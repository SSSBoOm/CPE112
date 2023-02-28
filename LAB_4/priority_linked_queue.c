#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int priority;
    char val[32];
    struct node *prev;
    struct node *next;
} node;

typedef struct queue
{
    int MaxPriority;
    struct node *front;
    struct node *rear;
} queue;

queue *createQueue()
{
    queue *newQueue = (queue *)malloc(sizeof(queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    newQueue->MaxPriority = 0;

    return newQueue;
}

int insert(queue *root, char *val, int pri)
{
    if (pri == -1)
    {
        pri = root->MaxPriority + 1;
    }

    node *newNode = (node *)malloc(sizeof(node));
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->priority = pri;
    strcpy(newNode->val, val);

    if (pri > root->MaxPriority)
    {
        root->MaxPriority = pri;
    }

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
    int pri = ptr->priority;
    while (ptr != NULL)
    {
        if (ptr->priority > pri)
        {
            temp = ptr;
            pri = ptr->priority;
        }
        ptr = ptr->next;
    }

    return temp;
}

int delete(queue *root)
{
    if (root->front == NULL && root->rear == NULL)
    {
        return 0;
    }
    node *delete = getNodeQueue(root->front);

    printf("%s ", delete->val);

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
        root->rear = delete->prev;
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

int createInsertQueue(queue *root)
{
    char buffer[512];
    fgets(buffer, sizeof(buffer), stdin);
    if (buffer[strlen(buffer) - 1] == '\n')
    {
        buffer[strlen(buffer) - 1] = '\0';
    }

    char *token = strtok(buffer, " ");
    int pri = atoi(strtok(NULL, " "));

    while (token != NULL)
    {
        insert(root, token, pri);
        token = strtok(NULL, " ");
        if (token == NULL)
        {
            break;
        }
        pri = atoi(strtok(NULL, " "));
    }

    return 1;
}

int main()
{
    queue *root = createQueue();

    createInsertQueue(root);

    int num;
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        if (!delete (root))
        {
            printf("None ");
            // break;
        }
    }
    printf("\n");

    return 0;
}