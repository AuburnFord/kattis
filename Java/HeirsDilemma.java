import java.util.*;

public class HeirsDilemma {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int lo = in.nextInt();
		int hi = in.nextInt();
		int count = 0;
		for(lo=lo; lo <= hi; lo++) {
			if(diff("" + lo) && div(lo)) count++;
		}			
		System.out.println(count);
	}
	
	static boolean diff(String n) {
		int[] c = new int[10];
		// the % operator would work i forgot until i got to div()
		for(int i = 0; i < n.length(); i++) {
			if(c[n.charAt(i) & 0xF] == 1) return false;
			c[n.charAt(i) & 0xF]++;
		}
		if(c[0] > 0) return false; // this performs the same action as zero()
		return true;	
	}
	
	// added this functionality in diff()
	static boolean zero(String n) {
		for(int i = 0; i < n.length(); i++) {
			if(n.charAt(i) == '0') return false;
		}
		return true;
	}
	
	static boolean div(int n) {
		HashSet<Integer> v = new HashSet<Integer>();
		int c = n;
		while(c > 0) {
			v.add(c%10);
			c = c/10;
		}
		for(int a : v) {
			if(n%a!=0) return false;
		}
		return true;
	}
}
