import java.util.*;

public class everywhere {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int cases = Integer.parseInt(scan.nextLine());
		for (int x = 0; x < cases; x++) {
			HashSet<String> traveled = new HashSet<String>();
			int cities = Integer.parseInt(scan.nextLine());
			for (int y = 0; y < cities; y++) {
				traveled.add(scan.nextLine());
			}
			System.out.println(traveled.size());
		}
	}	
}
