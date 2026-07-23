import java.io.*;
import java.util.*;
class demo
{
    public static void main(String[] args)
    {
        man m = new man();
        can c = new can();
        m.D2();
        c.D3();
    }
}


class Employee
{
    
      
    void D1(String name,int id)
    {   
       System.out.println(name);
        System.out.println(id);   
    }
}
class man extends Employee
{
    Scanner s = new Scanner(System.in);


    void D2()
    {
        System.out.println("enter the name");
        String name =s.nextLine();
        System.out.println("enter the id");
        int id = s.nextInt();
        s.nextLine();
        System.out.println("enter the department");
String d = s.nextLine();
        D1(name,id);
        System.out.println(d);
    }
}
class can extends man
{Scanner s = new Scanner(System.in);
void D3()
{
   System.out.println("enter the specialization");
        String spec=s.nextLine(); 
        D2();
        System.out.println(spec);
}
    
}
