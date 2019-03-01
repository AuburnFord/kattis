import java.util.*;

public class Frosh {

	public static void main (String[] args) {
		Scanner in = new Scanner(System.in);
		int numTask = in.nextInt();
		int numQuiet = in.nextInt();
		ArrayList<Integer> task = new ArrayList<Integer>();
		ArrayList<Integer> quiet = new ArrayList<Integer>();
		for (int i = 0; i < numTask; i++) {
			task.add(in.nextInt());
		}
		for (int i = 0; i < numQuiet; i++) {
			quiet.add(in.nextInt());
		}
		Collections.sort(task);
		Collections.sort(quiet);
		int num = 0;
		int a = 0;
		int b = 0;
		while (task.size() > a && quiet.size() > b) {
			if (task.get(a) <= quiet.get(b)) {
				a++;
				num++;
			}
			b++;
		}
		System.out.println(num);
	}
}
