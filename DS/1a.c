#include <stdio.h>
// initializing variables
int stack[100], top = -1, n, choice, x, i;

// function to push item into stack
void push()
{
    if (top >= n - 1)
        printf("Stack overflow\n");
    else
    {
        printf("Enter the value to be pushed\n");
        scanf("%d", &x);
        stack[++top] = x;
    }
}

// function to delete the last element of stack
void pop()
{
    if (top <= -1)
        printf("Stack overflow\n");
    else
        printf("%d deleted\n", stack[top--]);
}

// function to display the elements of stack
void display()
{
    if (top >= 0) // if stack is not empty
    {
        printf("The elements of stack are\n");
        for (i = 0; i <= top; i++)
            printf("%d\n", stack[i]);
    }
    else
    {
        printf("The stack is empty\n");
    }
}

int main()
{
    printf("Enter the size of stack\n");
    scanf("%d", &n);
    for (;;)
    {
        printf("1.Insert 2.Delete 3.Display\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;

        default:
            printf("Invalid choice\n");
        }
    }
}