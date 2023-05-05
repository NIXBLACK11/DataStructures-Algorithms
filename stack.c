#include <stdio.h>
#include<stdlib.h>
#define max 50
int push(int[],int);
int pop(int[],int);
void display(int[],int);
int main()
{
    int arr[max];
    int ch,top=-1;
    do{
        printf("\n1 for push \n 2 for pop \n 3 for print \n 4 for exit");
        printf("\n Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                top=push(arr,top);
                break;
            case 2:
                top=pop(arr,top);
                break;
            case 3:
                display(arr,top);
                break;
            case 4:
                exit(0);
        }
    }while(1);
}
int push(int arr[],int top)
{
    int val;
    printf("Enter the value:");
    scanf("%d",&val);
    if(top==max-1)
    {
        printf("Stack overflow");
    }
    else
    {
        top++;
        arr[top]=val;
    }
    return top;
}
int pop(int arr[],int top)
{
    if(top==-1)
    {
        printf("stac empty underflow");
    }
    else
    {
        top--;
    }
    return top;
}
void display(int arr[],int top)
{
    for(int i=top;i>=0;i--)
    {
        printf("%d,",arr[i]);
    }
}
