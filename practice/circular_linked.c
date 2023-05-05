#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}node;

node *insert(node *head)
{
    node *p = (node *)malloc(sizeof(node));
    printf("\nEnter the value:");
    scanf("%d",&(p->info));
    if(head == NULL)
    {
        head = p;
        p->next = head;
    }
    else
    {
        node *temp = head;
        while(temp->next!=head)
        {
            temp = temp->next;
        }
        temp->next = p;
        p->next = head;
    }
    return head;
}

void display(node *head)
{
    node *temp = head;
    printf("\nOutput : ");
    while(temp->next!=head)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("%d", temp->info);
    printf("\n");
}

int main()
{
    int opt;
    node *head=NULL;
    do
    {
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                head = insert(head);
                break;
            case 2:
                display(head);
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("\nenter tge correct option");
                break;
        }
    }while(1);
}