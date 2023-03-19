/*Design, develop and execute a program in C to implement a doubly linked list where each node consists of integers.
The program should support the following operations:
a.Create a doubly linked list by adding each node at the front
b.Delete the node of a given data If it is found, otherwise display appropriate message
c.Display the contents of the list.*/


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

NODE insfront(NODE first)
{
    NODE newnode;
    newnode = (NODE)malloc(sizeof(struct node));
    printf("Enter the info to newnode\n");
    scanf("%d", &newnode->info);
    newnode->left = NULL;
    newnode->right = first;
    first = newnode;
    return first;
}

NODE delinfo(NODE first)
{
    int key;
    NODE pres, prev;
    if (first == NULL)
    {
        printf("List is empty\n");
        return first;
    }
    printf("Enter the info to be deleted\n");
    scanf("%d", &key);

    if (key == first->info)
    {
        pres = first;
        first = first->right;
        free(pres);
        return first;
    }

    pres = first;
    while (pres != NULL && key != pres->info)
    {
        prev = pres;
        pres = pres->right;
    }

    if (pres == NULL)
    {
        printf("Key not found\n");
        return first;
    }
    else
    {
        prev->right = pres->right;
        pres->right->left = prev;
        free(pres);
        return first;
    }
}

void display(NODE first)
{
    NODE temp;
    if (first == NULL)
        printf("List is empty\n");
    else
    {
        temp = first;
        while (temp != NULL)
        {
            printf("%d\n", temp->info);
            temp = temp->right;
        }
    }
}

int main()
{
    NODE first = NULL;
    int ch;
    for (;;)
    {
        printf("1.Insert 2.Delete 3.Display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            first = insfront(first);
            break;
        case 2:
            first = delinfo(first);
            break;
        case 3:
            display(first);
            break;

        default:
            exit(0);
        }
    }
}
