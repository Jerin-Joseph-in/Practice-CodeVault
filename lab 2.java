import java.util.Scanner;

class Demo {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        
        System.out.println("Enter the name of the first employee:");
        String name1 = s.nextLine();
        
        System.out.println("Enter the name of the second employee:");
        String name2 = s.nextLine();
        
        System.out.println("Enter the monthly salary of the first employee:");
        int salary1 = s.nextInt();
        
        System.out.println("Enter the monthly salary of the second employee:");
        int salary2 = s.nextInt();
        
        Officer officer = new Officer(name1, name2, salary1, salary2);
        
        // Directly calling display methods
        officer.display();
        officer.displaySalaries();
        
        s.close(); // Close the scanner to avoid resource leaks
    }
}

class Employee {
    String name1;
    String name2;
    int salary1;
    int salary2;

    Employee(String name1, String name2, int salary1, int salary2) {
        this.name1 = name1;
        this.name2 = name2;
        this.salary1 = salary1;
        this.salary2 = salary2;
    }

    void display() {
        System.out.println("Employee 1: " + name1);
        System.out.println("Employee 2: " + name2);
    }

    void displaySalaries() {
        System.out.println("The annual salary of " + name1 + " is " + (salary1 * 12));
        System.out.println("The annual salary of " + name2 + " is " + (salary2 * 12));
    }
}

class Officer extends Employee {
    Officer(String name1, String name2, int salary1, int salary2) {
        super(name1, name2, salary1, salary2); // Calling the parent class constructor
    }
}
