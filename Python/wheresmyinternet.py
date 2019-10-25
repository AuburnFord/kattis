from sys import stdin,stdout

def find(a,parents):
	if a != parents[a]:
		parents[a] = find(parents[a],parents)
	return parents[a]

def union(a,b, parents):
	parents[find(b,parents)] = find(a,parents)

def main():
	houses,cables = map(int, stdin.readline().strip().split())	
	parents = list(range(houses))
	for x in range(cables):
		a,b = map(int, stdin.readline().strip().split()) 
		a -= 1
		b -= 1
		union(a,b, parents)
	needed = []
	root = find(0,parents)
	for x in range(1,houses):
		if find(x,parents) != root:
			needed.append(str(x+1))
	if len(needed) == 0:
		print('Connected')
	else:
		print('\n'.join(needed))
		

if __name__ == "__main__":
	main()
