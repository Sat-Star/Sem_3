/*Simulate the working of Messaging System in which a message is placed in a circular Queue by a Message Sender,
a message is removed from the circular queue by a Message Receiver, which can also display the contents of the Queue.*/


#include <stdio.h>
#include <stdlib.h>
#define sz 5

char q[sz][1000];
int f = 0, r = -1, count = 0;

void insert()
{
    if (count == sz)
        printf("Queue overflow\n");
    else
    {
        printf("Enter the element\n");
        r = (r + 1) % sz;
        scanf("%s", q[r]);
        count++;
    }
}

void delete()
{
    if (f > r)
        printf("Queue underflow\n");
    else
    {
        printf("%s deleted from queue\n", q[f]);
        f = f + 1;
    }
}

void display()
{
    int i, j;
    if (count == 0)
        printf("Queue is empty\n");
    else
    {
        printf("Contents of the queue are\n");
        j = f;
        for (i = j; i <= count; i++)
        {
            printf("%s\n", q[j]);
            j = (j + 1) % sz;
        }
    }
}

int main()
{
    int ch;
    for (;;)
    {
        printf("1.Insert 2.Delete 3.Display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        default:
            exit(0);
        }
    }
}
