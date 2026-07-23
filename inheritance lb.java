import java.util.*;
import java.io.*;

class Main
{
    public static void main(String[] args)
    {
        Scanner s= new Scanner(System.in);
        System.out.println("enter the name");
        String n= s.nextLine();
        System.out.println("enter the age");
        int a= s.nextInt();
        s.nextLine();
        System.out.println("enter the course name");
        String c= s.nextLine();
        student st = new student(n,a,c);
        st.dis();
        
        
        
        
        System.out.println("enter the name");
        String n1= s.nextLine();
        System.out.println("enter the age");
        int a1= s.nextInt();
        s.nextLine();
        System.out.println("enter the subject name");
        String c1= s.nextLine();
        teacher  st1 = new teacher (n1,a1,c1);
        st1.d();
        
        
    }
}
class person
{
    String name;
    int age;
    person(String name,int age)
    {
        this.name=name;
        this.age=age;
    }
    
    void display()
    {
        System.out.println("the name is"+name);
        System.out.println("the age is "+age);
    }
    
}
class student extends person
{
    String course;
    student(String name,int age,String course)
    {
        super(name,age);
        this.course=course;
    }
    void dis()
    {
      display();
      System.out.println("course is"+course);
    }
}
class teacher extends person
{
    String subject;
    teacher(String name,int age,String subject)
    {
         super(name,age);
         this.subject=subject;
    }
    void d()
    {
        display();
        System.out.println("the subject is"+subject);
        
    }
    
    
    
    
}
