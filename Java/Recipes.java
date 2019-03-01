import java.util.*;

public class Recipes{
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int r = Integer.parseInt(in.nextLine());
		for(int i = 1; i <= r; i++) {
			System.out.println("Recipe # " + i);
			int ingredients = in.nextInt();
			double portions = in.nextDouble();
			double desired = in.nextDouble();
			double ratio = desired/portions;
			in.nextLine();
			Ing[] ings = new Ing[ingredients];
			double main = 0;
			for(int j = 0; j < ingredients; j++) {
				String name = in.next();
				double weight = Double.parseDouble(in.next());
				double percentage = Double.parseDouble(in.next());
				ings[j] = new Ing(name, weight, percentage);
				if (percentage == 100) main = weight;	
			}	
			for(int j = 0; j < ingredients; j++) {
				System.out.println(ings[j].name + " " + main*ings[j].percentage/100*ratio);
			}
			for(int j = 0; j < 40; j++) {
				System.out.print("-");
			}
			System.out.println();
		}
	}
	
	private static class Ing{
		public String name;
		public double weight;
		public double percentage;
		
		public Ing(String n, double w, double p) {
			name = n;
			weight = w;
			percentage = p;
		}
	}
}
