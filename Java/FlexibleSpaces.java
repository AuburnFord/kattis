import java.util.*;

public class FlexibleSpaces{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int width = in.nextInt();
        TreeSet<Integer> dis = new TreeSet<Integer>();
        int numPartitions = in.nextInt();
        int[] partit = new int[numPartitions];
        for (int i = 0; i < numPartitions; i++) {
           partit[i] = in.nextInt();
        }
        dis.add(width);
        for (int i = 0; i < numPartitions; i++) {
            dis.add(partit[i]);
            dis.add(width - partit[i]);
            for (int j = i+1; j < numPartitions; j++) {
                dis.add(partit[j] - partit[i]);
            }
            
        }
        for(int i : dis) {
            System.out.print(i + " ");
        }
        System.out.println();

    }
}