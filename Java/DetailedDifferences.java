import java.util.*;

public class DetailedDifferences {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int i = in.nextInt();
		in.nextLine();
		while(i > 0) {
			String a = in.nextLine();
			String b = in.nextLine();
			String out = a+"\n"+b+"\n";
			for(int j = 0; j < a.length(); j++) {
				if(a.charAt(j) == b.charAt(j)) out += ".";
				else out += "*";	
			}
			System.out.println(out + "\n");
			i--;	
		}		
	}
}
