#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}node;

node* insert(node *head)
{
    node *p;
    p=(node*)malloc(sizeof(node));
    printf("enter the value:");
    int value;
    scanf("%d",&value);
    p->info=value;
    p->next=NULL;
    if(head==NULL)
    {
        head=p;
    }
    else{
        node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=p;
    }
    return head;
}

void display(node *head)
{
    node *temp=head;
    while(temp!=NULL)
    {
        printf("%d,",temp->info);
        temp=temp->next;
    }
}

positive(node *head, node **pos)
{    
    while(head!=NULL)
    {
        if(head->info > 0)
        {
            *pos = head;
            *pos = (*pos)->next;
        }
        head = head->next;
    }
}

node* negative(node *head, node **neg)
{
    while(head!=NULL)
    {
        if(head->info < 0)
        {
            *neg = head;
            *neg = (*neg)->next;
        }
        head = head->next;
    }
}

int main()
{
    node *head = NULL;
    node *pos = NULL;
    node *neg = NULL;
    int ch;
    do{
        printf("\n1 for insert \n 2 for negative, positive \n 3 for print \n 4 for exit");
        printf("\n Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                head=insert(head);
                break;
            case 2:
                negative(head, &neg);
                printf("\noutput for negative is:");
                display(neg);
                positive(head, &pos);
                printf("\noutput for positive is:");
                display(pos);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("ff");
        }
    }while(1);
}