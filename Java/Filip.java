import java.util.*;

class Filip{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String numbers = in.nextLine();
        int number1 = (numbers.charAt(2) & 0x0F) * 100 + (numbers.charAt(1) & 0x0F) * 10 +(numbers.charAt(0) & 0x0F);
        int number2 = (numbers.charAt(6) & 0x0F) * 100 + (numbers.charAt(5) & 0x0F) * 10 +(numbers.charAt(4) & 0x0F);
        if (number1 > number2) {
            System.out.println(number1);
        } else {
            System.out.println(number2);
        }
    }
}