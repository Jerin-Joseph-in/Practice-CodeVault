import java.io.*;
import java.lang.*;
class Demo
{
     public static void main(String[] args)
     {
         try
         {
             File F = new File("text.txt");
             FileReader r = new FileReader(F);
             FileWriter w = new FileWriter("cp.text");
             int c;
             while((c=r.read())!=-1)
             {
                 System.out.println((char)c);
                 w.write((char)c);
             }
             r.close();
             w.close();
             
         }
         catch(Exception e)
         {
             System.out.println(e);
         }
     }
}