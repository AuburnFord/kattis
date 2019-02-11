import java.util.*;

public class AboveAverage{
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int cases = in.nextInt();
        while (cases-- > 0) {
            int students = in.nextInt();
            int[] grades = new int[students];
            int sum = 0;
            for (int i = 0; i < students; i++) {
                grades[i] = in.nextInt();
                sum += grades[i];
            }
            double average = (double) sum / students;
            int above = 0;
            for (int i = 0; i <= students - 1; i++) {
                if (grades[i] > average) {
                    above++;
                }
            }
            double abvAvg = (double) above / students * 100;
            System.out.printf("%.3f%%", abvAvg, above);
        }
    }
}