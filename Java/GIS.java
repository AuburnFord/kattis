import java.util.*;

public class GIS{ // increase speed by using strbuilder?
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();
        int[] nums = new int[num];
        for (int i = 0; i < num; i++) {
            nums[i] = in.nextInt();
        }
        ArrayList<Integer> gis = new ArrayList<Integer>();
        gis.add(nums[0]);
        int max = nums[0];
        int i = 1;
        while (i < num) {
            if (max < nums[i]) {
                gis.add(nums[i]);
                max = nums[i];
            }
            i++;
        }
        System.out.println(gis.size());
        for (int j : gis) {
            System.out.print(j + " ");
        }
        System.out.println();
    }
}