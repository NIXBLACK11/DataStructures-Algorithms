#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}node;

node *insert(node *rear)
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

int main()
{
    node *rear;
    node *front;
    int ch;
    do{
        printf("\n1 for push \n 2 for pop\n 3 for display \n 4 for exit");
        printf("\n Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                rear=insert(rear);
                break;
            case 2:
                front=pop(front);
                break;
            case 3:
                display(front);
                break;
            case 4:
                exit(0);
        }
    }while(1);
}