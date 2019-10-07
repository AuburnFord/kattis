import heapq
def dijk(start,graph,dists,george,offset):
	pq = [(offset,start)]
	george_times = {}
	george_time = 0
	for i in range(len(george)-1):
		george_times[(george[i] if george[i] < george[i+1] else george[i+1],george[i+1] if george[i] < george[i+1] else george[i])] = (george_time, george_time+graph[george[i]][george[i+1]])
		george_time += graph[george[i]][george[i+1]]
	while len(pq) != 0:
		cur_dist, cur = heapq.heappop(pq)
		if dists[cur] != -1:
			continue
		dists[cur] = cur_dist
		neighbors = graph[cur]
		for neighbor in neighbors:
			p = (neighbor if neighbor < cur else cur, cur if neighbor < cur else neighbor)
			if p in george_times and cur_dist >= george_times[p][0] and cur_dist < george_times[p][1]:
				heapq.heappush(pq,(george_times[p][1]+neighbors[neighbor], neighbor))
			else:
				heapq.heappush(pq,(cur_dist+neighbors[neighbor], neighbor))
	

def main():
	intersections, streets = [int(x) for x in input().split()]
	start,dest,offset,gnum = [int(x) for x in input().split()]
	george = [int(x) for x in input().split()]
	graph = [{} for x in range(intersections+1)]
	for i in range(streets):
		i1,i2,cost = [int(x) for x in input().split()]
		if i1 in graph[i2]:
			if graph[i2][i1] > cost:
				graph[i2][i1] = cost
				graph[i1][i2] = cost
		else:
			graph[i2][i1] = cost
			graph[i1][i2] = cost
	dists = [-1]*(intersections+1)
	dijk(start,graph,dists,george,offset)
	print(dists[dest]-offset)

if __name__ == "__main__":
	main()

