import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class A implements ActionListener {
    JFrame j;
    JTextField f1, f2;
    JButton b;

    A() {
        j = new JFrame("program");
        f1 = new JTextField(20);
        f2 = new JTextField(20);
        b = new JButton("click");

        f1.setBounds(100, 20, 100, 30);
        f2.setBounds(100, 60, 100, 30);
        b.setBounds(100, 100, 100, 30);

        j.setLayout(null); // Set to null layout for manual positioning
        j.setSize(300, 200);
        j.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        j.setVisible(true);

        j.add(f1);
        j.add(f2);
        j.add(b);
        
        b.addActionListener(this);
    }

    public void actionPerformed(ActionEvent s) {
        try {
            if (s.getSource() == b) {
                double a = Double.parseDouble(f1.getText());
                f2.setText(String.valueOf((a * 9 / 5) + 32));
            }
        } catch (Exception e) {
            System.out.println("Enter a valid number");
        }
    }

    public static void main(String[] args) {
        new A();
    }
}
