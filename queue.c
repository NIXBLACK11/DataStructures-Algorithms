#include <stdio.h>
#include<stdlib.h>
#define max 50
int insert(int[],int);
int delete(int[],int,int);
void display(int[],int,int);
int main()
{
    int arr[max];
    int ch,front=-1,rear=-1;
    do{
        printf("\n1 for insert \n 2 for delete \n 3 for print \n 4 for exit");
        printf("\n Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            	if(front==-1)
				{
					front=0;
				}
                rear=insert(arr,rear);
                break;
            case 2:
                front=delete(arr,front,rear);
                break;
            case 3:
                display(arr,front,rear);
                break;
            case 4:
                exit(0);
        }
    }while(1);
}
int insert(int arr[],int rear)
{
	int val=0;
	if(rear==max-1)
	{
		printf("overflow");	
	}
	else
	{
		printf("enter the value:");
		scanf("%d",&val);
		rear++;
		arr[rear]=val;
		printf("%d",rear);
	}
	return rear;	
}
int delete(int arr[],int front,int rear)
{
	if(front==-1||front>rear)
	{
		printf("underflow");
	}
	else
	{
		front++;
		printf("%d",front);
	}
	return front;
}
void display(int arr[],int front,int rear)
{
	if(front>rear||front==-1)
	{
		printf("underflow");
	}
	else
	{
		for(int i=front;i<=rear;i++)
    	{
        	printf("%d,",arr[i]);
    	}
	}
}
