import java.util.*;

public class A1Paper {
    
    public static void main(String[] args) {
       Scanner in = new Scanner(System.in);
       int smallest = in.nextInt();
       int[] papers = new int[smallest - 1];
       int goal = (int) Math.pow(2, smallest - 1);
       int sum = 0;
       double tapeLength = 0;
       for (int i = 0; i < smallest - 1; i++) {
          papers[i] = in.nextInt(); 
       }
       for (int i = 0; i < smallest - 1; i++) {
          int j = 0;
          while ((int)(sum + Math.pow(2, smallest -i -2)) <= goal  && j < papers[i]) {
             sum += Math.pow(2, smallest - i -2);
             tapeLength += Math.pow(2, -0.75) * Math.pow(2, -0.5 * i);
             j++;
          }
       }
       System.out.println(sum >= goal ? tapeLength : "impossible");
       System.out.println(Math.pow(2, -0.75) * Math.pow(2, 0));
    }
}

//sum += (int) Math.pow(2, smallest - i++) * 