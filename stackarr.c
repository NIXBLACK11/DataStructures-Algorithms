#include<stdio.h>
#define max 50

int push(int arr[] , int top)
{
    if()
}




int main()
{
    int ch;
    int arr[max];
    int top = -1;
    while(1)
    {
        switch(ch)
        {
            case 1:
                push(arr,top);
                break;
            case 2:
                pop(arr,top);
                break;
            case 3:
                display(arr,top);
                break;
            case 4:
                exit(0);
            default:
                printf("wrong input");
        }
    }
}