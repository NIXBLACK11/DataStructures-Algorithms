#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}node;

node *insert(node *head)
{
    node *p = (node *)malloc(sizeof(node));
    printf("\nenter the value to enter:");
    scanf("%d",&(p->info));
    p->next = NULL;
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
    }
    return head;
}

void display(node *head)
{
    printf("\nThe linked list is:");
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
    int n;
    node *head = NULL;
    node *rev = NULL;
    do
    {
        printf("\nEnter the option:");
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
                printf("\nenter the correct option");
                break;
        }
    }while(1);
}