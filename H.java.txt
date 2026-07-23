import java.io.*;

class HelloWorld {
    public static void main(String[] args) {
    try{
      FileReader r = new FileReader("text.txt");
      FileWriter w = new FileWriter("c.txt");
      int c;
      c=r.read();
      while (c != -1)
      {
      System.out.println((char)c);
        w.write((char)c);
    }
    r.close();
    w.close();
    }
    catch (Exception e)
    {
      System.out.println(e);   
    }
        
        
    }}
    
    
    
    
    
    
    