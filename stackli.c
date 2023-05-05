#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}node;

node *insert(node *head)
{
    int val;
    node *p = (node*)malloc(sizeof(node));
    printf("\nEnter the value:");
    scanf("%d",&(val));
    p->info = val;
    p->next = NULL;
    if(head==NULL)
    {
        head = p;
    }
    else
    {
        p->next = head;
        head = p;
    }
    return head;
}

node *delete(node *head)
{
    if(head==NULL)
    {
        printf("\nempty");
    }
    else
    {
        printf("\n%d:deleted",head->info);
        node *temp;
        temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

void display(node *head)
{
    if(head==NULL)
    {
        printf("empty");
    }
    else
    {
        while(head!=NULL)
        {
            printf("%d,",head->info);
            head = head->next;
        }
    }
}

int main()
{
    node *head;
    head = NULL;
    int i=0;
    do{
        printf("\n1 for push \n 2 for pop\n 3 for display \n 4 for exit");
        printf("\n Enter your choice:\n");
        scanf("%d",&i);
        switch(i)
        {
            case 1:
                head = insert(head);
                break;
            case 2:
                head = delete(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
        }
    }while(1);
}