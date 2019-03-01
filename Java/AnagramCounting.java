import java.util.*;

public class AnagramCounting {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		HashMap<Character, Integer> chars = new HashMap<Character, Integer>();
		while(in.hasNextLine()) {
			chars.clear();
			String input = in.nextLine();
			for (int j = 0; j < input.length(); j++) {
				if (chars.containsKey(input.charAt(j))) {
					chars.replace(input.charAt(j), chars.get(input.charAt(j)+1));
				} else chars.put(input.charAt(j), 1);
			}
			long size = fact(chars.size());
			for (char a : chars.keySet()) {
				size /= fact(chars.get(a));
			}
			System.out.println(size);
		}
	}	

	static long fact(long f) {
		if (f == 1) return 1;
		return f * fact(f-1);
	}
}
			
