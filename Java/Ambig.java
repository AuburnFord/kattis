import java.util.*;
import java.io.*;

public class Ambig {    // dp to save off sets of parentheses???
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String transmission = in.readLine();
        while (!transmission.equals("END")) {
            int[] operands = new int[100];
            char[] operators = new char[99];
            int i = 0, iEnd = 0, b = 0, c = 0;
            while (i < transmission.length()) {
                if (transmission.charAt(i) <= 43) {
                    operators[c++] = transmission.charAt(i);
                    if (i != iEnd) {
                        operands[b++] = Integer.parseInt(transmission.substring(iEnd, i));
                        iEnd = i + 1;
                    } else iEnd++;
                }
                i++;
            }
            operands[b] = Integer.parseInt(transmission.substring(iEnd, i));
            System.out.println(iEnd + " " + i);
            for (int s: operands) {
                System.out.print(s + " ");
            }
            System.out.println();
            for (char q: operators) {
                System.out.print(q + " ");
            }
            System.out.println();
            transmission = in.readLine();
        }
    }
}