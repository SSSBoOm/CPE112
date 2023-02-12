#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}node;

void createList(node **start) {
    int num;
    node *newNode, *ptr;
    *start = NULL;

    printf("Enter data (-1 to end):");
    scanf("%d",&num);
    while(num != -1){
        newNode = (node *)malloc(sizeof(node));
        newNode->data = num;
        newNode->next = NULL;

        if(*start == NULL){
            *start = newNode;
        }else{
            ptr->next = newNode;
            
        }
        ptr = newNode;
        printf("Enter data (-1 to end):");
        scanf("%d",&num);
    }
}

void display(node *start) {
    node *ptr = start;
    printf("Data in the list: ");
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

}

void insertBegin(node **start) {
    node *newNode;
    int val;

    printf("Enter data : ");
    scanf("%d",&val);

    newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = *start;

    *start = newNode;
}

void insertEnd(node **start) {
    node *newNode, *ptr = *start;
    int val;

    printf("Enter data : ");
    scanf("%d",&val);

    newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = newNode;
}

void deleteBegin(node **start) {
    node *ptr = *start;
    *start = (*start)->next;
 
    free(ptr);
}

void deleteEnd(node **start) {
    node *ptr = *start, *preptr;
    while (ptr->next != NULL) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;

    free(ptr);
    
}

int main() {
    node *head;
    createList(&head);
    display(head);

    // insertBegin(&head);
    // insertEnd(&head);
    // deleteBegin(&head);
    display(head);

    return 0;
}