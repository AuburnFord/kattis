def union(p1, p2, graph):
	graph[find(p1, graph)] = find(p2, graph)

def find(person, graph):
	if graph[person] == person:
		return person
	else:
		graph[person] = find(graph[person], graph)
		return graph[person]	

def main():
	people, relations = [int(x) for x in input().split()]
	parents = list(range(0, people))
	values = []
	for _ in range(0, people):
		values.append(int(input()))
	for _ in range(0, relations):
		p1, p2 = [int(x) for x in input().split()]
		union(p1, p2, parents)
	group_sums = {}
	for i in range(0, people):
		if find(i,parents) not in group_sums:
			group_sums[find(i,parents)] = 0	
		group_sums[find(i,parents)] += values[i]
	flag = False
	for group in group_sums:
		if group_sums[group] != 0:
			flag = True
			break
	if not flag:
		print("POSSIBLE")
	else:
		print("IMPOSSIBLE")

if __name__ == "__main__":
	main()
