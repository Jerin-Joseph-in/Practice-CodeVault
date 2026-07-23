import java.io.*;
import java.util.*;
class demo
{
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
                System.out.println("enter the name");
                String x = s.nextLine();
                        System.out.println("enter the name");
                        String y = s.nextLine();
                                 System.out.println("enter the salary");
                                 int w= s.nextInt();
                         System.out.println("enter the salary");
                         int z = s.nextInt();
                         Officer o = new Officer(x,y,w,z);
                         o.dis();
    }
}



class Employee
{
    String n1;
    String n2;
    int s1;
    int s2;
    int n=12;
    void display()
    {
        System.out.println(n1);
        System.out.println(n2);
        
    }
    void salary()
    { 
     System.out.println("the Salary of "+n1+"   is   "+s1*12);
          System.out.println("the Salary of "+n2+"  is  "+s2*12);

    }
}
class Officer extends Employee
{
    Officer(String n1,String n2,int s1,int s2)
    {
     this.n1=n1;
     this.n2=n2;
     this.s1=s1;
     this.s2=s2;
    }
    void dis()
    {
    display();
    salary();
}
}
