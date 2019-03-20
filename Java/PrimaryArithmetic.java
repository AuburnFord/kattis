import java.util.*;

public class PrimaryArithmetic {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt(), b = in.nextInt();
		int carry, count;
		while(a>0||b>0) {
			carry = 0;
			count = 0;
			while(a>0||b>0) {
				if (a%10 + b%10 + carry > 9) {
					count++;
					carry = 1;
				} else carry = 0;
				a/=10;
				b/=10;
			}
			if(count == 0)
				System.out.println("No carry operation.");
			else if(count == 1)
				System.out.println("1 carry operation.");
			else
				System.out.println(count + " carry operations.");
			a = in.nextInt();
			b = in.nextInt();
		}	
	}
}
