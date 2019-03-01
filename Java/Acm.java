import java.util.*;
public class Acm {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		HashMap<String, Integer> unsolved = new HashMap<String, Integer>();
		int correct;
		int score = correct =  0;
		while(in.hasNextLine()) {
			String[] submit = in.nextLine().split(" ");
			if(submit[0].equals("-1")) break;
			if (!unsolved.containsKey(submit[1])) {
				unsolved.put(submit[1],0);	
			}
			unsolved.put(submit[1],
				unsolved.get(submit[1])+(submit[2].equals("wrong") ? 1 : 0));
			if (submit[2].equals("right")) {
				correct++;
				score+=unsolved.get(submit[1])*20+Integer.parseInt(submit[0]);	
			}
		}
		System.out.println(correct + " " + score);
	}
}
