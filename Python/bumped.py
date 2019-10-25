import heapq
import os

def dijk(start, dists, graph):
	pq = [(0,start)]
	while len(pq) != 0:
		cur_dist, cur = heapq.heappop(pq)
		if dists[cur] != -1:
			continue
		dists[cur] = cur_dist 
		neighbors = graph[cur]
		for neighbor in neighbors:
			heapq.heappush(pq,(cur_dist+neighbors[neighbor], neighbor))
#		print(pq)
			

def main():
	all_input = os.read(0,3000000).decode("utf-8").split("\n")
	cities, roads, num_flights, start, end = [int(x) for x in all_input[0].split()]
	graph = [{} for x in range(cities)]		
	flights = [] 
	for i in all_input[1:roads+1]:
		c1, c2, dist = [int(x) for x in i.split()]
		if c2 in graph[c1]:
			if graph[c1][c2] > dist:
				graph[c1][c2] = dist
				graph[c2][c1] = dist
		else:
			graph[c1][c2] = dist
			graph[c2][c1] = dist
	from_start = [-1] * cities
	from_end = [-1] * cities
	dijk(start, from_start, graph)
	dijk(end, from_end, graph)
	cost = 0
	flag = False
	if from_start[end] == -1:
		flag = True	
	else:
		cost = from_start[end]
	for i in all_input[roads+1:-1]:
		c1, c2 = [int(x) for x in i.split()]	
		d1 = from_start[c1]
		d2 = from_end[c2]
		if (d1 != -1 and d2 != -1):
			with_flight = d1 + d2
			if flag or cost > with_flight:
				cost = with_flight
	print(cost)

if __name__ == "__main__":
	main()
