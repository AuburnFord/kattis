import java.io.*;
import java.util.*;

public class Bernie{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int visits = Integer.parseInt(br.readLine());
        HashMap<String, TreeMap> vis = new HashMap<String, TreeMap>();
        while (visits > 0) {
           String[] loc = br.readLine().split(" ");
           int a = Integer.parseInt(loc[1]);
           if (vis.containsKey(loc[0])) {
               if (vis.get(loc[0]).containsKey(a)) {
                  vis.get(loc[0]).replace(a, (int)vis.get(loc[0]).get(a) + 1);
               }
               else {
                   vis.get(loc[0]).put(a, 1);
               }
           }
           else {
               vis.put(loc[0], new TreeMap<Integer, Integer>());
               vis.get(loc[0]).put(a, 1);
           }
           visits--;
        }

        int requests = Integer.parseInt(br.readLine());
        while (requests > 0) {
            String[] req = br.readLine().split(" ");
            int y = Integer.parseInt(req[1]);
            TreeMap<Integer, Integer> x = vis.get(req[0]);
            int count = 0;
            for (int s : x.keySet()) {
               count += x.get(s);
               if (y < count) {
                   System.out.println(s); // loop up to num stored nstead of add for count
               }
            }
            requests--;
        }
    }
}