import java.io.*;
import java.util.*;

public class CollatzConjecture {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String[] line = in.readLine().split(" ");
        int x = Integer.parseInt(line[0]);
        int y = Integer.parseInt(line[1]);
        while (x != 0 && y != 0 ) {
            int[] a = new int[20000];
            int[] b = new int[20000];
            int a_len = 1;
            int b_len = 1;
            a[0] = x;
            b[0] = y;
           while (x != 1) {
               if (x % 2 == 0) {
                   x /= 2;
                   a[a_len++] = x;
               } else {
                   x *= 3;
                   x += 1;
                   a[a_len++] = x;
               }
           }
           while (y != 1) {
               if (y % 2 == 0) {
                   y /= 2;
                   b[b_len++] = y;
               } else {
                   y *= 3;
                   y += 1;
                   b[b_len++] = y;
               }
           }

           int index = 1;
           while (a[a_len - index] == b[b_len - index]) {
               if (a_len - index == 0 || b_len - index == 0) {
                    index++;
                    break;
               }
               index++;
           }
               
        
           System.out.print(a[0] + " needs " + (a_len-index+1) + " steps, ");
           System.out.print(b[0] + " needs " + (b_len-index+1) + " steps, they meet at ");
           System.out.println(a[a_len-index+1]);
           line = in.readLine().split(" ");
           y = Integer.parseInt(line[1]); 
           x = Integer.parseInt(line[0]);
        }
    }
}