import java.util.*;
import java.io.*;
// covers additional edge cases
public class GuessingNum {
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String next = "";
        int lo = 1;
        int hi = 1001;
        while (!next.equals("correct")) {
            int guess = (lo + hi)/2; // lo + (hi - lo + 1)/2; fail if is 1
            System.out.println(guess);
            System.out.flush();
            next = in.readLine();
            if (next.equals("lower")) {
                hi = guess;
            } else if(next.equals("higher")) {
                lo = guess;
            }
        }
    }
}