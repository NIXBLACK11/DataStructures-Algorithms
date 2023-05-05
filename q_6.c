#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node * next;
    struct node * prev;
}node;

node *insert(node *head)
{
    node *p;
    p = (node*)malloc(sizeof(node));
    printf("\nEnter the value:");
    int val;
    scanf("%d",&val);
    p->info = val;
    p->next = NULL;
    p->prev = NULL;

    if(head==NULL)
    {
        head = p;
    }
    else
    {
        node *temp = head;
        while(1)
        {
            if(temp->info < val && temp->next->info > val)
            {
                node *t = temp->next;
                temp->next = p;
                p->prev = temp;
                p->next = t;
                t->prev = p;
                break;
            }
            if(temp->next == NULL)
            {
                temp->next = p;
                p->prev = temp;
                break;
            }
            temp = temp->next;
        }
    }
    return head;
}

void display(node *head)
{
    node *temp = head;
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
        printf("\n1 for insert \n 2 for print \n 3 for exit");
        printf("\n Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
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
                printf("ff");
        }
    }while(1);
}