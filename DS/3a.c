/*Design, develop and execute a program in C to  perform  the following operation on Singly linked list
a. Insert the node at a specific location
b. Delete a node at the beginning of the list
c. Display the list*/


#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;

NODE insert(NODE first)
{
    NODE newnode, pres, prev;
    int pos, count;
    printf("Enter the position of node to be inserted\n");
    scanf("%d", &pos);

    if (first == NULL && pos != 1)
    {
        printf("Insertion not possible,invalid position\n");
        return first;
    }

    if (pos == 1)
    {
        newnode = (NODE)malloc(sizeof(struct node));
        printf("Enter the item\n");
        scanf("%d", &newnode->info);
        newnode->link = first;
        first = newnode;
        return first;
    }

    count = 1;
    pres = first;
    while (count <= pos - 1 && pres != NULL)
    {
        prev = pres;
        pres = pres->link;
        count++;
    }

    if (pres == NULL)
    {
        printf("Invalid pos\n");
        return first;
    }

    newnode = (NODE)malloc(sizeof(struct node));
    printf("Enter the item\n");
    scanf("%d", &newnode->info);
    prev->link = newnode;
    newnode->link = pres;
    first = newnode;
    return first;
}

NODE delete(NODE first)
{
    NODE temp;
    if (first == NULL)
        printf("Underflow\n");
    else
    {
        temp = first;
        printf("%d is deleted\n", temp->info);
        first = first->link;
        free(temp);
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
            temp = temp->link;
        }
    }
}

int main()
{
    NODE first=NULL;
    int ch;
    for (;;)
    {
        printf("1.Insert 2.Delete 3.Display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            first = insert(first);
            break;
        case 2:
            first = delete (first);
            break;
        case 3:
            display(first);
            break;

        default:
            exit(0);
        }
    }
}
