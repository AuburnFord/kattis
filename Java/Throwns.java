import java.util.*;

public class Throwns {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int kids = in.nextInt();
		int com = in.nextInt();
		in.nextLine();
		Stack<Integer> past = new Stack<Integer>();
		int pos = 0;
		for(int i = 0; i < com; i++) {
			String instr = in.next();
			if(instr.equals("undo")) {
				int undos = in.nextInt();
				for(int j = 0; j < undos; j++) {
					int last = past.pop() * -1;
					pos += last;
					while(pos<0) {
						pos += kids;
					}
					pos = pos%kids;
				} 
			} else {
				int next = Integer.parseInt(instr);
				pos += next;
				past.push(next);
				while(pos<0) {
					pos += kids;
				}
				pos = pos%kids;
			}
		}
		System.out.println(pos);
	}
}
