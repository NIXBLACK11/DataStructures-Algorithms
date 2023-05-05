#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}node;

node *insert(node *rear,node *front)
{
    int val;
    node *p = (node*)malloc(sizeof(node));
    printf("\nEnter the value:");
    scanf("%d",&val);
    p->info = val;
    p->next = NULL;
    if(rear == NULL)
    {
        rear = p;
        p->next = rear;
    }
    else{
        rear->next = p;
        rear = p;
        rear->next = front; 
    }
    return rear;
}

node *delete(node *front,node *rear)
{
    if(front == NULL)
    {
        printf("\nempty!");
    }
    else{
        node *temp = front;
        front = front->next;
        rear->next = front;
        free(temp);
    }
    return front;
}

void display(node *front,node *rear)
{
    if(front == NULL)
    {
        printf("\nempty!");
    }
    else{
        while(front!=rear)
        {
            printf("%d,",(front->info));
            front = front->next;
        }
        printf("%d",(front->info));
    }
}

int main()
{
    node *front = NULL;
    node *rear = NULL;
    int i=0;
    do{
        printf("\n1 for push \n 2 for pop\n 3 for display \n 4 for exit");
        printf("\n Enter your choice:");
        scanf("%d",&i);
        switch(i)
        {
            case 1:
                rear = insert(rear,front);
                if(front == NULL)
                {
                    front = rear;
                }
                break;
            case 2:
                front = delete(front,rear);
                if(front == NULL)
                {
                    rear = NULL;
                }
                break;
            case 3:
                display(front,rear);
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