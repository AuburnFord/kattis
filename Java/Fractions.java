import java.util.*;
public class Fractions {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int num1 = in.nextInt();
        int num2 = in.nextInt();
        while (num1 != 0 && num2 != 0) {
            System.out.println("" + (num1/num2) + " " + (num1 % num2) + " / " + num2);
            num1 = in.nextInt();
            num2 = in.nextInt();
        }
    }
}