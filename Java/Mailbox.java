import java.util.*;

public class Mailbox {
    static int memo[][][] = new int[101][101][11];
    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);
        int runs = in.nextInt();
        while (runs > 0) {
            int mailboxes = in.nextInt();
            int maxFire = in.nextInt();
            System.out.println(fireCrackers(maxFire, 0, mailboxes));
            runs--;
        }
    }

    static int fireCrackers(int fcH, int fcL, int mb) {
        if (fcH == fcL) {
            return 0;
        }

        if (memo[fcH][fcL][mb] != 0) {
            return memo[fcH][fcL][mb];
        }
        
        if (mb == 1) {
            return fcH*(fcH+1)/2 - fcL*(fcL+1)/2;
        }

        int min = Integer.MAX_VALUE;
        int result;
        for (int i = fcL+1; i <= fcH; i++) {
            result = Math.max(fireCrackers(i-1, fcL, mb-1), fireCrackers(fcH, i, mb));
            min = (min > result+i ? result + i: min);
        }
        memo[fcH][fcL][mb] = min;
        return min;
    }
}