#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    int height;
    struct node *left;
    struct node *right;
} node;

node *newNode(int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->height = 0;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int height(node *node)
{
    if (node == NULL)
        return 0;
    int lh = height(node->left), rh = height(node->right);
    return 1 + ((lh >= rh) ? lh : rh);
}

int fillBalancedFactor(node *root)
{
    if (root == NULL)
        return 1;

    int lh = height(root->left), rh = height(root->right);

    root->height = lh - rh;

    fillBalancedFactor(root->left);
    fillBalancedFactor(root->right);

    return 0;
}

void preOrderData(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrderData(root->left);
        preOrderData(root->right);
    }
}

void preOrderHeight(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->height);
        preOrderHeight(root->left);
        preOrderHeight(root->right);
    }
}

node *generateBinaryTree()
{
    node *root = newNode(1);

    root->left = newNode(2);

    root->left->left = newNode(3);

    // left
    root->left->left->left = newNode(4);

    root->left->left->left->left = newNode(6);

    root->left->left->left->left->left = newNode(13);

    root->left->left->left->left->right = newNode(7);

    root->left->left->left->left->left->left = newNode(14);

    root->left->left->left->left->right->left = newNode(13);
    root->left->left->left->left->right->right = newNode(8);

    root->left->left->left->left->right->left->left = newNode(14);

    root->left->left->left->left->right->right->left = newNode(13);
    root->left->left->left->left->right->right->right = newNode(9);

    root->left->left->left->left->right->right->left->left = newNode(14);

    root->left->left->left->left->right->right->right->left = newNode(13);

    root->left->left->left->left->right->right->right->left->left = newNode(14);

    root->left->left->left->left->right->right->right->right = newNode(12);

    root->left->left->left->left->right->right->right->right->right = newNode(15);

    // right
    root->left->left->right = newNode(5);

    root->left->left->right->left = newNode(10);

    root->left->left->right->left->left = newNode(13);
    root->left->left->right->left->right = newNode(11);

    root->left->left->right->left->left->left = newNode(14);

    root->left->left->right->left->right->left = newNode(13);
    root->left->left->right->left->right->right = newNode(8);

    root->left->left->right->left->right->left->left = newNode(14);

    root->left->left->right->left->right->right->left = newNode(13);
    root->left->left->right->left->right->right->right = newNode(9);

    root->left->left->right->left->right->right->left->left = newNode(14);

    root->left->left->right->left->right->right->right->left = newNode(13);
    root->left->left->right->left->right->right->right->right = newNode(12);

    root->left->left->right->left->right->right->right->left->left = newNode(14);

    root->left->left->right->left->right->right->right->right->right = newNode(15);

    return root;
}

int main()
{
    node *root = generateBinaryTree();

    fillBalancedFactor(root);

    preOrderData(root);
    printf("\n");
    preOrderHeight(root);
}