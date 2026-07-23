class fact
{
   int facto(int n)
    {
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return 1;
        }
        return n*facto(n-1);
    }
}

class Main
{
    public static void main(String[] args)
    {
        fact f = new fact();
     System.out.println(f.facto(10
     
     ));
        
    }
}


