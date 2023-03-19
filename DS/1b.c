/*Given a valid parenthesized infix arithmetic expression convert it to postfix expression.
The expression consists of single character operands and the binary operators + (plus), - (minus), * (multiply) and / (divide).*/


#include <stdio.h>
#include <string.h>

void push(char s[10], int *top, char item)
{
    *top = *top + 1;
    s[*top] = item;
}

char pop(char s[10], int *top)
{
    char item;
    item = s[*top];
    *top = *top - 1;
    return item;
}

// these are predefined values
int IPV(char ch)
{
    if (ch == '(')
        return 9;
    if (ch == ')')
        return 0;
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 3;
    return 7;
}

int SPV(char ch)
{
    if (ch == '#')
        return -1;
    if (ch == '(')
        return 0;
    if (ch == '+' || ch == '-')
        return 2;
    if (ch == '*' || ch == '/')
        return 4;
    return 8;
}

int main()
{
    char in[20], post[20], s[10];
    int top = -1, i, j = 0;
    printf("Enter the infix expression\n");
    scanf("%s", in);
    push(s, &top, '#');

    for (i = 0; i < strlen(in); i++)
    {
        while (IPV(in[i]) < SPV(s[top]))
        {
            post[j++] = pop(s, &top);
        }
        if (IPV(in[i]) > SPV(s[top]))
        {
            push(s, &top, in[i]);
        }
        else
            pop(s, &top);
    }

    // Emptying the stack until # and storing the characters in postfix string
    while (s[top] != '#')
    {
        post[j++] = pop(s, &top);
    }
    post[j] = '\0';
    printf("Postfix form is %s\n", post);
}
