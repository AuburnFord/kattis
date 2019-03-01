import java.util.*;

public class Freefood {
	public static void main (String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		HashSet<Integer> days = new HashSet<Integer>();
		for(int i = 0; i < n; i++) {
			int a = in.nextInt();
			int b = in.nextInt();
			for(a=a; a<=b; a++) {
				days.add(a);
			}
		}
		System.out.println(days.size());
	}
}
