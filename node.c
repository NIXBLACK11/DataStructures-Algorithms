#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info;
    struct node *next;
}node;

node *input(node *head)
{
    node *p;
    p = (node *)malloc(sizeof(node));
    int val = 0;
    printf("\nenter the value:");
    scanf("%d",&val);
    p->info=val;
    p->next=NULL;
    if(head==NULL)
    {
        head = p;
    }
    else
    {
        node *temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
    return head;
}

void display(node *head)
{
    node *temp = head;
    while(temp!=NULL)
    {
        if((temp->info)%2==0)
        {
            printf("%d",(temp->info));
        }
        temp = temp->next;
    }
}

int main()
{
    node *top;
    int ch;
    do{
        printf("\n1 for push \n 3 for display \n 4 for exit");
        printf("\n Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                top=input(top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                exit(0);
        }
    }while(1);
}