//Design, develop and execute a program in C to create a Binary tree using arrays and display the tree.


#include <stdio.h>
#define sz 100

void bt(int a[sz], int ele)
{
    int c, p, i;
    if (a[0] == '\0')
    {
        a[0] = ele;
        return;
    }

    c = 0;
    while (a[c] != '\0')
    {
        p = c;
        if (ele < a[c])
            c = 2 * c + 1;
        else
            c = 2 * c + 2;
    }

    if (ele < a[p])
        c = 2 * p + 1;
    else
        c = 2 * p + 2;
    a[c] = ele;

    printf("Constructed binary tree is\n");
    for (i = 0; i < sz; i++)
        if (a[i] != '\0')
            printf("a[%d]==>%d\n", i, a[i]);
}

int main()
{
    int n, a[sz], i, ele;
    for (i = 0; i < sz; i++)
        a[i] = '\0';

    printf("Enter the number of data to Binary Tree\n");
    scanf("%d", &n);
    printf("Enter the data to Binary Tree\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ele);
        bt(a, ele);
    }
}
