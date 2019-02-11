import java.util.*;

public class Bus{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();
        TreeSet<Integer> busNums = new TreeSet<Integer>();
        while (num > 0) {
            busNums.add(in.nextInt());
            num--;
        }
        ArrayList<Integer> groups = new ArrayList<Integer>();
        while (busNums.size() > 0) {
            if (groups.size() == 0) {
                groups.add(busNums.pollFirst());
            } else {
                int next = busNums.pollFirst();
                if (Math.abs(next - groups.get(groups.size() - 1)) <= 1) {
                    groups.add(next);
                } else {
                    if (groups.size() > 2) {
                        System.out.print(groups.get(0) + "-" + groups.get(groups.size()-1) + " ");
                    } else if (groups.size() > 1){
                        System.out.print(groups.get(0) + " " + groups.get(1) + " ");
                    } else System.out.print(groups.get(0) + " ");
                    groups.clear();
                    groups.add(next);
                }
            }
        }
        if (groups.size() > 2) {
            System.out.println(groups.get(0) + "-" + groups.get(groups.size()-1));
        } else if (groups.size() > 1){
            System.out.println(groups.get(0) + " " + groups.get(1));
        } else System.out.println(groups.get(0));
    }
}