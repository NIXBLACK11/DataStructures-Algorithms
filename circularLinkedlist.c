#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node* insert(node* head)
{
    int val = 0;
    node *p = (node*)malloc(sizeof(node));
    printf("Enter Value :");
    scanf("%d", &val);
    p->data = val;
    p->next = NULL;

    if(head==NULL)
    {
        head = p;
    }
    else
    {
        node *temp = head;
        while(temp->next!=head && temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
        p->next = head;
    }

    return head;
}

void display(node* head)
{
    node *temp = head;
    printf("\nOutput : ");
    while(temp->next!=head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
    printf("\n");
}

int main(){
    node *head;
    head = NULL;
    int c = 0;
    do{
        printf("\nMenu:\n");
        printf("1. Enter 1 to insert\n2. Enter 2 to delete\n3. Enter 3 to display\n4. Enter 4 to exit\n");
        printf("\nEnter your choice :");
        scanf("%d", &c);
        switch (c)
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
                break;
            default:
                printf("\ninvalid input\n");
        }
    }while(1);
}