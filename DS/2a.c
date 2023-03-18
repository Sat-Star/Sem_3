#include <stdio.h>
#include <stdlib.h>
#define sz 5

// initializing front and rear values
int a[sz], f = 0, r = -1;

void insert()
{
    int item;
    if (r == sz - 1)
        printf("Queue overflow");
    else
    {
        printf("Enter the element to be inserted\n");
        scanf("%d", &item);
        r = r + 1;
        a[r] = item;
    }
}

void delete()
{
    if (f > r)
        printf("Queue underflow\n");
    else
    {
        printf("The deleted element is %d\n", a[f]);
        f = f + 1;
    }
}

void display()
{
    if (f > r)
        printf("The queue is empty\n");
    else
    {
        for (int i = f; i <= r; i++)
            printf("%d\n", a[i]);
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
            delete();
            break;
        case 3:
            display();
            break;

        default:
            exit(0);
        }
    }
}