#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;

NODE insert(NODE first, int num)
{
    NODE newnode;
    newnode = (NODE)malloc(sizeof(struct node));
    newnode->info = num;
    newnode->link = first;
    first = newnode;
    return first;
}

NODE addnum(NODE first, NODE second, NODE result)
{
    NODE temp1, temp2;
    int sum, carry = 0;
    temp1 = first;
    temp2 = second;

    while (temp1 != NULL && temp2 != NULL)
    {
        sum = temp1->info + temp2->info + carry;
        result = insert(result, sum % 10);
        carry = sum / 10;
        temp1 = temp1->link;
        temp2 = temp2->link;
    }

    while (temp1 != NULL)
    {
        sum = temp1->info + carry;
        result = insert(result, sum % 10);
        carry = sum / 10;
        temp1 = temp1->link;
    }

    while (temp2 != NULL)
    {
        sum = temp2->info + carry;
        result = insert(result, sum % 10);
        carry = sum / 10;
        temp1 = temp2->link;
    }

    if (carry == 1)
    {
        result = insert(result, 1);
    }
    return result;
}

void display(NODE result)
{
    NODE temp;
    if (result == NULL)
        printf("Empty\n");
    else
    {
        temp = result;
        while (temp != NULL)
        {
            printf("%d", temp->info);
            temp = temp->link;
        }
    }
}

int main()
{
    NODE fir = NULL, sec = NULL, res = NULL;
    char a[100], b[100];
    int i;
    printf("Enter the first number\n");
    scanf("%s", a);
    for (i = 0; i < strlen(a); i++)
    {
        fir = insert(fir, a[i] - '0');
    }
    printf("Enter the second number\n");
    scanf("%s", b);
    for (i = 0; i < strlen(b); i++)
    {
        sec = insert(sec, b[i] - '0');
    }
    res = addnum(fir, sec, res);
    printf("Addition is\n");
    display(res);
}