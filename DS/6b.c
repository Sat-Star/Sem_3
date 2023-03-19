/*In a payroll management system, it is required to store the employee data (Employee ID, Employee name, Login Time) as one logs in to the system.
At the end of the day, it is required to generate a report of all the employee who logged in that day in ascending order of the Employee ID.
Develop a program to generate this report.*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int eid;
    char ename[10];
    float It;
    struct node *left;
    struct node *right;
};
typedef struct node *NODE;

NODE insert(NODE root, int eid, char ename[10], float It)
{
    NODE newnode, prev, pres;
    newnode = (NODE)malloc(sizeof(struct node));
    newnode->left = newnode->right = NULL;
    newnode->eid = eid;
    strcpy(newnode->ename, ename);
    newnode->It = It;

    if (root == NULL)
    {
        root = newnode;
        return root;
    }

    pres = root;
    while (pres != NULL)
    {
        prev = pres;
        if (eid < pres->eid)
            pres = pres->left;
        else if (eid > pres->eid)
            pres = pres->right;
        else
        {
            printf("Duplicate elements not allowed\n");
            return root;
        }
    }

    if (eid < prev->eid)
        prev->left = newnode;
    else
        prev->right = newnode;

    return root;
}

void inorder(NODE root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t%s\t%.2f\n", root->eid, root->ename, root->It);
        inorder(root->right);
    }
}

int main()
{
    NODE root = NULL;
    int ch, eid;
    char ename[10];
    float It;
    for (;;)
    {
        printf("1.Insert 2.Inorder\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter employee details\n");
            printf("Employee ID\n");
            scanf("%d", &eid);
            printf("Employee name\n");
            scanf("%s", ename);
            printf("Login time\n");
            scanf("%f", &It);
            root = insert(root, eid, ename, It);
            break;
        case 2:
            if (root == NULL)
                printf("Employee details absent\n");
            else
            {
                printf("Eid\tEname\tIt\n");
                inorder(root);
            }
            break;
        default:
            exit(0);
        }
    }
}
