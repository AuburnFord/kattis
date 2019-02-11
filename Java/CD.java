import java.util.*;
import java.io.*;
public class CD {

    public static void main(String[] args) throws IOException {
       BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
       String[] nums = in.readLine().split(" ");
       int jack = Integer.parseInt(nums[0]);
       int jill = Integer.parseInt(nums[1]);
       while (jack != 0 || jill !=0) {
          HashSet<Integer> catalogue = new HashSet<Integer>();  
          int count = 0;
          for (int i = 0; i < jack; i++) {
              catalogue.add(Integer.parseInt(in.readLine()));
          }
          for (int i = 0; i < jill; i++) {
              if(catalogue.contains(Integer.parseInt(in.readLine()))) count++;
          }
          System.out.println(count);
          
          nums = in.readLine().split(" ");
          jack = Integer.parseInt(nums[0]);
          jill = Integer.parseInt(nums[1]);
       }
    }
}