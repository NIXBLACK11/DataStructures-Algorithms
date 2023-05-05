#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *next;
    struct node *prev;
}node;

node *insert(node *head)
{
    node *p = (node *)malloc(sizeof(node));
    printf("\nenter the value to enter:");
    scanf("%d",&(p->info));
    p->next = NULL;
    p->prev = NULL;
    if(head == NULL)
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
        p->prev = temp;
    }
    return head;
}

void display(node *head)
{
    node *temp = head;
    while(temp!=NULL)
    {
        printf("%d,",temp->info);
        temp = temp->next;
    }
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