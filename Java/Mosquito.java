import java.util.*;

public class Mosquito {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int m,p,l,e,r,s,n;
		while(in.hasNext()) {
			m = in.nextInt();
			p = in.nextInt();
			l = in.nextInt();
			e = in.nextInt();
			r = in.nextInt();
			s = in.nextInt();
			n = in.nextInt();
			
			for(int w = 0; w < n; w++) {
				// update number of larvae
				// number of mosquitoes * eggs per mosquito
				int larvae = l;
				l = m * e;	
				// update number of pupae
				// number of larvae / survival rate
				int pupae = p;
				p = larvae / r;
				// update number of mosquitoes
				// number of pupae / survival rate
				m = pupae / s;
			/*
			 *	Note that by changing the order of updating
			 *	we can reduce the saved data
			 *	int larvae = l;
			 *	l = m*e;
			 *	m = p/s;
			 *	p = larvae/r;
			 */
			}
			System.out.println(m);
			in.nextLine(); // clear last '/n' char thats left be nextInt()
		}
	}
}
