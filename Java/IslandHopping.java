import java.util.*;

public class IslandHopping {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int z = in.nextInt();
		for(int q = 0; q < z; q++) {
			int N = in.nextInt();		
			Island[] islands = new Island[N];
			for (int i = 0; i < N; i++) {
				double x = in.nextDouble();
				double y = in.nextDouble();	
				islands[i] = new Island(x,y);
			}
			
			// This is meant to be Prim's algorithm			
			double[] distances = new double[N];
			for (int i = 1; i < N; i++) {
				distances[i] = Double.MAX_VALUE;
			}
			HashSet<Integer> visited =new HashSet<Integer>();
			int currentIndex = 0;	
			int count = 1;
			double total = 0;
			while (count < N) {
				visited.add(currentIndex);
				Island currentIsland = islands[currentIndex];
				for (int i = 0; i < N; i++) {
					if (i == currentIndex) {
						continue;
					}
					Island otherIslands = islands[i];
					double newDistance = getDistance(currentIsland, otherIslands);
					if(newDistance < distances[i]) {
						distances[i] = newDistance;
					}
				}
				int nextIsland = 0;
				double bestDistance = Double.MAX_VALUE;
				for(int i = 0; i < N; i++) {
					if(visited.contains(i)) {
						continue;
					}	
					
					if (distances[i] < bestDistance) {
						bestDistance = distances[i];
						nextIsland = i;
					}
				}
				count++;
				total += Math.sqrt(bestDistance);
				currentIndex = nextIsland;
			}
			System.out.println(total);
		}
	}

	static double getDistance(Island a, Island b) {
		double dist = (a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y);
		return dist;
	}

	static class Island{
		double x;
		double y;

		Island(double a, double b) {
			x = a;
			y = b;	
		}
	}
}
