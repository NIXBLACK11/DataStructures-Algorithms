#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int exec_time;
    int pro_num;
    struct node * next;
    struct node * prev;
}node;

node *insert(node *head,int num)
{
    node *p;
    p = (node*)malloc(sizeof(node));
    int val;
    scanf("%d",&val);
    p->exec_time = val;
    p->pro_num = num;
    p->next = NULL;
    p->prev = NULL;

    if(head==NULL)
    {
        head = p;
        p->next = head;
        p->prev = head;
    }
    else
    {
        node *temp = head;
        while(temp->next!=head)
        {
            temp = temp->next;
        }
        temp->next = p;
        p->next = head;
        p->prev = temp;
    }
    return head;
}

node *del(node *temp)
{
    node *d = temp;
    temp->prev->next = temp->next; 
    return d->next;
}

void display(node* head)
{
     node *temp = head;
     while(temp->next!=head)
     {
         printf("%d %d\n", temp->exec_time, temp->pro_num);
         temp = temp->next;
     }
     printf("%d %d\n", temp->exec_time, temp->pro_num);
}

int main()
{
    /*
        n -> stores the number of processes
        head -> points to the first element of the node
        timeTaken -> stores the time taken for a process
        ts -> time cpu gives for one process
    */
    int n,timeTaken = 0,ts;
    node *head = NULL;

    printf("enter the number of processes:");
    scanf("%d",&n);

    printf("enter the time slot:");
    scanf("%d",&ts);

    printf("\nenter the executions time of the processes:");
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the execution time of %d process:",(i+1));
        head = insert(head,(i+1));
    }
    node *temp = head;

    while(head!=NULL)
    {
        timeTaken = timeTaken + ts;
        temp->exec_time = temp->exec_time - ts;
        if(temp->exec_time == 0)
        {
            printf("\n%d :  %d process executed",timeTaken,(temp->pro_num));
            node *d = temp;
            temp->prev->next = temp->next; 
            temp = d->next;
            free(d);
        }
        else
        {
            printf("\n%d : %d",timeTaken,(temp->pro_num));
            temp = temp->next;
        }
    }
}