#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}node;

node *push(node *top)
{
    node *p = (node*)malloc(sizeof(node));
    printf("\nEnter the number:");
    scanf("%d",&(p->info));
    p->next = NULL;
    if(top == NULL)
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

node *pop(node *head)
{
    if(head == NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        node *temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

void display(node *top)
{
    node *temp = top;
    while(temp!=NULL)
    {
        printf("%d",temp->info);
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
                head = push(head);
                break;
            case 2:
                head = pop(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nenter tge correct option");
                break;
        }
    }while(1);
}