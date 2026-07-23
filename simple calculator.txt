import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
     Scanner s= new Scanner(System.in);
     int c;
     do
     {
    System.out.println("enter 1 number");
    int a=s.nextInt();
    System.out.println("enter 2 number");
    int b=s.nextInt();
    System.out.println("1.addition,2.suntraction,3.multiplication,4.divition,5.exits");
    System.out.println("enter the choice");
     c = s.nextInt();
    switch(c)
    {
        case 1:int r=a+b;
              System.out.println(r);
              break;
        case 2:int x=a-b;
              System.out.println(x);
              break;
        case 3:int y=a*b;
              System.out.println(y);
              break;
        case 4:int z=a/b;
              System.out.println(z);
              break;
        case 5:break;
        default :System.out.println("invalid");
    }
}while(c!=5);
}
}
