#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *next;
} node;

node* insert(node *top)
{
    int val=0;
    node *p = (node*)malloc(sizeof(node));
    printf("Enter Value :");
    scanf("%d",&val);
    p->info = val;
    p->next = NULL;

    if(top==NULL)
    {
        top = p;
    }
    else
    {
        p->next = top;
        top = p;
    }
    return top;
}

node* delete(node *top)
{
    if(top==NULL)
    {
        printf("\nempty");
    }
    else
    {
        printf("\n%d : deleted",top->info);
        node *temp;
        temp = top;
        top = top->next;
        free(temp);
    }
    return top;
}

void display(node *top)
{
    if(top==NULL)
    {
        printf("empty");
    }
    else
    {
        while(top!=NULL)
        {
            printf("%d ",top->info);
            top = top->next;
        }
    }
}

int main()
{
    node *top;
    top = NULL;
    int i=0;
    do{
        printf("\nMenu\n1. for push \n2. for pop\n3. for display \n4. for exit");
        printf("\nEnter your choice :");
        scanf("%d", &i);
        switch (i)
        {
            case 1:
                top = insert(top);
                break;
            case 2:
                top = delete(top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nmachuda\n");
                break;
        }
    }while(1);
}
