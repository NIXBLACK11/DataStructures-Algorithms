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
    else
    {
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
        printf("%d",temp->info);
        temp=temp->next;
    }
}
int main()
{
    node *head = NULL;
    int ch;
    do{
        printf("\n1 for insert \n 2 for \n 3 for print \n 4 for exit");
        printf("\n Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                head=insert(head);
                printf("ff");
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