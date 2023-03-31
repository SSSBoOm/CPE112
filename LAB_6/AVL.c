#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    int height;
    struct node *left;
    struct node *right;
} node;

int count = 0;

int height(node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

node *createNewNode(int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->val = val;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int getBalance(node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

node *rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

node *leftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

node *insertNode(node *root, int val)
{
    if (root == NULL)
        return createNewNode(val);

    if (val < root->val)
        root->left = insertNode(root->left, val);
    else if (val > root->val)
        root->right = insertNode(root->right, val);
    else
        return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && val < root->left->val)
        return rightRotate(root);

    if (balance < -1 && val > root->right->val)
        return leftRotate(root);

    if (balance > 1 && val > root->left->val)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && val < root->right->val)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

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

    node *root = NULL;
    root = insertNode(root, set1[setInt][0]);
    for (int i = 1; i < 7; i++)
    {
        root = insertNode(root, set1[setInt][i]);
    }

    return root;
}

node *searchElement(node *root, int key)
{
    count++;
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
    node *root = generateBinaryTree(1);

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
}