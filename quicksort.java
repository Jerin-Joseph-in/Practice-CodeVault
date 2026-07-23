import java.io.*;
import java.util.*;

class D
{
    public static void main(String[] args)
    { 
        Scanner s = new Scanner(System.in);
        System.out.println("enter the array size");
        String m = s.nextLine();
        int n =Integer.parseInt(m);
        String a[]= new String[n];
        System.out.println("enter the elements");
        for(int i=0;i<n;i++)
        {
            a[i]=s.nextLine();
        }
        demo d = new demo();
        d.quicksort(a,0,n-1);
        for(int i=0;i<n;i++)
        {
            System.out.println(a[i]);
        }
    }
}
class demo
{
 public void quicksort(String a[],int low,int high)
    {  if(low<high)
    {
        String  p=a[low];
        int i=low;
        int j=high;
        while(i<j)
        {
            while(a[i].compareTo(p)>=0 && i<high)
            {
                i++;
            }
            while(a[j].compareTo(p)>=0 && j>low)
            {
                j--;
            }
            if(i<j)
            {
                String temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        String temp=a[low];
        a[low]=a[j];
        a[j]=temp;
         
         quicksort(a,low,j-1);
         quicksort(a,j+1,high);
        
    }}
}
