#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}node;

node *insert(node *head)
{
    node *p = (node *)malloc(sizeof(node));
    printf("\nenter the value to enter:");
    scanf("%d",&(p->info));
    p->next = NULL;
    if(head == NULL)
    {
        head = p;
    }
    else
    {
        node *temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
    return head;
}

void display(node *head)
{
    printf("\nThe linked list is:");
    node *temp = head;
    while(temp!=NULL)
    {
        printf("%d,",temp->info);
        temp = temp->next;
    }
}

void display_rev(node *head)
{
    if(head == NULL)
    {
        return;
    }
    else
    {
        display_rev(head->next);
        printf("%d,",head->info);
    }
}

void find_n_last(node *head, int n)
{
    if(head == NULL)
    {
        return;
    }
    else
    {
        find_n_last(head->next, n-1);
        if(n==0)
        {
            printf("%d",head->info);
            return;
        }
    }
}

node *reverseList(node *head) 
{
    node* prev = NULL;
    node* current = head;
    node* next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

node *reverse(node *head)
{
    node *prev = NULL;
    node *current = head;
    node *next = NULL;
    while(current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main()
{
    int opt;
    int n;
    node *head = NULL;
    node *rev = NULL;
    do
    {
        printf("\nEnter the option:");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                head = insert(head);
                break;
            case 2:
                display(head);
                break;
            case 3:
                display_rev(head);
                break;
            case 4:
                printf("Enter the index:");
                scanf("%d",&n);
                find_n_last(head,n);
                break;
            case 5:
                head = reverseList(head);
                break;
            case 6:
                rev = reverseList(head);
                display(rev);
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("\nenter tge correct option");
                break;
        }
    }while(1);
}