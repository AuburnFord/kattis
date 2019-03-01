import java.util.*;

public class Simplicity{

	public static void main(String[] args) {
		long n = System.currentTimeMillis();
		Scanner in = new Scanner(System.in);
		String word = in.next();
		HashMap<Character, Integer> num = new HashMap<Character, Integer>();
		TreeMap<Integer, ArrayList> vals = new TreeMap<Integer, ArrayList>();
		for (int i = 0; i < word.length(); i++) {
			if (num.containsKey(word.charAt(i))) {
				num.replace(word.charAt(i), num.get(word.charAt(i)) + 1);
			} else {
				num.put(word.charAt(i), 1);
			}
		}
		// Instead of Treemap just iterate from 0, pulling values, with question bounds this is fast(est?)
		if (num.size() > 2) {
			for(char k : num.keySet()) {
				if (vals.containsKey(num.get(k))) {
					vals.get(num.get(k)).add(k);
				} else {
					vals.put(num.get(k), new ArrayList());
					vals.get(num.get(k)).add(k);
				}
			}
			int sum = 0;
			for (int i = 0; i < num.size() - 2; i++) {
				int l = vals.firstKey();
				if (vals.get(l).size() > 1) {
					vals.get(l).remove(0);	
				} else {
					vals.remove(l);
				}
				sum += l;
			}
			System.out.println(sum);
		} else System.out.println(0);
		System.out.println(System.currentTimeMillis() - n);	
	}
}
