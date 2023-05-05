#include<stdio.h>
#include<limits.h>
int main()
{
    int n;
    int max = INT_MIN;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]>max)
        {
            max = arr[i];
        }
    }
    int brr[max];
    for(int i=0;i<n;i++)
    {
        int temp = arr[i];
        brr[temp] = brr[temp]+1;
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(brr[arr[i]]>=2)
        {
            count++;
        }
        if(count == 2)
        {
            printf("Ans is:%d",arr[i]);
            break;
        }
    }
    
}