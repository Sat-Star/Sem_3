#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *left;
    struct node *right;
};
typedef struct node *NODE;

NODE create(NODE root)
{
    NODE pres, prev, newnode;
    newnode = (NODE)malloc(sizeof(struct node));
    printf("Enter info\n");
    scanf("%d", &newnode->info);
    newnode->left = newnode->right = NULL;
    if (root == NULL)
    {
        root = newnode;
        return root;
    }

    pres = root;
    while (pres != NULL)
    {
        if (newnode->info < pres->info)
        {
            prev = pres;
            pres = pres->left;
        }

        else
        {
            prev = pres;
            pres = pres->right;
        }
    }

    if (newnode->info < prev->info)
        prev->left = newnode;
    else
        prev->right = newnode;

    return root;
}

void preorder(NODE root)
{
    if (root != NULL)
    {
        printf("%d\t", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->info);
        inorder(root->right);
    }
}

void postorder(NODE root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->info);
    }
}

int main()
{
    NODE root = NULL;
    int ch;
    for (;;)
    {
        printf("\n1.Create 2.Preorder 3.Inorder 4.Postorder\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            root = create(root);
            break;
        case 2:
            if (root == NULL)
                printf("The tree is empty\n");
            else
            {
                printf("\nPreorder traversal\n");
                preorder(root);
            }
            break;
        case 3:
            if (root == NULL)
                printf("\nThe tree is empty\n");
            else
            {
                printf("\nInorder traversal\n");
                inorder(root);
            }
            break;
        case 4:
            if (root == NULL)
                printf("\nThe tree is empty\n");
            else
            {
                printf("\nPostorder traversal\n");
                postorder(root);
            }
            break;
        default:
            exit(0);
        }
    }
}