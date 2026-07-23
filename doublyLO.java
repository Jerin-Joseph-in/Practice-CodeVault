import java.util.*;
class demo
{
    public static void main(String[] args)
    { 
        doubly d = new doubly();
        Scanner s = new Scanner(System.in);
        int c;
        do
        {
        System.out.println("enter 1.insert at end,2.delete at front,3.display,4.exit");
        System.out.println("enter the choice");
        c = s.nextInt();
        switch(c)
        {
            case 1:System.out.println("enter the item");
                   int data = s.nextInt();
                   d.insertend(data);
                   break;
            case 2:d.deletebeg();
                   break;
            case 3:d.display();
                   break;
            case 4:break;
            default :System.out.println("invalid");
        }
        
        
    }while(c != 4);
    s.close();
}
}
class doubly
{
    node head;
    class node
    {
        int data;
        node left;
        node right;
        
        node(int data)
        {
            this.data=data;
        }
    }
    
    void insertend(int data)
    { node temp = new node(data);
        if(head==null)
        {
            head=temp;
        }
        else
        {
           node ptr = head;
           while(ptr.right!=null)
           {
               ptr=ptr.right;
               
           }
           ptr.right=temp;
           temp.left=ptr;
           temp.right=null;
        }
    }
    void deletebeg()
    {
        if(head==null)
        {
            System.out.println("empty");
        }
        else if(head.right==null)
        {
            head=null;
        }
        else
        {
            node ptr;
            ptr=head;
            head=head.right;
            head.left=null;
            ptr.left=ptr.right=null;
        }
    }
    

void display()
{
    if(head==null)
        {
            System.out.println("empty");
        }
        else
        {
            node ptr;
            ptr=head;
            while(ptr.right!=null)
            {
             System.out.println(ptr.data);
             ptr=ptr.right;
            }
            System.out.println(ptr.data);
            
        }
}

}
