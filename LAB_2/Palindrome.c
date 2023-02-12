#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode
{
    int val;
    struct ListNode *prev;
    struct ListNode *next;
};

struct ListNode *createList(struct ListNode **root);
struct ListNode *duplicateList(struct ListNode **root, struct ListNode **dup, int i);
int PalindomeCheck(struct ListNode *root, struct ListNode *end);
void display(struct ListNode *start);
void delete(struct ListNode *start);
int count(struct ListNode *start, struct ListNode *end);

int count(struct ListNode *start, struct ListNode *end)
{
    int count = 1;
    struct ListNode *ptr = start;
    while (ptr != end)
    {
        ptr = ptr->next;
        count++;
    }
    return count;
}

struct ListNode *createList(struct ListNode **root)
{
    char temp[256];
    struct ListNode *newNode, *ptr;
    *root = NULL;
    scanf("%s", temp);
    while (strcmp(temp, "END"))
    {
        newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = atoi(temp);
        newNode->prev = NULL;
        newNode->next = NULL;

        if (*root == NULL)
        {
            *root = newNode;
        }
        else
        {
            newNode->prev = ptr;
            ptr->next = newNode;
        }
        ptr = newNode;
        scanf("%s", temp);
    }

    return newNode;
}

void display(struct ListNode *start)
{
    int count = 0;
    struct ListNode *ptr = start;
    while (ptr != NULL)
    {
        printf("%d ", ptr->val);
        count++;
        ptr = ptr->next;
    }
    if (count == 0)
    {
        printf("None");
    }
    printf("\n");
}

int PalindomeCheck(struct ListNode *root, struct ListNode *end)
{
    struct ListNode *front = root;
    struct ListNode *rear = end;
    int num = count(front, rear);
    while (num > 0)
    {
        if (front->val == rear->val)
        {
            front = front->next;
            rear = rear->prev;
        }
        else
        {
            return -1;
        }
        num -= 2;
    }

    return 1;
}

struct ListNode *duplicateList(struct ListNode **root, struct ListNode **dup, int i)
{
    struct ListNode *newNode, *ptr;
    struct ListNode *temp = *dup;
    *root = NULL;
    int count = 0;
    while (temp != NULL)
    {
        if (count != i)
        {
            newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
            newNode->val = temp->val;
            newNode->prev = NULL;
            newNode->next = NULL;

            if (*root == NULL)
            {
                *root = newNode;
            }
            else
            {
                newNode->prev = ptr;
                ptr->next = newNode;
            }
            ptr = newNode;
        }
        temp = temp->next;
        count++;
    }
    return newNode;
}

void delete(struct ListNode *start)
{
    struct ListNode *tmp;
    while (start != NULL)
    {
        tmp = start;
        start = start->next;
        free(tmp);
    }
}

int main()
{
    struct ListNode *root;

    struct ListNode *end = createList(&root);

    int lenght = count(root, end);
    int value = PalindomeCheck(root, end);

    if (value == 1)
    {
        printf("None\n");
    }
    else
    {
        int status = 1;
        for (int i = 0; i <= lenght; i++)
        {
            struct ListNode *rootdup;
            struct ListNode *enddup = duplicateList(&rootdup, &root, i);

            value = PalindomeCheck(rootdup, enddup);
            delete(rootdup);
            if (value == 1)
            {
                printf("%d\n", i);
                status = 0;
                break;
            }
        }
        if (status == 1)
        {
            printf("None\n");
        }
    }

    return 0;
}