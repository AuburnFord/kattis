from sys import stdin,stdout
import heapq
def dijk(grid,costs):
	r = len(grid)
	c = len(grid[0])
	dirs = [(0,1),(1,0),(-1,0),(0,-1)]
	pq = [(grid[y][0],0,y) for y in range(r)]
	for y in range(r):
		costs[y][0] = grid[y][0]
	heapq.heapify(pq)
	while pq:
		cur_cost,cur_x,cur_y = heapq.heappop(pq)
#		print(cur_x,cur_y,cur_cost)
		for n in dirs:	
			new_x = cur_x + n[1]
			new_y = cur_y + n[0]
			if 0 <= new_x < c and 0 <= new_y < r:
				if costs[new_y][new_x] == -1:	
					cost = max(cur_cost,grid[new_y][new_x])			
					costs[new_y][new_x] = cost
					heapq.heappush(pq,(cost,new_x,new_y))

def main():
	r,c = map(int, stdin.readline().split())
	grid = []
	for _ in range(r):
		grid.append([int(x) for x in stdin.readline().split()])	
	costs = [[-1]*c for x in range(r)]
	dijk(grid,costs)	
#	print(grid)
#	print(costs)
	print(min([costs[y][c-1] for y in range(r)]))


if __name__ == "__main__":
	main()
