#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info;
    struct node *next;
}node;
node *push(node *top)
{
    node *p;
    p=(node *)malloc(sizeof(node));
    printf("enter value:");
    scanf("%d",&p->info);
    p->next=NULL;
    if(top==NULL)
    {
        top=p;
    }
    else
    {
        p->next=top;
        top=p;
    }
    return top;
}
node *pop(node *top)
{
    if(top==NULL)
    {
        printf("underflow");
    }
    else
    {
        printf("deleted:%d",top->info);
        node *temp=top;
        top=top->next;
        free(temp);
        return top;
    }
}
void display(node *top)
{  
    if(top==NULL)
    {
        printf("underflow");
    }
    else
    {
        while(top!=NULL)
        {
            printf("%d",top->info);
            top=top->next;
        }
    }
}
int main()
{
    node *top;
    int ch;
    do{
        printf("\n1 for push \n 2 for pop\n 3 for display \n 4 for exit");
        printf("\n Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                top=push(top);
                break;
            case 2:
                top=pop(top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                exit(0);
        }
    }while(1);
}