from sys import stdin, stdout
import collections

def search(graph,reqs, start, days):
	q = [start]
	spoke = set()
	heard = set()
	heard.add(start)
	for i in range(days):
		if len(q) == 0:
			break
		nextq = []
		for p in q:
			for x in graph[p]:
				if reqs[x] == 1:
					nextq.append(x)
					heard.add(x)
				reqs[x] -= 1
				heard.add(x)
		q = nextq
	return len(heard)-1

def main():
	people, conn, days = map(int, stdin.readline().split())
	reqs = {}
	conns = {}
	for p in range(people):
		pers, skept = stdin.readline().split()
		skept = int(skept)	
		reqs[pers] = skept
		conns[pers] = list() 
	for c in range(conn):
		p1,p2 = stdin.readline().split()
		conns[p1].append(p2)
		conns[p2].append(p1)
	start = stdin.readline().rstrip()
	print(search(conns,reqs,start,days))
	
	
if __name__ == "__main__":
	main()
