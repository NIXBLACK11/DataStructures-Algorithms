#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node* next;
}node;

node * insert(node *rear)
{
    node *p;
    p = (node *)malloc(sizeof(node));
    p->next = NULL;
    printf("\nEnter the value:");
    scanf("%d",&(p->info));
    if(rear==NULL)
    {
        rear = p;
    }
    else
    {
        rear->next = p;
        rear = p;
    }
    return rear;
}

node * delete(node * front)
{
    if(front == NULL)
    {
        printf("\nempty");
    }
    else
    {
        node *temp = front;
        front = front->next;
        free(temp);
    }
    return front;
}

void display(node *front)
{
    if(front==NULL)
    {
        printf("\nempty");
    }
    else
    {
        while(front!=NULL)
        {
            printf("%d,",front->info);
            front = front->next;
        }
    }
}

void display_rev(node* front)
{
    if(front==NULL)
    {
        return;
    }
    else
    {
        display_rev(front->next);
        printf("%d",front->info);
    }
}

int main()
{
    node *front;
    node *rear;
    front = NULL;
    rear = NULL;
    int i = 0;
    do{
        printf("\n1 for push \n 2 for pop\n 3 for display \n 4 for exit");
        printf("\n Enter your choice:");
        scanf("%d",&i);
        switch (i)
        {
            case 1:
                rear = insert(rear);
                if(front == NULL && rear!= NULL)
                {
                    front = rear;
                }
                break;
            case 2:
                front = delete(front);
                break;
            case 3:
                display_rev(front);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nwrong input");
                break;
        }
    }while(1);
}