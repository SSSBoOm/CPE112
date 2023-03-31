#include <stdio.h>
#include <stdlib.h>
#define COUNT 5

typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
} node;

node *createNewNode(int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

node *insertNode(node *root, int val)
{
    if (root == NULL)
        return createNewNode(val);

    if (val < root->val)
        root->left = insertNode(root->left, val);
    else if (val > root->val)
        root->right = insertNode(root->right, val);

    return root;
}

void preorder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

node *generateBinaryTree(int setInt)
{
    int set1[3][7] = {{30, 25, 12, 28, 40, 32, 41},
                      {40, 32, 30, 25, 12, 28, 41},
                      {41, 40, 32, 30, 28, 25, 12}};

    node *root = insertNode(root, set1[setInt][0]);
    for (int i = 1; i < 7; i++)
    {
        insertNode(root, set1[setInt][i]);
    }

    return root;
}

node *searchElement(node *root, int key)
{
    if (root == NULL || root->val == key)
        return root;

    if (root->val < key)
        return searchElement(root->right, key);

    return searchElement(root->left, key);
}

void displayTree(node *root, int space, int height)
{
    if (root == NULL)
    {
        return;
    }

    space += height;

    displayTree(root->right, space, 10);
    printf("\n");

    for (int i = height; i < space; i++)
    {
        printf(" ");
    }
    printf("%d", root->val);

    printf("\n");
    displayTree(root->left, space, 10);
}

int main()
{
    node *root = generateBinaryTree(0);

    preorder(root);
    printf("\n");

    node *search = searchElement(root, 12);

    if (search != NULL)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    displayTree(root, 0, 10);

    return 0;
}