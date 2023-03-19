/*Design a doubly linked list to represent sparse matrix. Each node in the list can have the row and column index of the matrix element and the value of the element.
Print the complete matrix as the output.*/


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

NODE insend(NODE first, int ele)
{
    NODE newnode, temp;
    newnode = (NODE)malloc(sizeof(struct node));
    newnode->info = ele;
    if (first == NULL)
    {
        newnode->left = newnode->right = NULL;
        first = newnode;
        return first;
    }

    newnode->right = NULL;
    temp = first;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    temp->right = newnode;
    newnode->left = temp;
    return first;
}

NODE remov(NODE first, NODE second)
{
    NODE temp = first;
    while (temp != NULL)
    {
        if (temp->info != 0)
            second = insend(second, temp->info);
        temp = temp->right;
    }
    return second;
}

void display(NODE first)
{
    NODE temp = first;
    while (temp != NULL)
    {
        printf("%d\t", temp->info);
        temp = temp->right;
    }
}

int main()
{
    NODE first = NULL, second = NULL;
    int m, n, i, j, ele;
    printf("Enter the size of matrix\n");
    scanf("%d%d", &m, &n);
    printf("Enter the elements of matrix\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &ele);
            first = insend(first, ele);
        }
    }
    printf("Contents of matrix are\n");
    display(first);
    printf("\nSparse matrix is\n");
    second = remov(first, second);
    display(second);
}
