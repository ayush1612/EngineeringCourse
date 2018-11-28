/*This program implements a binary search tree with the inputs from the user, prints it out in 
all 3 tree traversing ways, ie preOrder, inOrder and postOrder traversals.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *left, *right;
    int data;
} node;

node *tree = NULL; //Global pointer to hold the pointer of root node

node *createNode(int data)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void createBranch(node *root, int data) //Creates a binary tree with the root given as parameter
{
    if (root == NULL) //Case for first node
    {
        root = createNode(data);
        tree = root; //Global tree pointer holds this root value as it is the first node
        return;
    }

    if (data >= root->data && root->right != NULL)
        createBranch(root->right, data);

    else if (data < root->data && root->left != NULL) //if there is an element in the left
        createBranch(root->left, data);

    else if (data >= root->data)
        root->right = createNode(data);

    else
        root->left = createNode(data);
}

void preOrderPrint(node *root)
{
    if (root != NULL)
    {
        printf("%d  ", root->data); //Root first, left element second and then right element
        preOrderPrint(root->left);
        preOrderPrint(root->right);
    }
}

void inOrderPrint(node *root)
{
    if (root != NULL)
    {
        inOrderPrint(root->left); //Left first, root second, right third.
        printf("%d  ", root->data);
        inOrderPrint(root->right);
    }
}
void postOrderPrint(node *root)
{
    if (root != NULL)
    {
        postOrderPrint(root->left); //Left first, right second, root third.
        postOrderPrint(root->right);
        printf("%d  ", root->data);
    }
}

int main()
{
    int menu, data;
    while (1)
    {
        printf("\n\n1. Insert\n");
        printf("2. Print\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &menu);

        switch (menu)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &data);
            createBranch(tree, data);
            break;
        case 2:
            printf("\nPre order: ");
            preOrderPrint(tree);
            printf("\nIn order: ");
            inOrderPrint(tree);
            printf("\nPost order: ");
            postOrderPrint(tree);
            printf("\n");
            break;

        case 3:
            exit(0);

        default:
            printf("Wrong choice\n\n");
            break;
        }
    }

    return (0);
}