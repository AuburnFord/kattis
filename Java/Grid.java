import java.util.Scanner;
import java.util.LinkedList;

public class Grid {

	private static int height;
	private static int width;
	
	private static int[] eval(int current, int[][] grid, int[][] dists) {
		int x = current % width;
		int y = current / width;	
		
		int travel = grid[y][x];
		int[] ret = {-1, -1, -1, -1};
		if (travel == 0)
			return ret;
		// check all 4 directions
		// right
		if (x + travel < width && dists[y][x + travel] == -1) {
			ret[0] = x + travel + y * width;
			dists[y][x+travel] = dists[y][x] + 1;
		}
		// left
		if (x - travel >= 0 && dists[y][x - travel] == -1) {
			ret[1] = x - travel + y * width;
			dists[y][x-travel] = dists[y][x] + 1;
		}
		// down
		if (y + travel < height && dists[y + travel][x] == -1) {
			ret[2] = x + (y + travel) * width;
			dists[y+travel][x] = dists[y][x] + 1;
		}
		if (y - travel >= 0 && dists[y - travel][x] == -1) {
			ret[3] = x + (y - travel) * width;
			dists[y-travel][x] = dists[y][x] + 1;
		}
		return ret;	
	}

	private static void search(int[][] grid, int[][] dists) {
		LinkedList<Integer> q = new LinkedList<Integer>();
		q.add(0);
		while (q.size() != 0) {
			int cur = q.poll();
			int[] neighbors = eval(cur, grid, dists);
			for (int neighbor : neighbors) 
				if (neighbor != -1) 
					q.add(neighbor);
		}
	}
	
	public static void main (String[] args) {
		Scanner in = new Scanner(System.in);
		// Determine size of grid
		String[] h_w = in.nextLine().split(" ");
		height = Integer.parseInt(h_w[0]); 
		width = Integer.parseInt(h_w[1]); 

		int[][] grid, dists;
		// init the arrays
		grid = new int[height][width];
		dists = new int[height][width];

		for (int y = 0; y < height; y++) {
			String line_vals = in.nextLine();
			for (int x = 0; x < width; x++) {
				dists[y][x] = -1;
				// convert char to int
				grid[y][x] = line_vals.charAt(x) - '0';
			}
		}
		// set dist to starting point as 0
		dists[0][0] = 0;
		
		search(grid, dists);
		
		System.out.println(dists[height-1][width-1]);
	}
}
