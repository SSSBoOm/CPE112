#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

void display(struct ListNode *start);
void deleteEnd(struct ListNode **start);
void createList(struct ListNode **root);

void deleteEnd(struct ListNode **start)
{
    struct ListNode *ptr = *start, *preptr;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;

    free(ptr);
}

void createList(struct ListNode **root)
{
    char temp[256];
    struct ListNode *newNode, *ptr;
    *root = NULL;
    scanf("%s", temp);
    while (strcmp(temp, "END"))
    {
        newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = atoi(temp);
        newNode->next = NULL;

        if (*root == NULL)
        {
            *root = newNode;
        }
        else
        {
            ptr->next = newNode;
        }
        ptr = newNode;
        scanf("%s", temp);
    }
}

int removeList(struct ListNode **root)
{
    struct ListNode *current = *root;
    struct ListNode *next;
    struct ListNode *preptr;

    if (current == NULL)
        return 1;

    while (current->next != NULL)
    {
        if (current->val == current->next->val)
        {
            int temp = current->val;
            next = current;
            while (next->val == temp)
            {
                next = current->next->next;
                free(current->next);
                current->next = next;
                if (current->next == NULL)
                    break;
            }

            if (current == *root)
            {
                if (current->next == NULL)
                {
                    *root = NULL;
                    free(current);
                    return 1;
                }
                else
                {
                    *root = current->next;
                    free(current);
                    current = *root;
                }
            }
            else if (current->next == NULL)
            {
                preptr->next = NULL;
                free(current);
                return 1;
            }
            else
            {
                next = current;
                current = next->next;
                preptr->next = current;
                free(next);
            }
        }
        else
        {
            preptr = current;
            current = current->next;
        }
    }
    return 1;
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

int main()
{
    struct ListNode *root;

    createList(&root);

    removeList(&root);

    display(root);
    return 0;
}