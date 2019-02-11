import java.util.*;

public class AlmostPerfect {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        do {
            int maybePerfect = in.nextInt();
            int sum = 1;
            for (int i  = 2; i <= (int)Math.floor(Math.sqrt(maybePerfect)); i++) {
                if (maybePerfect % i == 0) {
                    if (i * i == maybePerfect) {
                        sum += i;
                    } else {
                        sum += i + maybePerfect / i;
                    }
                }
            }
            System.out.print(maybePerfect);
            if (Math.abs(maybePerfect - sum) <= 2) {
                if (maybePerfect == sum) {
                    System.out.println(" perfect");
                } else {
                    System.out.println(" almost perfect");
                }

            } else {
                System.out.println(" not perfect");
            }
        } while (in.hasNextInt());
    }
}