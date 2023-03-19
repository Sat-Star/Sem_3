/*Given a String representing a parentheses-free infix arithmetic expression, implement a program to place it in a tree in the infix form.
Assume that a variable name is a single letter. Traverse the tree to produce an equivalent postfix and prefix expression string.*/


#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<ctype.h>

struct node
{
    char info;
    struct node *left;
    struct node *right;
};typedef struct node* NODE;

struct stack{
    int top;
    NODE data[10];
};typedef struct stack STACK;


int preced(char item)
{
    switch(item)
    {
        case '^' : return 5;
        case '*' : return 4;
        case '/' : return 3;
        case '+' : return 2;
        case '-' : return 1;
        default : exit(0);
    }
}

void preorder(NODE root)
{
    if(root!=NULL)
    {
        printf("%c\t",root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%c\t",root->info);
        inorder(root->right);
    }
}

void postorder(NODE root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%c\t",root->info);
    }
}

void push(STACK *s,NODE temp)
{
    s->data[++(s->top)] = temp;
}

NODE pop(STACK *s)
{
    return (s->data[(s->top)--]);
}

NODE createnode(char item)
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->info = item;
    temp->left = temp->right = NULL;
    return temp;
}


NODE createExpTree(char expr[20])
{
    char symbol;
    int i;
    NODE temp,t,l,r;
    STACK tree,operator;
    tree.top=-1;
    operator.top = -1;

    for(i=0;expr[i]!='\0';i++)
    {
        symbol = expr[i];
        temp = createnode(symbol);
        if(isalnum(symbol))
        push(&tree,temp);
        else
        {
            while(operator.top!=-1 && preced((operator.data[operator.top]->info))>=preced(symbol))
            {
                t = pop(&operator);
                r = pop(&tree);
                l = pop(&tree);
                t->right = r;
                t->left = l;
                push(&tree,t);
            }
            push(&operator,temp);
        }
}
        while(operator.top!=-1)
        {
            t = pop(&operator);
            r = pop(&tree);
            l = pop(&tree);
            t->right=r;
            t->left=l;
            push(&tree,t);
        }
        return pop(&tree);
}

int main()
{
    NODE root = NULL;
    char expr[20];
    printf("Read expression\n");
    scanf("%s",expr);
    root = createExpTree(expr);
    printf("\nInorder\t");
    inorder(root);
    printf("\nPreorder\t");
    preorder(root);
    printf("\nPostorder\t");
    postorder(root);
}
