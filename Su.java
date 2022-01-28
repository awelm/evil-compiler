import java.util.Scanner;

public class Su {
    public static void main(String[] args) {
        Scanner inputReader = new Scanner(System.in);
        System.out.println("Enter root password:");
        String userName = inputReader.nextLine();
        if(userName == "test123")
            System.out.println("Successfully logged in as root");
        else
            System.out.println("Wrong password, try again.");
    }
}
