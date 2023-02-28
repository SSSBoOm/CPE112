#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char val[64];
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

int insert(queue *root, char *val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->prev = NULL;
    newNode->next = NULL;
    strcpy(newNode->val ,val);

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

int createInsertQueue(queue *root) {
    char buffer[2048];
    fgets(buffer, sizeof(buffer), stdin);
    if (buffer[strlen(buffer) - 1] == '\n')
    {
        buffer[strlen(buffer) - 1] = '\0';
    }

    char * token = strtok(buffer, " ");

    while (token != NULL)
    {
        insert(root, token);
        token = strtok(NULL , " ");
    }
    
    return 1;
}

int main()
{
    queue *root = createQueue();

    createInsertQueue(root);

    int num;
    scanf("%d", &num);

    for(int i = 0; i < num; i++) {
        if(!deleteFront(root)){
            printf("None ");
        }
    }
    printf("\n");

    return 0;
}