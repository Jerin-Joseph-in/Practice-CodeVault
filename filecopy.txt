import java.io.*;
import java.util.Scanner;

public class FileCopy {
    public static void main(String[] args) {
        // File to read from
        File inputFile = new File("input.txt");
        // File to write to
        File outputFile = new File("output.txt");

        try (
            // Create Scanner to read input file
            Scanner scanner = new Scanner(inputFile);
            // Create FileWriter to write to output file
            FileWriter writer = new FileWriter(outputFile)
        ) {
            // Loop through the input file line by line
            while (scanner.hasNextLine()) {
                // Read the next line from the input file
                String line = scanner.nextLine();
                // Write the line to the output file
                writer.write(line + "\n");
            }
            System.out.println("File copied successfully!");
        } catch (IOException e) {
            System.err.println("An error occurred: " + e.getMessage());
        }
    }
}
