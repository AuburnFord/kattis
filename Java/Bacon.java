import java.util.*;

public class Bacon {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int customers = Integer.parseInt(in.nextLine());
		while (customers != 0) {
			TreeMap<String, TreeSet<String>> orders = new TreeMap<String, TreeSet<String>>(); 
			while (customers > 0) {
				String[] order = in.nextLine().split(" ");
				for(int i = 1; i < order.length; i++) {
					if(!orders.containsKey(order[i])) {
						orders.put(order[i], new TreeSet<String>());	
					}
					orders.get(order[i]).add(order[0]);
				}
				customers--;
			}
			for(String s : orders.keySet()) {
				System.out.print(s);
				TreeSet<String> curr = orders.get(s);
				for(String t : curr) {
					System.out.print(" " + t);
				}	
				System.out.println();
			}
			System.out.println();
			customers = Integer.parseInt(in.nextLine());
		}	
	}
}
