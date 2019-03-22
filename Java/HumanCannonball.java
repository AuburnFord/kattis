import java.util.*;

public class HumanCannonball {
	static Location[] locations;
	static Location start;
	static Location end;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);		
		start = new Location(in.nextDouble(), in.nextDouble());
		end = new Location(in.nextDouble(), in.nextDouble());
		int cannons = in.nextInt();
		locations = new Location[cannons+2];
		locations[0] = start;
		locations[locations.length-1] = end;
		for(int i = 1; i <= cannons; i++) {
			locations[i] = new Location(in.nextDouble(), in.nextDouble());
		}
	//	for(Location l : locations) {
	//		System.out.println(l.x + " " + l.y);
	//	}
		System.out.println(dijkstra());
	}

	static double calcTime(int from, int to) {
		double dist = locations[from].distance(locations[to]);
		if (from == 0) {
			return dist/5;
		} else if(dist==50) {
			return 2;
		} else {
			return Math.abs(dist-50)/5 + 2;
		} 
	}

	static double dijkstra() {
		int count = 0;
		PriorityQueue<WeightedLoc> pq = new PriorityQueue<WeightedLoc>();
		HashSet<Integer> visited = new HashSet<Integer>();	
		pq.add(new WeightedLoc(0, 0));
		while(pq.size()!=0 && count < 10) {
			WeightedLoc cur = pq.peek();
			if(cur.loc == locations.length-1) {
				break;	
			}
			if(!visited.contains(cur.loc)) {
				for(int i = 0; i < locations.length; i++) {
					if(cur.loc != i) {
						double weight = calcTime(cur.loc, i) + cur.weight;
						pq.add(new WeightedLoc(i,weight));
					}
				}	
//				System.out.println(cur.loc + " " + cur.weight);
				visited.add(cur.loc);
			}
			pq.poll();
//			count++;
		}
		return pq.peek().weight;
	}
}

class Location {
	double x;
	double y;
		
	public Location(double x, double y) {
		this.x = x;
		this.y = y;
	}
	
	public double distance(Location other) {
		return Math.sqrt((other.x-this.x)*(other.x-this.x)+(other.y-this.y)*(other.y-this.y));
	}
}

class WeightedLoc implements Comparable<WeightedLoc>{
	int loc;
	double weight;
	
	public WeightedLoc(int loc, double weight) {
		this.loc = loc;
		this.weight = weight;
	}

	public int compareTo(WeightedLoc other) {
		if(this.weight==other.weight) return 0;
		else return this.weight > other.weight ? 1 : -1;
	}	
}
