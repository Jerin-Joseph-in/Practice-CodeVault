class Demo {
    public static void main(String[] args) {
        MyThread generatorThread = new MyThread();
        Gread evenPrinterThread = new Gread(generatorThread);
        
        // Start the threads
        generatorThread.start();
        evenPrinterThread.start();
    }
}

class MyThread extends Thread {
    public int generatedNumber;

    public void run() {
        // Generate a fixed number every second
        for (int i = 2; i <= 10; i += 2) { // Example: Even numbers from 2 to 10
            generatedNumber = i;
            System.out.println("Generated number is: " + generatedNumber);
            try {
                Thread.sleep(1000); // Wait for 1 second before generating the next number
            } catch (InterruptedException e) {
                // Handle interruption (this can be left empty in this case)
            }
        }
    }
}

class Gread extends Thread {
    MyThread generator;

    Gread(MyThread generator) {
        this.generator = generator;
    }

    public void run() {
        while (true) {
            int number = generator.generatedNumber;

            // Print even numbers only if the generated number is even
            if (number % 2 == 0) {
                System.out.println("Even numbers between 1 and " + number + ":");
                for (int i = 1; i <= number; i++) {
                    if (i % 2 == 0) {
                        System.out.print(i + " ");
                    }
                }
                System.out.println();
            }

            // Sleep for a short time to avoid busy waiting
            try {
                Thread.sleep(1000); // Check every second
            } catch (InterruptedException e) {
                // Handle interruption (this can be left empty in this case)
            }
        }
    }
}
