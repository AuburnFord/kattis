import java.util.*;

public class IcpcAwards{
	public static void main(String[]args) {
		Scanner in = new Scanner(System.in);
		HashSet<String> schools = new HashSet<String>();
		in.nextLine();
		while(in.hasNext() && schools.size() < 12) {
			String[] next = in.nextLine().split(" ");
			if(!schools.contains(next[0])) {
				schools.add(next[0]);
				System.out.println(next[0] + " " + next[1]);
			}
		}
	}
}
