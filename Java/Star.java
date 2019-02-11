import java.util.*;

public class Star{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int stars = in.nextInt();
        System.out.println(stars + ":");
        for (int i = 2; i <= (stars/2); i++) {
            if (stars != i && (stars%(2*i - 1) == i || stars%(2*i-1) == 0)) {
                System.out.println(i + "," + (i-1));
            }
            if (stars%i == 0 && stars/i !=1) {
                System.out.println(i + "," + i);
            }
            
        }
    }
}