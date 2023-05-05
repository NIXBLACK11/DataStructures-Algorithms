#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info;
    struct node *next;
}node;

node* insert(node *head, int value)
{
    node *p;
    p = (node*)malloc(sizeof(node));
    p->info = value;
    p->next = NULL;
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
void *add(node *p ,node **q, node **r)
{
    int i=0;
    while(p != NULL)
    {
        if(i%2 == 0)
        {
            *q = insert(*q, p->info);
        }
        else
        {
            *r = insert(*r, p->info);
        }
        i++;
        p = p->next;
    }
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
int main()
{
    node *p = NULL;
    node *q = NULL;
    node *r = NULL;
    int ch;
    do{
        printf("\n1 for insert \n 2 for \n 3 for print \n 4 for exit");
        printf("\n Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("enter the value:");
                int value;
                scanf("%d",&value);
                p=insert(p, value);
                break;
            case 3:
                display(p);
                printf("\n");
                display(q);
                printf("\n");
                display(r);
                break;
            case 4:
                add(p, &q, &r);
                break;
            case 5:
                exit(0);
                break;
        }
    }while(1);
}