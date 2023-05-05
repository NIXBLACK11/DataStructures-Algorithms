#include<stdio.h>

int check(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
        {
            return 0;
        }
    }
    return 1;
    //returns 1 when all the processes are executed
}

int next(int i,int n)
{
    if(i==(n-1))
    {
        return (0);
    }
    else
    {
        return i+1;
    }
}
int main()
{
    /*
        n         -> stores the number of processes
        et        -> array which stores the execution time for the n processes
        ts        -> time cpu gives to a single process
        count_pro -> number of processes executed
        timeTaken -> time taken for execution
    */
    int n , ts , count_pro = 0;

    printf("Enter the number of processes to be executed:");
    scanf("%d",&n);

    printf("\nEnter the value of the time slot:");
    scanf("%d",&ts);

    int et[n];

    printf("\nEnter the execution time of the processes:");
    for(int i=0;i<n;i++)
    {
        printf("\nExecution time for %d process is:",(i+1));
        scanf("%d",&et[i]);
    }

    int timeTaken = ts;
    while(check(et,n)==0)
    {
        if(et[count_pro] <= 0)
        {
            count_pro = next(count_pro , n);
            continue;
        }
        et[count_pro] = et[count_pro] - ts;
        if(et[count_pro] <= 0)
        {
            printf("\n%d %d Process executed",timeTaken,(count_pro+1));
        }
        else{
            printf("\n%d",timeTaken);
        }
        timeTaken = timeTaken + ts;
        count_pro = next(count_pro , n);
    }
    printf("\n\nAll processes executed");
}