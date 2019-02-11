import java.util.*;

public class AListGame{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();
        int count = 0;
        int i = 2;
        while (Math.pow(i,2) <= num) {
            if (num % i == 0) {
               count++;
               num /= i;
            } else i++;
        }
        count++;
        System.out.println(count);
    }
}