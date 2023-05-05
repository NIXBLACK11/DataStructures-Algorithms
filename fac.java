class fac
{
    public static void main(String args[])
    {
        int recu=rec(5);
        System.out.println(recu);
    }
    static int rec(int a)
    {
        if(a==0)
        {
            return 1;
        }
        else
        {
            return a*rec(a-1);
        }
    }
}