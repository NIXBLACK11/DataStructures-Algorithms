#include<stdio.h>
#include<limits.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int c=0;
    int count= 0;
    for(int i=0;i<n;i++)
    {
        c=0;
        if(arr[i]==INT_MIN)
        {
            continue;
        }
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                c++;
                arr[j]=INT_MIN;
            }
        }
        if(c>=1)
        {
            count++;
        }
        if(count==2)
        {
            printf("Ans is:%d",arr[i]);
            break;
        }
    }
}