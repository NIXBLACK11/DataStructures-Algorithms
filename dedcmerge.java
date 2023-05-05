public class dedcmerge {
    public static void main(String args[]) {
        int a[]={1,5,4,9,-3,-4};
        mergesort(a, 0 , a.length);
        for(int i=0;i<a.length;i++)
        {
            System.out.println(a[i]);
        }
    }
    public static void mergesort(int[] input,int start,int end){
        if(end-start<2)
        {
            return;
        }
        int mid=(start+end)/2;
        mergesort(input, start, mid);
        mergesort(input, mid, end);
        merger(input,start,mid,end);
    }
    public static void merger(int[] input,int start,int mid,int end)
    {
        if(input[mid-1]>=input[mid])
        {
            return;
        }
        int i=start;
        int j=mid;
        int tempIndex=0;
        int[] temp=new int[end-start];
        while(i<mid&&j<end)
        {
            temp[tempIndex++] = input[i] >= input[j] ? input[i++] :input[j++];
        }
        System.arraycopy(input, i, input , start+tempIndex , mid-i );
        System.arraycopy(temp, 0, input, start, tempIndex);
    }
}