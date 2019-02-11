import java.util.*;

public class Server{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tasks = in.nextInt();
        int maxTime = in.nextInt();
        int sumTime = 0;
        int numComplete = 0;
        while (tasks > 0) {
            int nextTime = in.nextInt();
            if (!(maxTime >= sumTime + nextTime)) {
               break;
            }
            sumTime += nextTime;
            tasks--;
            numComplete++;
        }
        System.out.println(numComplete);
    }
}