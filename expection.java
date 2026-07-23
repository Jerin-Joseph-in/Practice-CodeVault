import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
     Scanner s= new Scanner(System.in);
    try
    {
        System.out.println("enter the array size");
        int n=s.nextInt();
        int a[]=new int[n];
        for(int i=0;i<n;i++)
        {
            a[i]=s.nextInt();
        }
        for(int i=0;i<n;i++)
        {
           System.out.println(a[i]); 
        }
        System.out.println("element to insert");
        int item =s.nextInt();
        a[10]=item;
    }
    catch(ArrayIndexOutOfBoundsException e)
    {
        System.out.println("error");
    }
    catch(InputMismatchException e  )
     {
         System.out.println(e);
     }
     
     
    }
}
