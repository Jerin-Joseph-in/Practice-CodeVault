import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
class calculator implements ActionListener
{
    JFrame j;
    JButton b1,b2,b3,b4,b5,b6,b7,b8,b9,b0,bmul,badd,bsub,bdiv,bclr,beq;
    JTextField t;
    int c,a,b,r=0;
    calculator()
    {
        j = new JFrame("calculator");
        t= new JTextField();
        b1 = new JButton("1");
        b2 = new JButton("2");
        b3 = new JButton("3");
        b4 = new JButton("4");
        b5 = new JButton("5");
        b6 = new JButton("6");
        b7 = new JButton("7");
        b8 = new JButton("8");
        b9 = new JButton("9");
        b0 = new JButton("0");
        bmul = new JButton("*");
        badd = new JButton("+");
        bdiv = new JButton("/");
        bsub = new JButton("-");
        bclr = new JButton("clr");
        t.setBounds(170,213,12,24);
        b1.setBounds(100,220,10,20);
        b2.setBounds(100,240,20,30);
        b3.setBounds(100,260,30,40);
        b4.setBounds(100,280,40,50);
        b5.setBounds(100,250,50,60);
        b6.setBounds(100,230,60,70);
        b7.setBounds(100,210,10,80);
        b8.setBounds(100,250,10,90);
        b9.setBounds(100,220,10,15);
        b0.setBounds(100,233,10,25);
        bmul.setBounds(100,244,10,35);
        badd.setBounds(100,255,10,45);
        bsub.setBounds(100,266,10,55);
        bclr.setBounds(100,277,10,66);
        bdiv.setBounds(100,288,10,77);
        
        j.add(b1);
        j.add(b2);
        j.add(b3);
        j.add(b4);
        j.add(b5);
        j.add(b6);
        j.add(b7);
        j.add(b8);
        j.add(b9);
        j.add(b0);
        j.add(bmul);
        j.add(badd);
        j.add(bsub);
        j.add(bdiv);
        j.add(bclr);
        j.add(beq);
        
        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b4.addActionListener(this);
        b5.addActionListener(this);
        b6.addActionListener(this);
        b7.addActionListener(this);
        b8.addActionListener(this);
        b9.addActionListener(this);
        b0.addActionListener(this);
        bmul.addActionListener(this);
        bsub.addActionListener(this);
        bdiv.addActionListener(this);
        bclr.addActionListener(this);
        badd.addActionListener(this);
        beq.addActionListener(this);
        
        
        
        j.setSize(400,500);
        j.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        j.setVisible(true);
    }
  public   void actionPerformed(ActionEvent e)
    {
       if(e.getSource()==b1)
      {
          t.setText(t.getText().concat("1"));
      }
      else if(e.getSource()==b2)
      {
         t.setText(t.getText().concat("2"));
        
      }
      else if(e.getSource()==b3)
      {
         t.setText(t.getText().concat("3"));
        
      }
      else if(e.getSource()==b4)
      {
         t.setText(t.getText().concat("4"));
        
      }
      else if(e.getSource()==b5)
      {
         t.setText(t.getText().concat("5"));
        
      }
      else if(e.getSource()==b6)
      {
         t.setText(t.getText().concat("6"));
        
      }
      else if(e.getSource()==b7)
      {
         t.setText(t.getText().concat("7"));
        
      }
      else if(e.getSource()==b8)
      {
         t.setText(t.getText().concat("8"));
        
      }
      else if(e.getSource()==b9)
      {
         t.setText(t.getText().concat("9"));
        
      }
      else if(e.getSource()==b0)
      {
         t.setText(t.getText().concat("0"));
        
      }
      else if(e.getSource()==badd)
      {
        int a = Integer.parseInt(t.getText());
        c=1;
        
      }
      else if(e.getSource()==bsub)
      {
         int a = Integer.parseInt(t.getText());
        c=2;
        
      }
      else if(e.getSource()==bmul)
      {
         int a = Integer.parseInt(t.getText());
        c=3;
        
      }
      else if(e.getSource()==bdiv)
      {
        int a = Integer.parseInt(t.getText());
        c=4;
        
      }
      else if(e.getSource()==beq)
      {
        int  b=Integer.parseInt(t.getText());
        switch(c)
        {
            case 1:r=a+b;
                   break;
            case 2:r=a-b;
                break;
            case 3:r=a*b;
                   break;
            case 4:r=a/b;
                   break;
        }
        t.setText(""+r);
      }
    }
    public static void main(String[] args)
    {
        new calculator();
    }
}

        
        
        
        
        
        
        
        
