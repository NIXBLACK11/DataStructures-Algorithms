#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node * next;
}node;

node *insert(node *head)
{
    node * p ;
    p = (node*)malloc(sizeof(node));
    p->next = NULL;
    printf("\nEnter the value:");
    scanf("%d",&(p->info));
    if(head == NULL)
    {
        head = p;
    }
    else{
        node * temp = head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next = p;
    }
    return head;
}

void display(node *head)
{
    node * temp = head;
    int i = 2;
    while(temp!=NULL)
    {
        if(i%2 == 0)
        {
            printf("%d,",temp->info);
        }
        i++;
        temp = temp->next;
    }
}

int main()
{
    node *head = NULL;
    int ch;
    do{
        printf("\n1 for insert \n 2 for print\n 3 for exit");
        printf("\n Enter your choice:");
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
                printf("\nwrong input!");
                break;
        }
    }while(1);
}