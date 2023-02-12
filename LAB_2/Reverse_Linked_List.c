#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

void createList(ListNode **start)
{
    char num[10];
    ListNode *newNode, *ptr;
    *start = NULL;
    scanf("%s", num);
    while (strcmp(num, "END"))
    {
        int convertedNum = atoi(num);
        newNode = (ListNode *)malloc(sizeof(ListNode));
        newNode->val = convertedNum;
        newNode->next = NULL;
        if (*start == NULL)
            *start = newNode;
        else
            ptr->next = newNode;
        ptr = newNode;
        // printf("Enter data (-1 to end): ");
        scanf("%s", num);
    }
}

void display(ListNode *start)
{
    ListNode *ptr = start;
    // printf("Data in the list: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
}

void *reverseSubLinkedList(ListNode **start)
{
    int left, right;
    scanf("%d %d", &left, &right);
    ListNode *dummy = (ListNode *)malloc(sizeof(ListNode));
    dummy->next = *start;
    ListNode *prev = dummy;
    ListNode *current = *start;
    int count = 1;
    while (count < left)
    {
        prev = prev->next;
        count++;
    }
    ListNode *begin = prev->next;
    ListNode *nextStart = begin->next;
    for (int i = 0; i < right - left; i++)
    {
        begin->next = nextStart->next;
        nextStart->next = prev->next;
        prev->next = nextStart;
        nextStart = begin->next;
    }
    *start = dummy->next;
}

int main()
{
    ListNode *ll;
    createList(&ll);
    // display(ll);
    // deleteDuplicateNumber(ll);
    // reverseLinkList(&ll);
    reverseSubLinkedList(&ll);
    display(ll);
    return 0;
}
